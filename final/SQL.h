/*
 * Author: Brendan Chess
 * Project: Final Project
 * Purpose: Implement a database that responds to SQL commands on the command
 *      line or from a batch file
 */
#ifndef DATABASE_SQL_H
#define DATABASE_SQL_H

#include "Parser.h"
#include "Table.h"

class SQL{
public:
    void run();
};

void SQL::run() {
    string query;

    while(true){
        cout << "> ";

        getline(cin, query);

        if(query == "exit") break;

        Parser p(&query[0]);

        if(p.is_valid()){
            MMap<string, string> ptree = p.ptree();

            if(ptree["command"][0] == "select"){
                string table_name = ptree["table"][0];

                Table t(table_name);

                cout << t.select(ptree["fields"], ptree["conditions"]);

            } else if(ptree["command"][0] == "insert"){
                string table_name = ptree["table"][0];

                Table t(table_name);

                t.insert_into(ptree["data"]);

            } else if(ptree["command"][0] == "create" || ptree["command"][0] == "make"){
                string table_name = ptree["table"][0];

                vector_str field_names = ptree["fields"];

                Table t(table_name, field_names);

            } else if(ptree["command"][0] == "batch"){
                string file_name = ptree["data"][0];
                string batch_query;
                int line_no = 1;
                int query_no = 0;
                fstream f;
                f.open(file_name);
                while(getline(f, batch_query)){

                    if(!batch_query.empty() && batch_query[0] != '/'){ //dont parse empty lines and comments
                        cout << "[" << query_no << "] " << batch_query << endl;
                        Parser batch_p(&batch_query[0]);

                        if(batch_p.is_valid()){
                            MMap<string, string> batch_ptree = batch_p.ptree();

                            if(batch_ptree["command"][0] == "select"){
                                string table_name = batch_ptree["table"][0];
                                Table t(table_name);
                                cout << t.select(batch_ptree["fields"], batch_ptree["conditions"]);
                            } else if(batch_ptree["command"][0] == "insert"){
                                string table_name = batch_ptree["table"][0];
                                Table t(table_name);
                                t.insert_into(batch_ptree["data"]);
                            } else if(batch_ptree["command"][0] == "create" || batch_ptree["command"][0] == "make"){
                                string table_name = batch_ptree["table"][0];
                                vector_str field_names = batch_ptree["fields"];
                                Table t(table_name, field_names);
                            }

                            query_no++;
                        } else {
                            cout << "Invalid query on line " << line_no << ": " << batch_query << endl;
                        }

                        line_no++;
                    } else {
                        cout << batch_query << endl;
                    }


                }

                f.close();
            } else if(ptree["command"][0] == "drop"){

                string file_name = ptree["table"][0] + ".bin";
                remove(file_name.c_str());

            } else if(ptree["command"][0] == "delete"){
                string table_name = ptree["table"][0];
                Table t(table_name);
                t.delete_where(ptree["conditions"]);

            }
        } else {
            cout << "Invalid query: " << query << endl;
        }
    }
}


#endif //DATABASE_SQL_H
