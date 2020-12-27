/*
 * Author: Brendan Chess
 * Project: Hash Tables
 * Purpose: Implement an open hash table class and a chained hash table class
 *      along with demo functions
 * Notes: Interactive demo works best with table size of 17, and random demo
 *      works best with table size of 811
 */
#ifndef HASH_OPEN_HASH_H
#define HASH_OPEN_HASH_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class open_hash{
public:
    static const size_t CAPACITY = 17;

    open_hash();

    void insert(const T& entry);
    bool remove(int key);

    bool is_present(int key) const;
    void find(int key, bool& found, T& result) const;
    size_t size() const { return used; }

    friend ostream& operator <<(ostream& outs, const open_hash<T>& print_me){
        for (int i = 0; i < print_me.CAPACITY; ++i) {
            outs <<  "[" << i <<  "] ";
            if(print_me.data[i]._key >= 0) {
                size_t hash = print_me.hash(print_me.data[i]._key);
                outs << print_me.data[i] << " Hash: " << hash;
                if(hash != i) outs << " *";
            } else if (print_me.data[i]._key == -2) {
                outs << "- - - - - - -";
            }
            outs << endl;
        }
        return outs;
    }
private:
    static const int NEVER_USED = -1;
    static const int PREVIOUSLY_USED = -2;

    T data[CAPACITY];
    size_t used = 0;

    size_t hash(int key) const;
    size_t next_index(size_t index) const;
    void find_index(int key, bool& found, size_t& index) const;
    bool never_used(size_t index) const;
    bool is_vacant(size_t index) const;
};

template<typename T>
open_hash<T>::open_hash() {
    for (int i = 0; i < CAPACITY; ++i) {
        data[i]._key = NEVER_USED;
    }
}

template<typename T>
void open_hash<T>::insert(const T &entry) {
    bool already_present;
    size_t index;

    //ensure the new entry has a key we can use
    assert(entry._key >= 0);

    //check if the entry is already in the table
    find_index(entry._key, already_present, index);

    //if true, find the index to insert the entry at
    //if false, update the entry in the table
    if(!already_present){
        //ensure we have empty spots left in the table
        assert(size() < CAPACITY);
        index = hash(entry._key);
        //linear probe to find next empty spot, if needed
        while(!is_vacant(index))
            index = next_index(index);
        //keep track of spots used in the table
        ++used;
    }

    data[index] = entry;
}

template<typename T>
bool open_hash<T>::remove(int key) {
    bool found;
    size_t index;

    //ensure we receive a key that we can work with
    assert(key >= 0);

    find_index(key, found, index);
    if(found){
        //make spot available
        data[index]._key = PREVIOUSLY_USED;
        //keep track of spots used
        --used;
    }

    //true if removal was successful
    //false if the key to remove was not in the table
    return found;
}

template<typename T>
bool open_hash<T>::is_present(int key) const {
    bool found;
    size_t index;
    assert(key >= 0);
    find_index(key, found, index);
    return found;
}

template<typename T>
void open_hash<T>::find(int key, bool &found, T &result) const {
    size_t index;
    assert(key >= 0);
    find_index(key, found, index);
    if(found) result = data[index];
}

template<typename T>
size_t open_hash<T>::hash(int key) const {
    return key % CAPACITY;
}

template<typename T>
size_t open_hash<T>::next_index(size_t index) const {
    return (index + 1) % CAPACITY;
}

template<typename T>
void open_hash<T>::find_index(int key, bool &found, size_t &index) const {
    size_t count = 0;

    index = hash(key);
    while((count < CAPACITY) && (!never_used(index)) && (data[index]._key != key)){
        ++count;
        index = next_index(index);
    }
    found = data[index]._key == key;
}

template<typename T>
bool open_hash<T>::never_used(size_t index) const {
    return data[index]._key == NEVER_USED;
}

template<typename T>
bool open_hash<T>::is_vacant(size_t index) const {
    return data[index]._key < 0;
}

#endif //HASH_OPEN_HASH_H
