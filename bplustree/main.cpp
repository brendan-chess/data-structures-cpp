/*
 * Author: Brendan Chess
 * Project: B+Tree Map & MultiMap
 * Purpose: Implement Map and MultiMap classes based on a B+Tree
 * Notes: Depends on B+Tree class and array util functions
 */
#include <iostream>
#include "BPlusTree.h"
#include "Map.h"
#include "MMap.h"

void test_bpt();
void test_bpt_big3();
void test_map();
void test_mmap();

int main() {
    srand(time(0));
    //test_bpt();
    //test_bpt_big3();
    //test_map();
    test_mmap();
}

void test_bpt(){
    BPlusTree<int> bpt;
    int size = 50;
    int data[size];

    cout << "Inserting " << size << " random integers:" << endl;
    for (int i = 0; i < size; ++i) {
        int random_int = rand() % 1000;
        data[i] = random_int;
        bpt.insert(random_int);
    }

    cout << bpt << endl;

    cout << "========================================================" << endl;

    cout << "Tree is valid: ";
    cout << bpt.is_valid() << endl;

    cout << "========================================================" << endl;

    cout << "Printing leaves using Iterator:" << endl;
    for(BPlusTree<int>::Iterator it = bpt.begin();
        it!= bpt.end(); ++it){
        cout << "[" << *it << "]" << endl;
    }

    cout << "========================================================" << endl;

    cout << "Find 10 values that are in the tree:" << endl;
    for (int j = 0; j < 10; ++j) {
        int random_element = data[rand() % (size - 1)];
        BPlusTree<int>::Iterator it = bpt.find(random_element);
        if(it.is_null()) cout << random_element << " was not found" << endl;
        else cout << random_element << " was found" << endl;
    }

    cout << "========================================================" << endl;

    cout << "Find 10 values that are not in the tree:" << endl;
    for (int j = 0; j < 10; ++j) {
        int random_int = 1000 + rand() % 1000;
        BPlusTree<int>::Iterator it = bpt.find(random_int);
        if(it.is_null()) cout << random_int << " was not found" << endl;
        else cout << random_int << " was found" << endl;
    }

    cout << "========================================================" << endl;

    cout << "Removing all values from the tree: " << endl;
    cout << bpt << endl;
    for (int k = 0; k < size; ++k) {
        cout << "Removing " << data[k] << endl;
        bpt.remove(data[k]);
        //cout << bpt << endl;
    }

    cout << bpt << endl;

    cout << "========================================================" << endl;
    cout << "End of test" << endl;
    cout << "========================================================" << endl;
}

void test_bpt_big3(){
    BPlusTree<int> bpt;
    int size = 50;

    cout << "Inserting " << size << " random integers:" << endl;
    for (int i = 0; i < size; ++i) {
        bpt.insert(rand() % 1000);
    }

    cout << bpt << endl;

    cout << "========================================================" << endl;

    cout << "Copy constructor:" << endl;
    cout << "BPlusTree<int> bpt2(bpt);" << endl;
    BPlusTree<int> bpt2(bpt);
    cout << "bpt2: " << endl;
    cout << bpt2 << endl;

    cout << "========================================================" << endl;

    cout << "Assignment operator:" << endl;
    BPlusTree<int> bpt3;
    cout << "bpt3 = bpt;" << endl;
    bpt3 = bpt;
    cout << "bpt3:" << endl;
    cout << bpt3 << endl;

    cout << "========================================================" << endl;
    cout << "End of test" << endl;
    cout << "========================================================" << endl;
}

void test_map(){
    Map<int, char> map;
    int size = 50;
    int data[size];

    cout << "Inserting " << size << " random pairs of <int, char>:" << endl;
    for (int i = 0; i < size; ++i) {
        int random_int = rand() % 1000;
        char random_char = rand() % (90 - 65 + 1) + 65;
        data[i] = random_int;
        map.insert(random_int, random_char);
    }

    cout << map << endl;

    cout << "========================================================" << endl;

    cout << "Map is valid: ";
    cout << map.is_valid() << endl;

    cout << "========================================================" << endl;

    cout << "Printing leaves using Iterator:" << endl;
    for(Map<int, char>::Iterator it = map.begin();
        it!= map.end(); ++it){
        cout << "[" << *it << "]" << endl;
    }

    cout << "========================================================" << endl;

    cout << "Find 10 keys that are in the map:" << endl;
    for (int j = 0; j < 10; ++j) {
        int random_element = data[rand() % (size - 1)];
        Map<int, char>::Iterator it = map.find(random_element);
        if(it.is_null()) cout << random_element << " was not found" << endl;
        else cout << random_element << " was found" << endl;
    }

    cout << "========================================================" << endl;

    cout << "Find 10 keys that are not in the map:" << endl;
    for (int j = 0; j < 10; ++j) {
        int random_int = 1000 + rand() % 1000;
        Map<int, char>::Iterator it = map.find(random_int);
        if(it.is_null()) cout << random_int << " was not found" << endl;
        else cout << random_int << " was found" << endl;
    }

    cout << "========================================================" << endl;

    cout << "Removing all keys from the map: " << endl;
    cout << map << endl;
    for (int k = 0; k < size; ++k) {
        cout << "Removing " << data[k] << endl;
        map.erase(data[k]);
    }

    cout << map << endl;

    cout << "========================================================" << endl;
    cout << "End of test" << endl;
    cout << "========================================================" << endl;
}

void test_mmap(){
    MMap<int, char> mmap;
    int size = 50;
    int data[size];

    cout << "Inserting " << size << " random pairs of <int, <char> >:" << endl;
    for (int i = 0; i < size; ++i) {
        int random_int = rand() % 15;
        char random_char = rand() % (90 - 65 + 1) + 65;
        data[i] = random_int;
        mmap.insert(random_int, random_char);
    }

    cout << mmap << endl;

    cout << "========================================================" << endl;

    cout << "mmap is valid: ";
    cout << mmap.is_valid() << endl;

    cout << "========================================================" << endl;

    cout << "Printing leaves using Iterator:" << endl;
    for(MMap<int, char>::Iterator it = mmap.begin();
        it!= mmap.end(); ++it){
        cout << "[" << *it << "]" << endl;
    }

    cout << "========================================================" << endl;

    cout << "Find 5 keys that are in the mmap:" << endl;
    for (int j = 0; j < 5; ++j) {
        int random_element = data[rand() % (size - 1)];
        MMap<int, char>::Iterator it = mmap.find(random_element);
        if(it.is_null()) cout << random_element << " was not found" << endl;
        else cout << random_element << " was found" << endl;
    }

    cout << "========================================================" << endl;

    cout << "Find 5 keys that are not in the mmap:" << endl;
    for (int j = 0; j < 5; ++j) {
        int key = 20 + j;
        MMap<int, char>::Iterator it = mmap.find(key);
        if(it.is_null()) cout << key << " was not found" << endl;
        else cout << key << " was found" << endl;
    }

    cout << "========================================================" << endl;

    cout << "Removing all keys from the mmap: " << endl;
    cout << mmap << endl;
    for (int k = 0; k < 15; ++k) {
        cout << "Removing " << k << endl;
        mmap.erase(k);
    }

    cout << mmap << endl;

    cout << "========================================================" << endl;
    cout << "End of test" << endl;
    cout << "========================================================" << endl;
}
