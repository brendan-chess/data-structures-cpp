/*
 * Author: Brendan Chess
 * Project: BTree progress 2
 * Purpose: Implement remove in BTree and create a Map and MultiMap class
 *      based on BTree
 */
#ifndef MAP_MAP_H
#define MAP_MAP_H

using namespace std;
#include <iostream>
#include "../btree/BTree.h"

template <typename K, typename V>
struct Pair{
    K key;
    V value;

    Pair(const K& k=K(), const V& v=V()){
        key = k;
        value = v;
    }

    friend ostream& operator <<(ostream& outs, const Pair<K, V>& print_me){
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
    typedef BTree<Pair<K,V>> map_base;

    int size() const;
    bool empty() const;

    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();
    V get(const K& key);

    V& operator[](const K& key);
    V& at(const K& key);
    const V& at(const K& key) const;

    bool contains(const Pair<K, V>& target) const;

    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me){
        outs<<print_me.map;
        return outs;
    }
private:
    BTree<Pair<K,V>> map;
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
void Map<K, V>::erase(const K &key) {
    map.remove(key);
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


#endif //MAP_MAP_H
