/*
 * Author: Brendan Chess
 * Project: Final Project
 * Purpose: Implement a database that responds to SQL commands on the command
 *      line or from a batch file
 */
#ifndef DATABASE_TABLE_H
#define DATABASE_TABLE_H

#include <fstream>
#include "Map.h"
#include "MMap.h"

#include "../!includes/stack/Stack.h"
#include "../!includes/queue/Queue.h"

typedef vector<string> vector_str;

static int _serial = 0;

class Record {
public:
    Record() {
        for(int i = 0; i < MAX_ROWS; i++){
            record[i][0] = NULL;
        }
        recno = -1;
        _num_of_fields = MAX_ROWS;
    }

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

        for(int i = 0; i < _num_of_fields; i++){
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

    char record[MAX_ROWS][MAX_COLS];
};

long Record::write(fstream &outs){
    //write to the end of the file.
    outs.seekg(0, outs.end);
    long pos = outs.tellp();

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
        outs << setw(20) << r.record[i];
    }

    return outs;
}

//--------------------------------------------------------------------------//

class Table {
public:
    Table(const string &name, const vector_str &field_names);
    Table(const string &name);

    void insert_into(const vector_str &data);

    Table select(const vector_str &fields, const vector_str &conditions);

    void delete_where(const vector_str &conditions);

    void print_table();
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

    void open_fileW(fstream &f, const char filename[]) throw(char*); //creates a new file for input
    void open_fileRW(fstream &f, const char filename[]) throw(char*); //opens an existing file for input/output

    bool file_exists(const char filename[]);

    void reindex(); //construct _field_map and _indices when we open an existing file

    Table select_fields(const vector_str &fields, const string &name);
    Table select_cond(const vector_str &conditions, const vector_str &fields, const string &name);

    vector_str shunting_yard(const vector_str &conditions);
    vector<long> rpn(const vector_str &postfix);
    bool valid_expression(const string &value, const string &field);
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

Table::Table(const string &name) {
    _name = name;
    _file_name = name + ".bin";
    open_fileRW(_f, _file_name.c_str());

    Record fields;
    fields.read(_f, 0);

    _field_names = fields.get_record();

    vector_str field_names_trimmed;

    for (int i = 0; i < _field_names.size(); ++i) {
        if(!_field_names[i].empty())
            field_names_trimmed.push_back(_field_names[i]);
    }

    _field_names = field_names_trimmed;

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
    Record r(_field_names);
    int recno = 1;
    r.read(_f, recno);
    int rec_size = r.get_record().size();

    //read the entire file
    while(!_f.eof()){
        if(!r.get_record()[0].empty()){ //do not add deleted (empty) records
            //get data in each field at the current record
            for (int i = 0; i < rec_size; ++i) {
                string data = r.get_record()[i];
                string field = _field_names[i];
                int index = _field_map[field];

                _indices[index].insert(data, recno);
            }
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
        if(recno > 0)
            cout << setw(4) << recno - 1;
        else
            cout << setw(4) << "";
        recno++;
        cout << r << endl;
        if(recno == 1) cout << endl;
        r.read(_f, recno);
    }

    cout << "Number of records: " << recno - 1 << "\n\n";

    _f.close();
}

Table Table::select(const vector_str &fields, const vector_str &conditions){
    _serial++;
    string name = "_temp_" + _name + to_string(_serial);

    vector_str sub_fields;

    if(fields[0] == "*"){
        sub_fields = _field_names;
    } else
        sub_fields = fields;

    open_fileRW(_f, _file_name.c_str());

    if(conditions.empty()){
        return select_fields(sub_fields, name);
    } else {
        return select_cond(conditions, sub_fields, name);
    }
}

Table Table::select_fields(const vector_str &fields, const string &name) {
    //vector contains only values from the requested fields in the entire record
    vector_str filtered_record;
    Table sub_table(name, fields);
    Record r(_field_names);
    int recno = 1; //start at 1 because 0 is the field titles
    r.read(_f, recno);

    while(!_f.eof()){
        if(!r.get_record()[0].empty()){ //do not read deleted (empty) records
            //grab the value from each requested field,
            //insert into the filtered version of the record
            for (int i = 0; i < fields.size(); ++i) {
                filtered_record.push_back(r.get_record()[_field_map[fields[i]]]);
            }

            sub_table.insert_into(filtered_record); //insert the filtered record into the new subtable
        }

        recno++;
        r.read(_f, recno);
        filtered_record.clear();
    }

    _f.close();

    return sub_table;
}

Table Table::select_cond(const vector_str &conditions, const vector_str &fields, const string &name) {
    vector_str postfix = shunting_yard(conditions);
    vector<long> recnos = rpn(postfix);

    vector_str filtered_record;
    Table sub_table(name, fields);
    Record r(_field_names);

    for (int i = 0; i < recnos.size(); ++i) {
        r.read(_f, recnos[i]);

        for (int j = 0; j < fields.size(); ++j) {
            filtered_record.push_back(r.get_record()[_field_map[fields[j]]]);
        }

        sub_table.insert_into(filtered_record);

        filtered_record.clear();
    }

    _f.close();

    return sub_table;
}

vector_str Table::shunting_yard(const vector_str &conditions) {
    vector_str postfix;

    Queue<string> output_queue;
    Stack<string> operator_stack;

    Map<string, int> operator_map;

    operator_map.insert("=", 1);
    operator_map.insert(">", 1);
    operator_map.insert("<", 1);
    operator_map.insert("<=", 1);
    operator_map.insert(">=", 1);
    operator_map.insert("and", 2);
    operator_map.insert("or", 3);
    operator_map.insert("(", 1);
    operator_map.insert(")", 1);


    for (int i = 0; i < conditions.size(); ++i) {
        string token = conditions[i];
        if(operator_map.contains(token)){
            if(token == ")"){
                while(operator_stack.top() != "("){
                    string top = operator_stack.pop();
                    output_queue.push(top);
                }
                operator_stack.pop();
            } else {
                while(!operator_stack.empty() && operator_map[operator_stack.top()] < operator_map[token] && operator_stack.top() != "("){
                    string top = operator_stack.pop();
                    output_queue.push(top);
                }
                operator_stack.push(token);
            }
        } else {
            output_queue.push(token);
        }
    }

    while(!output_queue.empty()) postfix.push_back(output_queue.pop());
    while(!operator_stack.empty()) postfix.push_back(operator_stack.pop());

    return postfix;
}

vector<long> Table::rpn(const vector_str &postfix) {
    Stack<string> token_stack;
    Stack<vector<long>> recno_stack;

    Map<string, int> operator_map;

    operator_map.insert("=", 1);
    operator_map.insert(">", 1);
    operator_map.insert("<", 1);
    operator_map.insert("<=", 1);
    operator_map.insert(">=", 1);
    operator_map.insert("and", 2);
    operator_map.insert("or", 3);
    operator_map.insert("(", 1);
    operator_map.insert(")", 1);

    for (int i = 0; i < postfix.size(); ++i) {
        string token = postfix[i];
        if(operator_map.contains(token)){
            //get the vector<long> for this condition
            //push that to recno_stack

            if(token == "and"){
                vector<long> intersection;
                vector<long> rec1 = recno_stack.pop();
                vector<long> rec2 = recno_stack.pop();

                sort(rec1.begin(), rec1.end());
                sort(rec2.begin(), rec2.end());

                set_intersection(rec1.begin(), rec1.end(), rec2.begin(), rec2.end(), back_inserter(intersection));

                recno_stack.push(intersection);
            }



            if(token == "or"){
                vector<long> un;
                vector<long> rec1 = recno_stack.pop();
                vector<long> rec2 = recno_stack.pop();

                sort(rec1.begin(), rec1.end());
                sort(rec2.begin(), rec2.end());

                set_union(rec1.begin(), rec1.end(), rec2.begin(), rec2.end(), back_inserter(un));

                recno_stack.push(un);
            }



            if(token == "="){
                string value = token_stack.pop();
                string field = token_stack.pop();

                if(valid_expression(value, field)) recno_stack.push(_indices[_field_map[field]][value]);
                else recno_stack.push(vector<long>());
            }



            if(token == ">"){
                string value = token_stack.pop();
                string field = token_stack.pop();

                if(valid_expression(value, field)){
                    MMap<string, long> range = _indices[_field_map[field]].upper_bound(value); //get mmap consisting of upper bound only
                    if(!range.empty()){
                        MMap<string, long>::Iterator range_iter(range.begin()); //iterator used to read every node in the upper bound
                        vector<long> range_recnos; //contains all record numbers from the upper bound

                        while(!range_iter.is_null()){ //iterate over upper bound mmap
                            int range_iter_size = (*(range_iter)).value_list.size(); //how many recnos are in this node (mpair)
                            for (int j = 0; j < range_iter_size; ++j) {
                                range_recnos.push_back((*(range_iter)).value_list[j]); //add each recno from this node
                            }
                            ++range_iter; //move onto the next node in the upper bound
                        }
                        recno_stack.push(range_recnos);
                    } else {
                        recno_stack.push(vector<long>());
                    }
                } else {
                    recno_stack.push(vector<long>());
                }
            }



            if(token == "<"){
                string value = token_stack.pop();
                string field = token_stack.pop();

                if(valid_expression(value, field)){
                    MMap<string, long> range = _indices[_field_map[field]].lower_bound(value); //get mmap consisting of lower bound only
                    if(!range.empty()){
                        MMap<string, long>::Iterator range_iter(range.begin()); //iterator used to read every node in the lower bound
                        vector<long> range_recnos; //contains all record numbers from the upper bound

                        while(!range_iter.is_null()){ //iterate over lower bound mmap
                            int range_iter_size = (*(range_iter)).value_list.size(); //how many recnos are in this node (mpair)
                            for (int j = 0; j < range_iter_size; ++j) {
                                range_recnos.push_back((*(range_iter)).value_list[j]); //add each recno from this node
                            }
                            ++range_iter; //move onto the next node in the lower bound
                        }
                        recno_stack.push(range_recnos);
                    } else {
                        recno_stack.push(vector<long>());
                    }
                } else {
                    recno_stack.push(vector<long>());
                }
            }



            if(token == ">="){
                string value = token_stack.pop();
                string field = token_stack.pop();

                if(valid_expression(value, field)){
                    vector<long> recnos; //contains all resulting record numbers
                    //get the = records
                    vector<long> equal_recnos = _indices[_field_map[field]][value];
                    for (long equal_recno : equal_recnos) {
                        recnos.push_back(equal_recno);
                    }

                    MMap<string, long> ub_map = _indices[_field_map[field]].upper_bound(value); //get mmap consisting of upper bound only
                    if(!ub_map.empty()){
                        MMap<string, long>::Iterator ub_iter(ub_map.begin()); //iterator used to read every node in the upper bound

                        //get the > records
                        while(!ub_iter.is_null()){ //iterate over upper bound mmap
                            int ub_iter_size = (*(ub_iter)).value_list.size(); //how many recnos are in this node (mpair)
                            for (int j = 0; j < ub_iter_size; ++j) {
                                recnos.push_back((*(ub_iter)).value_list[j]); //add each recno from this node
                            }
                            ++ub_iter; //move onto the next node in the upper bound
                        }
                    }

                    recno_stack.push(recnos);
                } else {
                    recno_stack.push(vector<long>());
                }
            }



            if(token == "<="){
                string value = token_stack.pop();
                string field = token_stack.pop();

                if(valid_expression(value, field)){
                    vector<long> recnos; //contains all record numbers
                    //get the = records
                    vector<long> equal_recnos = _indices[_field_map[field]][value];
                    for (long equal_recno : equal_recnos) {
                        recnos.push_back(equal_recno);
                    }

                    MMap<string, long> lb_map = _indices[_field_map[field]].lower_bound(value); //get mmap consisting of lower bound only
                    if(!lb_map.empty()){
                        MMap<string, long>::Iterator lb_iter(lb_map.begin()); //iterator used to read every node in the lower bound

                        //get the < records
                        while(!lb_iter.is_null()){ //iterate over lower bound mmap
                            int lb_iter_size = (*(lb_iter)).value_list.size(); //how many recnos are in this node (mpair)
                            for (int j = 0; j < lb_iter_size; ++j) {
                                recnos.push_back((*(lb_iter)).value_list[j]); //add each recno from this node
                            }
                            ++lb_iter; //move onto the next node in the lower bound
                        }
                    }

                    recno_stack.push(recnos);
                } else {
                    recno_stack.push(vector<long>());
                }
            }



        } else {
            token_stack.push(token);
        }
    }

    return recno_stack.top();
}

bool Table::valid_expression(const string &value, const string &field) {
    if(_field_map.contains(field)){
        if(_indices[_field_map[field]].contains(value)){
            return true;
        }
    }
    return false;
}

void Table::delete_where(const vector_str &conditions) {
    vector_str postfix = shunting_yard(conditions);
    vector<long> recnos = rpn(postfix);

    open_fileRW(_f, _file_name.c_str());
    Record r;
    char record[20][50];

    for (long rec: recnos) {
        long pos = rec * sizeof(record);
        _f.seekg(pos, ios_base::beg);
        _f.write(&r.get_record()[0][0], sizeof(record));
    }

    _f.close();
}


#endif //DATABASE_TABLE_H
