/*
 * Author: Brendan Chess
 * Project: BTree progress 2
 * Purpose: Implement remove in BTree and create a Map and MultiMap class
 *      based on BTree
 */
#include <iostream>
#include "Map.h"
#include "MMap.h"
using namespace std;

void map_demo(){
    Map<int, char> m;
    cout << m << endl;

    cout << "Inserting..." << endl;
    m.insert(1, 'a');
    m.insert(2, 'b');
    m.insert(3, 'c');
    m.insert(4, 'd');
    m.insert(5, 'e');
    cout << m << endl;

    cout << "Size: " << m.size() << endl;
    cout << "Empty: " << m.empty() << endl;

    cout << "Overwriting: m[1] = 'r'" << endl;
    m[1] = 'r';
    cout << m << endl;

    cout << "Erasing some..." << endl;
    m.erase(3);
    m.erase(2);
    m.erase(5);
    cout << m << endl;

    cout << "m[1] = " << m[1] << endl;
    cout << "m[3] = " << m[3] << endl;
    cout << m << endl;

    cout << "m.get(2) = " << m.get(2) << endl;
    cout << m << endl;

    cout << "m.at(4) = " << m.at(4) << endl;
    cout << "m.at(5) = " << m.at(5) << endl;
    cout << m << endl;

    cout << "m.contains(2) = " << m.contains(2) << endl;
    cout << "m.contains(7) = " << m.contains(7) << endl << endl;

    cout << "Clearing..." << endl;
    m.clear();
    cout << m << endl;

    cout << "Size: " << m.size() << endl;
    cout << "Empty: " << m.empty() << endl;
}

int main() {
    map_demo();
}
