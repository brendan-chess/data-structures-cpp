/*
 * Author: Brendan Chess
 * Project: Hash Tables
 * Purpose: Implement an open hash table class and a chained hash table class
 *      along with demo functions
 * Notes: Interactive demo works best with table size of 17, and random demo
 *      works best with table size of 811
 */
#ifndef HASH_RECORD_H
#define HASH_RECORD_H

#include <iostream>
using namespace std;

struct record
{
    int _key;
    double _value;

    record(int k=0, double v=0):_key(k), _value(v){}
    friend bool operator ==(const record& left, const record& right);
    friend ostream& operator <<(ostream& outs, const record& print_me);
};

bool operator==(const record &left, const record &right) {
    return left._key == right._key;
}

ostream &operator<<(ostream &outs, const record &print_me) {
    outs << "[Key:" << print_me._key << "|Value:" << print_me._value << "]";
    return outs;
}

#endif //HASH_RECORD_H
