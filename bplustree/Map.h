/*
 * Author: Brendan Chess
 * Project: B+Tree Map & MultiMap
 * Purpose: Implement Map and MultiMap classes based on a B+Tree
 * Notes: Depends on B+Tree class and array util functions
 */
#ifndef BPLUSTREE_MAP_H
#define BPLUSTREE_MAP_H
using namespace std;
#include <iostream>
#include "BPlusTree.h"

template <typename K, typename V>
struct Pair{
    K key;
    V value;

    Pair(const K& k=K(), const V& v=V()){
        key = k;
        value = v;
    }

    friend ostream& operator <<(ostream& outs, const Pair<K, V>& print_me){
        bool print_as_row = false;

        if(print_as_row)
            outs << print_me.key << '|' << print_me.value;
        else
            outs << '(' << print_me.key << ',' << print_me.value << ')';

        return outs;
    }

    friend bool operator ==(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        return lhs.key == rhs.key;
    }

    friend bool operator < (const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        return lhs.key < rhs.key;
    }

    friend bool operator > (const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        return lhs.key > rhs.key;
    }

    friend bool operator <= (const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        return lhs.key <= rhs.key;
    }

    friend Pair<K, V> operator += (Pair<K, V>& lhs, const Pair<K, V>& rhs){
        lhs.value = rhs.value;
        return lhs;
    }
};



template <typename K, typename V>
class Map{
public:
    typedef BPlusTree<Pair<K,V>> map_base;

    class Iterator{
    public:
        friend class Map;
        Iterator(typename map_base::Iterator it):_it(it){}
        Iterator operator ++(){ return ++_it; }
        Pair<K, V> operator *(){ return *_it; }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs){
            return lhs._it == rhs._it;
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs){
            return lhs._it != rhs._it;
        }
        bool is_null(){ return _it.is_null(); }
    private:
        typename map_base::Iterator _it;
    };

    Iterator begin();
    Iterator end();

    int size() const;
    bool empty() const;
    bool is_valid();

    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();
    V get(const K& key);

    V& operator[](const K& key);
    V& at(const K& key);
    const V& at(const K& key) const;

    bool contains(const Pair<K, V>& target) const;
    Iterator find(const K& key);

    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me){
        outs<<print_me.map;
        return outs;
    }
private:
    BPlusTree<Pair<K,V>> map;
};



template<typename K, typename V>
int Map<K, V>::size() const {
    return map.size();
}

template<typename K, typename V>
bool Map<K, V>::empty() const {
    return map.empty();
}

template<typename K, typename V>
void Map<K, V>::insert(const K &k, const V &v) {
    map.insert(Pair<K,V>(k, v));
}

template<typename K, typename V>
void Map<K, V>::clear() {
    map.clear_tree();
}

template<typename K, typename V>
V Map<K, V>::get(const K &key) {
    return map.get(key).value;
}

template<typename K, typename V>
V& Map<K, V>::operator[](const K &key) {
    return map.get(key).value;
}

template<typename K, typename V>
V& Map<K, V>::at(const K &key) {
    return map.get(key).value;
}

template<typename K, typename V>
const V& Map<K, V>::at(const K &key) const {
    return map.get_existing(key).value;
}

template<typename K, typename V>
bool Map<K, V>::contains(const Pair<K,V> &target) const {
    return map.contains(target);
}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::find(const K &key) {
    return map.find(Pair<K,V>(key));
}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::begin() {
    return Iterator(map.begin());
}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::end() {
    return Iterator(map.end());
}

template<typename K, typename V>
bool Map<K, V>::is_valid() {
    return map.is_valid();
}

template<typename K, typename V>
void Map<K, V>::erase(const K &key) {
    map.remove(key);
}

#endif //BPLUSTREE_MAP_H
