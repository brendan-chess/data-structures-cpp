/*
 * Author: Brendan Chess
 * Project: Binary Search Tree Class
 * Purpose: Use functions that perform operations on binary search trees to
 *      implement a binary search tree class
 * Notes: None
 */
#include <iostream>
#include "BST.h"

void demo(){
    BST<int> bst;
    srand(time(0));
    char selection;

    while (selection != 'x'){
        cout << "[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it: ";
        cin >> selection;

        switch (selection){
            case 'r':
                int random;
                random = rand() % 100;
                bst.insert(random);
                cout << "Inserting random number: " << random << endl;
                break;
            case 'i':
                int insert;
                cout << "Insert: ";
                cin >> insert;
                bst.insert(insert);
                break;
            case 'c':
                bst.clear();
                cout << "Tree cleared" << endl;
                break;
            case 's':
                int search;
                cout << "Search for: ";
                cin >> search;
                tree_node<int>* found;
                if(bst.search(search, found)){
                    cout << "Node found: " << "|" << found->_item << "|" << endl;
                } else {
                    cout << "Node not found" << endl;
                }
                break;
            case 'e':
                int erase;
                cout << "Erase: ";
                cin >> erase;
                bst.erase(erase);
                break;
        }

        cout << bst << endl;
        cout << "======================" << endl;
    }

}

int main() {
    demo();
}
