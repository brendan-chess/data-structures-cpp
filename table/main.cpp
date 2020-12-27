#include "Table.h"
using namespace std;

int main(int argc, char *argv[]){
    Table t("Employee", {"First", "Last", "Age"});
    t.insert_into({"Joe", "Baker", "23"});
    t.insert_into({"Mark", "Johnson", "31"});
    t.insert_into({"Lisa", "Harold", "26"});


    Table t2 = t.select_all();
    cout << t;
}