#include <iostream>
#include "Parser.h"
#include "../table/Table.h"

int main() {
    Table st("student", {"first", "last", "major"});
    st.insert_into({"John", "Nelson", "Humanitites"});
    st.insert_into({"Maria", "Allen", "Art"});
    st.insert_into({"Robert", "Harrison", "Computer Science"});
    st.insert_into({"Brian", "Harrison", "Math"});



    Parser p("select * from student where last = Harrison");
    MMap<string, string> ptree = p.ptree();
    cout << ptree;
    if(ptree["command"][0] == "select"){
        string table_name = ptree["table"][0];
        Table t(table_name);
        cout << t.select_cond(ptree["conditions"]);
    }


//    Parser p("select * from student where last = Allen");
//    MMap<string, string> ptree = p.ptree();
//    if(ptree["command"][0] == "select"){
//        string table_name = ptree["table"][0];
//        Table t(table_name);
//        cout << t.select(ptree["fields"]);
//    }
}
