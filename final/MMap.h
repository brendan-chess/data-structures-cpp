/*
 * Author: Brendan Chess
 * Project: Final Project
 * Purpose: Implement a database that responds to SQL commands on the command
 *      line or from a batch file
 */
#ifndef DATABASE_MMAP_H
#define DATABASE_MMAP_H

#include <vector>
#include "BPlusTree.h"

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
    typedef BPlusTree<MPair<K,V>> map_base;

    class Iterator{
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it):_it(it){}
        Iterator operator ++(){ return ++_it; }
        MPair<K, V> operator *(){ return *_it; }
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
    MMap<K, V> lower_bound(const K& key);
    MMap<K, V> upper_bound(const K& key);

    int size() const;
    bool empty() const;
    bool is_valid();

    const vector<V>& operator[](const K& key) const;
    vector<V>& operator[](const K& key);

    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();

    bool contains(const K& key) const;
    vector<V> &get(const K& key);
    Iterator find(const K& key);
    int count(const K& key);

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me){
        outs<<print_me.mmap<<endl;
        return outs;
    }

private:
    BPlusTree<MPair<K,V>> mmap;
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

template<typename K, typename V>
typename MMap<K,V>::Iterator MMap<K, V>::begin() {
    return Iterator(mmap.begin());
}

template<typename K, typename V>
typename MMap<K,V>::Iterator MMap<K, V>::end() {
    return Iterator(mmap.end());
}

template<typename K, typename V>
typename MMap<K,V>::Iterator MMap<K, V>::find(const K &key) {
    return mmap.find(MPair<K,V>(key));
}

template<typename K, typename V>
bool MMap<K, V>::is_valid() {
    return mmap.is_valid();
}

template<typename K, typename V>
int MMap<K, V>::count(const K &key) {
    return mmap.get_existing(MPair<K,V>(key)).value_list.size();
}

template<typename K, typename V>
void MMap<K, V>::erase(const K &key) {
    mmap.remove(key);
}

template<typename K, typename V>
MMap<K, V> MMap<K, V>::lower_bound(const K &key) {
    MMap result;

    Iterator iter(mmap.begin());
    Iterator stop(mmap.find(key));

    while(iter != stop){
        MPair<K, V> pair = (*(iter));
        for (int i = 0; i < pair.value_list.size(); ++i) {
            result.insert(pair.key, pair.value_list[i]);
        }
        ++iter;
    }

    return result;
}

template<typename K, typename V>
MMap<K, V> MMap<K, V>::upper_bound(const K &key) {
    MMap result;

    Iterator iter(mmap.find(key));
    ++iter;

    while(!iter.is_null()){
        MPair<K, V> pair = (*(iter));
        for (int i = 0; i < pair.value_list.size(); ++i) {
            result.insert(pair.key, pair.value_list[i]);
        }
        ++iter;
    }

    return result;
}

#endif //DATABASE_MMAP_H
