/*
 * Author: Brendan Chess
 * Project: Hash Tables
 * Purpose: Implement an open hash table class and a chained hash table class
 *      along with demo functions
 * Notes: Interactive demo works best with table size of 17, and random demo
 *      works best with table size of 811
 */
#include <iostream>
#include "open_hash.h"
#include "chained_hash.h"
#include "record.h"

template <typename table>
void test_hash_table_interactive(table &hash, string table_type){
    cout << "Using " << table_type << endl;

    char input;

    while (input != 'x'){
        cout << "[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : ";
        cin >> input;

        switch (input){

            case 's':
                cout << "Table Size: " << hash.size() << " records" << endl;
                break;

            case 'i': {
                int key;
                double value;

                cout << "Key: ";
                cin >> key;
                cout << "Value: ";
                cin >> value;

                record i(key, value);
                hash.insert(i);
                cout << "Inserted " << i << endl;
                break;
            }

            case 'r': {
                record r(rand() % 10000, rand() % 10000);
                hash.insert(r);
                cout << "Inserted " << r << endl;
                break;
            }

            case 'd': {
                int key;

                cout << "Key: ";
                cin >> key;

                bool success = hash.remove(key);

                if(success) cout << "Deleted Key " << key << endl;
                else cout << "Key " << key << " not found" << endl;
                break;
            }

            case 'f': {
                int key;

                cout << "Key: ";
                cin >> key;

                bool found;
                record r;
                hash.find(key, found, r);

                if(found) cout << "Found record: " << r << endl;
                else cout << "Record not found" << endl;

                break;
            }

            case '?': {
                int key;

                cout << "Key: ";
                cin >> key;

                if(hash.is_present(key)) cout << "Key " << key << " exists" << endl;
                else cout << "Key " << key << " does not exist" << endl;
                break;
            }

            case 'x':
                cout << "Final Table:" << endl;
                break;
        }

        cout << hash << endl;
    }

}

template <typename table>
void test_hash_table_random(table &hash, int num_records, string table_type){
    cout << "Using " << table_type << endl;
    cout << "# of Records: " << num_records << endl;

    record entries[num_records];

    for (int i = 0; i < num_records; ++i) {
        entries[i] = record(rand() % 10000, rand() % 10000);
        hash.insert(entries[i]);
    }

    int found = 0, not_found = 0;
    for (int j = 0; j < num_records/2; ++j) {
        if(hash.is_present(entries[rand() % num_records]._key)) found++;
        else not_found++;
    }

    cout << "Searching for " << num_records/2 << " existing keys..." << endl;
    cout << "Found: " << found << endl;
    cout << "Not Found: " << not_found << endl;

    found = 0;
    not_found = 0;
    int k = 0;
    while(k < num_records/2){
        int key =  rand() % 10000;
        int unique = true;
        for (int i = 0; i < num_records; ++i) {
            if(entries[i]._key == key) {
                unique = false;
                break;
            }
        }
        if(unique){
            if(hash.is_present(key)) found++;
            else not_found++;
            k++;
        }
    }

    cout << "Searching for " << num_records/2 << " non-existing keys..." << endl;
    cout << "Found: " << found << endl;
    cout << "Not Found: " << not_found << endl;
    cout << "- - - End of random test - - -" << endl;
}

int main() {
    srand(time(0));

    const bool INTERACTIVE_OPEN = false;
    const bool INTERACTIVE_CHAINED = false;
    const bool RANDOM_OPEN = false;
    const bool RANDOM_CHAINED = false;

    open_hash<record> open;
    chained_hash<record> chained;

    if(INTERACTIVE_OPEN){
        test_hash_table_interactive(open, "open_hash<record>");
    }

    if(INTERACTIVE_CHAINED){
        test_hash_table_interactive(chained, "chained_hash<record>");
    }

    if(RANDOM_OPEN){
        test_hash_table_random(open, 500, "open_hash<record>");
    }

    if(RANDOM_CHAINED){
        test_hash_table_random(chained, 2500, "chained_hash<record>");
    }

}