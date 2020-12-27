/*
 * Author: Brendan Chess
 * Project: Hash Tables
 * Purpose: Implement an open hash table class and a chained hash table class
 *      along with demo functions
 * Notes: Interactive demo works best with table size of 17, and random demo
 *      works best with table size of 811
 */
#ifndef HASH_CHAINED_HASH_H
#define HASH_CHAINED_HASH_H

#include <cstdlib>
#include <iostream>
#include "record.h"
using namespace std;

#include "../!includes/list/list.h"

template <typename T>
class chained_hash{
public:
    static const size_t TABLE_SIZE = 17;

    chained_hash();
    chained_hash(const chained_hash& source);
    ~chained_hash();

    void insert(const T& entry);
    bool remove(int key);
    chained_hash<T>& operator =(const chained_hash& source);

    void find(int key, bool& found, T& result) const;
    bool is_present(int key) const;
    size_t size() const { return total_records; }

    friend ostream& operator <<(ostream& outs, const chained_hash<T>& print_me){
        for (int i = 0; i < print_me.TABLE_SIZE; ++i) {
            outs <<  "[" << i <<  "] ";
            print_list(print_me.data[i], outs);
            outs << endl;
        }
        return outs;
    }
private:
    node<T>* data[TABLE_SIZE];
    size_t total_records = 0;
    size_t hash(int key) const;
};

template<typename T>
chained_hash<T>::chained_hash() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        data[i] = nullptr;
    }
}

template<typename T>
chained_hash<T>::chained_hash(const chained_hash &source) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        data[i] = source.data[i];
    }
    total_records = source.total_records;
}

template<typename T>
chained_hash<T>::~chained_hash() {}

template<typename T>
void chained_hash<T>::insert(const T &entry) {
    bool already_present = false;
    size_t index = hash(entry._key);
    node<T>* rec;

    assert(entry._key >= 0);

    rec = find_node(data[index], entry, already_present);

    if(!already_present){
        index = hash(entry._key);
        insert_head(data[index], entry);
        ++total_records;
    } else {
        rec->_item = entry;
    }
}

template<typename T>
bool chained_hash<T>::remove(int key) {
    assert(key >= 0);
    size_t index = hash(key);
    bool success = false;
    list_remove(data[index], record(key), success);
    if(success) total_records--;
    return success;
}

template<typename T>
chained_hash<T>& chained_hash<T>::operator=(const chained_hash &source) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        data[i] = source.data[i];
    }
    total_records = source.total_records;
    return *this;
}

template<typename T>
void chained_hash<T>::find(int key, bool &found, T &result) const {
    node<T>* res = find_node(data[hash(key)], record(key), found);
    if(res) result = res->_item;
    else result = NULL;
}

template<typename T>
bool chained_hash<T>::is_present(int key) const {
    size_t index = hash(key);
    bool found;
    find_node(data[index], record(key), found);
    return found;
}

template<typename T>
size_t chained_hash<T>::hash(int key) const {
    return key % TABLE_SIZE;
}

#endif //HASH_CHAINED_HASH_H
