#ifndef TABLE_TABLE_H
#define TABLE_TABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "../bplustree/Map.h";
#include "../bplustree/MMap.h";

using namespace std;

typedef vector<string> vector_str;

static int _serial = 0;

class Record {
public:
    Record() {
        for(int i = 0; i < MAX_ROWS; i++){
            record[i][0] = NULL;
        }
        recno = -1;
        _num_of_fields = 0;
    }

//    Record(char str[]){
//        strcpy(record, str);
//    }

    Record(const vector_str &v){
        for(int i = 0; i < MAX_ROWS; i++){
            record[i][0] = NULL;
        }
        for (int i = 0; i < v.size(); i++){
            strcpy(record[i], v[i].c_str());
        }
        _num_of_fields = v.size();
    }

    vector_str get_record(){
        vector_str v;

        for(int i = 0; i < MAX_ROWS; i++){
            v.push_back(string(record[i]));
        }

        return v;
    }

    long write(fstream &outs);
    long read(fstream &ins, long recno);

    friend ostream& operator <<(ostream &outs, const Record &r);
private:
    static const int MAX_ROWS = 20;
    static const int MAX_COLS = 50;

    int recno;
    int _num_of_fields;

    // is it supposed to be cols, rows instead?
    char record[MAX_ROWS][MAX_COLS];
};

long Record::write(fstream &outs){
    //write to the end of the file.
    outs.seekg(0, outs.end);
    long pos = outs.tellp();

    //outs.write(&record[0], sizeof(record));
    outs.write(&record[0][0], sizeof(record));

    return pos / sizeof(record);
}

long Record::read(fstream &ins, long recno){
    long pos= recno * sizeof(record);
    ins.seekg(pos, ios_base::beg);

    ins.read(&record[0][0], sizeof(record));

    return ins.gcount();
}

ostream& operator <<(ostream &outs, const Record &r){
    for (int i = 0; i < r._num_of_fields; i++){
        outs << setw(10) << r.record[i] << "|";
    }

    return outs;
}

//--------------------------------------------------------------------------//

class Table {
public:
    Table(const string &name, const vector_str &field_names);
    Table(const string &name);

    void insert_into(const vector_str &data);

    Table select_all();
    Table select_cond(const vector_str &conditions);
    Table select(const vector_str &fields);

    void print_table();
    //should really be const Table &t
    friend ostream& operator <<(ostream &outs, Table t){
        t.print_table();
        return outs;
    }
private:
    string _name;
    string _file_name;
    vector_str _field_names;
    fstream _f;
    Map<string, int> _field_map; //which index is any given field at in _indices
    vector<MMap<string, long>> _indices; //one MMAP for each field, each contains MPairs of <record_value, file_location>
    //int _record_count;

    void open_fileW(fstream &f, const char filename[]) throw(char*); //creates a new file for input
    void open_fileRW(fstream &f, const char filename[]) throw(char*); //opens an existing file for input/output

    bool file_exists(const char filename[]);

    void reindex(); //construct _field_map and _indices when we open an existing file
};

Table::Table(const string &name, const vector_str &field_names) {
    _name = name;
    _field_names = field_names;
    _file_name = name + ".bin";
    open_fileW(_f, _file_name.c_str()); //creates a new file

    Record fields(field_names);
    fields.write(_f); //write field names to the first line of the file

    _f.close();

    for (int i = 0; i < _field_names.size(); ++i) {
        _field_map.insert(_field_names[i], i);
    }

    for (int j = 0; j < _field_names.size(); ++j) {
        _indices.push_back(MMap<string, long>());
    }

    //_record_count = 0;
}

void Table::open_fileW(fstream &f, const char filename[]) throw(char*) {
    f.open(filename,fstream::out|fstream::binary);
    if(f.fail()){
        cout << "Failed to open file: " << filename << endl;
        throw("Failed to open file");
    }
}

void Table::insert_into(const vector_str &data) {
    open_fileRW(_f, _file_name.c_str());
    Record r(data);
    long pos = r.write(_f);
    _f.close();

    for (int i = 0; i < _field_names.size(); ++i) {
        _indices[_field_map[_field_names[i]]].insert(data[i], pos);
    }

    //_record_count++;
}

Table Table::select_all() {
    _serial++;

    string name = _name + to_string(_serial);
    Table sub_table(name, _field_names);

    Record r(_field_names);
    open_fileRW(_f, _file_name.c_str());

    int recno = 1;
    r.read(_f, recno);

    while(!_f.eof()){
        sub_table.insert_into(r.get_record());
        recno++;
        r.read(_f, recno);
    }

    _f.close();

    return sub_table;
}

void Table::open_fileRW(fstream &f, const char filename[]) throw(char*) {
    const bool debug = false;

    if(!file_exists(filename)){
        f.open(filename, fstream::out|fstream::binary);
        if(f.fail()){
            cout << "file open (RW) failed: with out|"<<filename<<"]"<<endl;
            throw("file RW failed  ");
        } else {
            if (debug) cout<<"open_fileRW: file created successfully: "<<filename<<endl;
        }
    } else {
        f.open(filename, fstream::in|fstream::out|fstream::binary);
        if(f.fail()){
            cout<<"file open (RW) failed. ["<<filename<<"]"<<endl;
            throw("file failed to open.");
        }
    }

}

bool Table::file_exists(const char filename[]) {
    const bool debug = false;

    fstream ff;
    ff.open(filename, fstream::in|fstream::binary);

    if (ff.fail()){
        if (debug) cout<<"file_exists(): File does NOT exist: "<<filename<<endl;
        return false;
    }

    if (debug) cout<<"file_exists(): File DOES exist: "<<filename<<endl;

    ff.close();

    return true;
}

Table Table::select_cond(const vector_str &conditions) {
    open_fileRW(_f, _file_name.c_str());

    long pos;
    Record r(_field_names);

    _serial++;
    string name = _name + to_string(_serial);
    Table sub_table(name, _field_names);

    for (int i = 0; i < conditions.size(); ++i) {
        if(conditions[i] == "="){
            string field = conditions[i - 1];
            string value = conditions[i + 1];
            int num_records = _indices[_field_map[field]][value].size();
            for (int j = 0; j < num_records; ++j) {
                pos = _indices[_field_map[field]][value][j];
                r.read(_f, pos);
                sub_table.insert_into(r.get_record());
            }
        }
    }

    _f.close();

    return sub_table;
}

Table::Table(const string &name) {
    _name = name;
    _file_name = name + ".bin";
    open_fileRW(_f, _file_name.c_str());

    //put # of fields in file? or else _field_names.size() is MAX_ROWS
    Record fields;
    fields.read(_f, 0);
    _field_names = fields.get_record();

    reindex();

    _f.close();
}

void Table::reindex() {
    //build _field_map
    for (int i = 0; i < _field_names.size(); ++i) {
        _field_map.insert(_field_names[i], i);
    }

    //build indices
    for (int j = 0; j < _field_names.size(); ++j) {
        _indices.push_back(MMap<string, long>());
    }

    //populate _indices by reading every record in the file (except 0, which has the field names)
    Record r;
    int recno = 1;
    r.read(_f, recno);
    int rec_size = r.get_record().size();

    //read the entire file
    while(!_f.eof()){
        //get data in each field at the current record
        for (int i = 0; i < rec_size; ++i) {
            string data = r.get_record()[i];
            string field = _field_names[i];
            int index = _field_map[field];

            _indices[index].insert(data, recno);
        }

        //move onto the next record in the file
        recno++;
        r.read(_f, recno);
    }
}

void Table::print_table() {
    cout << _name << endl;

    Record r(_field_names);
    open_fileRW(_f, _file_name.c_str());

    int recno = 0;
    r.read(_f, recno);
    while (!_f.eof()){
        recno++;
        cout << r << endl;
        r.read(_f, recno);
    }

    _f.close();
}

Table Table::select(const vector_str &fields){
    if(fields[0] == "*") return select_all();

    //create new subtable to return
    _serial++;
    string name = _name + to_string(_serial);
    Table sub_table(name, fields);
    Record r(fields);
    open_fileRW(_f, _file_name.c_str());

    //vector contains only values from the requested fields in the entire record
    vector_str filtered_record;

    int recno = 1; //start at 1 because 0 is the field titles
    r.read(_f, recno);

    while(!_f.eof()){
        //grab the value from each requested field,
        //insert into the filtered version of the record
        for (int i = 0; i < fields.size(); ++i) {
            filtered_record.push_back(r.get_record()[_field_map[fields[i]]]);
        }

        sub_table.insert_into(filtered_record); //insert the filtered record into the new subtable
        recno++;
        r.read(_f, recno);
        filtered_record.clear();
    }

    _f.close();

    return sub_table;
}


#endif //TABLE_TABLE_H
