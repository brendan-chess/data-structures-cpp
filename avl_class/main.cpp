/*
 * Author: Brendan Chess
 * Project: AVL Tree Class
 * Purpose: Implement a binary search tree that is always balanced
 * Notes: None
 */
#include <iostream>
#include "AVL.h"

void demo(){
    AVL<int> avl;
    srand(time(0));
    char selection;

    while (selection != 'x'){
        cout << "[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it: ";
        cin >> selection;

        switch (selection){
            case 'r':
                int random;
                random = rand() % 100;
                avl.insert(random);
                cout << "Inserting random number: " << random << endl;
                break;
            case 'i':
                int insert;
                cout << "Insert: ";
                cin >> insert;
                avl.insert(insert);
                break;
            case 'c':
                avl.clear();
                cout << "Tree cleared" << endl;
                break;
            case 's':
                int search;
                cout << "Search for: ";
                cin >> search;
                tree_node<int>* found;
                if(avl.search(search, found)){
                    cout << "Node found: " << "|" << found->_item << "|" << endl;
                } else {
                    cout << "Node not found" << endl;
                }
                break;
            case 'e':
                int erase;
                cout << "Erase: ";
                cin >> erase;
                avl.erase(erase);
                break;
        }

        cout << avl << endl;
        cout << "======================" << endl;
    }
}

int main() {
    demo();
}
