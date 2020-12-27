/*
 * Author: Brendan Chess
 * Project: BTree progress 2
 * Purpose: Implement remove in BTree and create a Map and MultiMap class
 *      based on BTree
 */
#ifndef MAP_MMAP_H
#define MAP_MMAP_H

using namespace std;
#include<iostream>
#include <vector>
#include "../btree/BTree.h"

template <typename K, typename V>
struct MPair{
    K key;
    vector<V> value_list;

    MPair(const K& k=K()){
        key = k;
    }
    MPair(const K& k, const V& v){
        key = k;
        value_list.push_back(v);
    }
    MPair(const K& k, const vector<V>& vlist){
        key = k;
        value_list = vlist;
    }

    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me){
        outs << '(' << print_me.key << ",<";
        int value_length = print_me.value_list.size();
        for (int i = 0; i < value_length; i++) {
            outs << print_me.value_list[i];
            if(i < value_length - 1) outs << ',';
        }
        outs << ">)";
        return outs;
    }

    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs.key == rhs.key;
    }
    friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs.key < rhs.key;
    }
    friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs.key <= rhs.key;
    }
    friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs.key > rhs.key;
    }
    friend MPair<K, V> operator += (MPair<K, V>& lhs, const MPair<K, V>& rhs){
        for (V value: rhs.value_list) {
            lhs.value_list.push_back(value);
        }
        return lhs;
    }
};



template <typename K, typename V>
class MMap
{
public:
    typedef BTree<MPair<K,V>> map_base;

    int size() const;
    bool empty() const;

    const vector<V>& operator[](const K& key) const;
    vector<V>& operator[](const K& key);

    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();

    bool contains(const K& key) const;
    vector<V> &get(const K& key);

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me){
        outs<<print_me.mmap<<endl;
        return outs;
    }

private:
    BTree<MPair<K,V>> mmap;
};

template<typename K, typename V>
int MMap<K, V>::size() const {
    return mmap.size();
}

template<typename K, typename V>
bool MMap<K, V>::empty() const {
    return mmap.empty();
}

template<typename K, typename V>
const vector<V>& MMap<K, V>::operator[](const K &key) const {
    return mmap.get_existing(MPair<K,V>(key)).value_list;
}

template<typename K, typename V>
vector<V>& MMap<K, V>::operator[](const K &key) {
    return mmap.get(MPair<K,V>(key)).value_list;
}

template<typename K, typename V>
void MMap<K, V>::insert(const K &k, const V &v) {
    mmap.insert(MPair<K,V>(k, v));
}

template<typename K, typename V>
void MMap<K, V>::erase(const K &key) {
    mmap.remove(MPair<K,V>(key));
}

template<typename K, typename V>
void MMap<K, V>::clear() {
    mmap.clear_tree();
}

template<typename K, typename V>
bool MMap<K, V>::contains(const K &key) const {
    return mmap.contains(MPair<K,V>(key));
}

template<typename K, typename V>
vector<V>& MMap<K, V>::get(const K &key) {
    return mmap.get(MPair<K,V>(key)).value_list;
}

#endif //MAP_MMAP_H
