/*
 * Author: Brendan Chess
 * Project: Heap Class
 * Purpose: Implement a class that stores data in a heap structure
 * Notes: None
 */
#include <iostream>
#include "heap.h"

void demo(){
    Heap<int> h;
    char input;
    int insert_me;
    srand(time(0));

    while(input != 'x'){
        cout << "[r]andom [i]nsert [p]op e[x]it: ";
        cin >> input;

        switch (input){
            case 'r':
                insert_me = rand() % 100 + 1;
                cout << "insert: " << insert_me << endl;
                h.insert(insert_me);
                break;
            case 'i':
                cout << "insert: ";
                cin >> insert_me;
                h.insert(insert_me);
                break;
            case 'p':
                cout << "popped: " << h.pop() << endl;
                break;
        }

        cout << h << endl;
    }
}

int main() {
    demo();
}
