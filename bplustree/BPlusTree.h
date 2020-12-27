/*
 * Author: Brendan Chess
 * Project: B+Tree Map & MultiMap
 * Purpose: Implement Map and MultiMap classes based on a B+Tree
 * Notes: Depends on B+Tree class and array util functions
 */
#ifndef BPLUSTREE_BPLUSTREE_H
#define BPLUSTREE_BPLUSTREE_H

#include <iostream>
#include <iomanip>
#include "../!includes/array_utils/array_utils.h"
using namespace std;

template <class T>
class BPlusTree{
public:
    class Iterator{
    public:
        friend class BPlusTree<T>;
        Iterator(BPlusTree<T>* _it = NULL, int _key_ptr = 0):it(_it), key_ptr(_key_ptr){}

        T operator *() {
            if(is_null()) return T();
            assert(key_ptr < it->data_count);
            return it->data[key_ptr];
        }

        Iterator operator++(){
            assert(it);
            key_ptr++;
            if(key_ptr == it->data_count) {
                it = it->next;
                key_ptr = 0;
            }
            return *this;
        }

        friend bool operator ==(const Iterator& lhs, const Iterator& rhs){
            return lhs.it == rhs.it;
        }

        friend bool operator !=(const Iterator& lhs, const Iterator& rhs){
            return lhs.it != rhs.it;
        }

        bool is_null(){ return !it; }
    private:
        BPlusTree<T>* it;
        int key_ptr;
    };

    //Constructor
    BPlusTree(bool dups = false);

    //Big 3
    BPlusTree(const BPlusTree<T>& other);
    ~BPlusTree();
    BPlusTree<T>& operator =(const BPlusTree<T>& RHS);

    //Modifiers
    void insert(const T& entry);
    void clear_tree();
    void copy_tree(const BPlusTree<T>& other);
    void remove(const T& entry);

    //Search
    bool contains(const T& entry) const;
    T& get(const T& entry);
    const T& get(const T& entry) const;
    T& get_existing(const T& entry);
    Iterator find(const T& entry);

    //Meta
    int size() const { return tree_size; }
    bool empty() const { return tree_size == 0; }
    bool is_valid();

    void print_tree(int level = 0, ostream &outs=cout) const;
    friend ostream& operator<<(ostream& outs, const BPlusTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }

    Iterator begin();
    Iterator end();
private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    bool dups_ok;
    int data_count, child_count;
    T data[MAXIMUM + 1];
    BPlusTree* subset[MAXIMUM + 2];
    BPlusTree* next;
    int tree_size;

    bool is_leaf() const { return child_count == 0; }

    void copy_tree(const BPlusTree<T>& other, BPlusTree<T>* &last_node);

    //Insertion helpers
    void loose_insert(const T& entry);
    void fix_excess(int i);

    //Remove helpers
    void loose_remove(const T& entry);
    BPlusTree<T>* fix_shortage(int i);
    BPlusTree<T>* get_smallest_node();
    void transfer_left(int i);
    void transfer_right(int i);
    void merge_with_next_subset(int i);
};

//- - - - - - - - - - - - - - - -//

template<class T>
BPlusTree<T>::BPlusTree(bool dups) {
    dups_ok = dups;
    data_count = 0;
    child_count = 0;
    next = NULL;
    tree_size = 0;

    for (int i = 0; i < MAXIMUM + 1; ++i) {
        data[i] = T();
        subset[i] = NULL;
    }
    subset[MAXIMUM + 1] = NULL;
}

template<class T>
void BPlusTree<T>::insert(const T &entry) {
    loose_insert(entry);
    tree_size++;
    //handle excess in root if needed
    if(data_count > MAXIMUM){
        BPlusTree<T>* grow = new BPlusTree<T>(dups_ok);
        copy_array(grow->data, data, grow->data_count, data_count);
        copy_array(grow->subset, subset, grow->child_count, child_count);

        for (int i = 0; i < data_count; ++i) {
            data[i] = T();
        }
        for (int j = 0; j < child_count; ++j) {
            subset[j] = NULL;
        }
        data_count = 0;
        child_count = 1;

        subset[0] = grow;

        fix_excess(0);
    }
}

template<class T>
void BPlusTree<T>::loose_insert(const T &entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(found){
        if(is_leaf()){
            data[i] += entry; //only use with pair/mpair as template
            //deal with duplicates
        } else {
            subset[i + 1]->loose_insert(entry);
            if(subset[i + 1]->data_count > MAXIMUM) fix_excess(i + 1);
        }
    } else {
        if(is_leaf()){
            insert_item(data, i, data_count, entry);
        }
        else {
            subset[i]->loose_insert(entry);
            if(subset[i]->data_count > MAXIMUM) fix_excess(i);
        }
    }
}

template<class T>
void BPlusTree<T>::fix_excess(int i) {
    insert_item(subset, i + 1, child_count, new BPlusTree<T>(dups_ok));

    if(subset[i]->is_leaf() && subset[i + 1]->is_leaf()){
        subset[i + 1]->next = subset[i]->next;
        subset[i]->next = subset[i + 1];
    }

    split(subset[i]->data, subset[i]->data_count, subset[i + 1]->data, subset[i + 1]->data_count);
    split(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset, subset[i + 1]->child_count);
    T entry;
    detach_item(subset[i]->data, subset[i]->data_count, entry);
    ordered_insert(data, data_count, entry);

    if(subset[i + 1]->is_leaf())
        insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, entry);
}

template<class T>
void BPlusTree<T>::print_tree(int level, ostream &outs) const {
    bool debug = false;

    //last childs index
    int index = child_count - 1;

    //print last child (if it exists)
    if(index >= 0) subset[index]->print_tree(level + 3);

    //print this
    if(is_leaf()) outs << "\033[32m";
    outs << setw(4 * level);
//    if(debug) {
//        outs << "[" << "DC:" << data_count << "|CC:" << child_count << "]-";
//    }
    if(debug){
        outs << "[" << "THIS:" << this << "|NEXT:" << next << "]-";
    }

    print_array(data, data_count);

    if(is_leaf()) outs << "\033[0m";

    //print other children (if they exist)
    index--;
    while(index >= 0){
        subset[index]->print_tree(level + 3);
        index--;
    }
}

template<class T>
void BPlusTree<T>::clear_tree() {
    for (int i = 0; i < child_count; ++i) {
        subset[i]->clear_tree();
    }
    for (int j = 0; j < child_count; ++j) {
        delete subset[j];
        subset[j] = NULL;
    }
    data_count = 0;
    child_count = 0;
    tree_size = 0;
}

template<class T>
bool BPlusTree<T>::contains(const T &entry) const {
    int i = first_ge(data, data_count, entry);
    bool found = data[i] == entry;
    if(found) return true;
    else if(is_leaf()) return false;
    else return subset[i]->contains(entry);
}

template<class T>
T& BPlusTree<T>::get(const T &entry) {
    if(!contains(entry)) insert(entry);
    return get_existing(entry);
}

template<class T>
const T& BPlusTree<T>::get(const T &entry) const {
    return get_existing(entry);
}

template<class T>
T& BPlusTree<T>::get_existing(const T &entry) {
    int i = first_ge(data, data_count, entry);
    bool found = data[i] == entry;
    if(found){
        if(is_leaf()) return data[i];
        else return subset[i + 1]->get_existing(entry);
    } else {
        assert(!is_leaf());
        return subset[i]->get_existing(entry);
    }
}

template<class T>
BPlusTree<T>::~BPlusTree() {
    clear_tree();
}

template<class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::find(const T &entry) {
    int i = first_ge(data, data_count, entry);
    bool found = data[i] == entry;
    if(found){
        if(is_leaf()) return Iterator(this, i);
        else return subset[i + 1]->find(entry);
    } else {
        if(is_leaf()) return Iterator();
        else return subset[i]->find(entry);
    }
}

template<class T>
BPlusTree<T>* BPlusTree<T>::get_smallest_node() {
    if(is_leaf()) return this;
    else return subset[0]->get_smallest_node();
}

template<class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::begin() {
    return Iterator(get_smallest_node());
}

template<class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::end() {
    return Iterator();
}

template<class T>
void BPlusTree<T>::copy_tree(const BPlusTree<T> &other) {
    BPlusTree<T>* last_node = nullptr;
    copy_tree(other, last_node);
}

template<class T>
void BPlusTree<T>::copy_tree(const BPlusTree<T> &other, BPlusTree<T>* &last_node) {
    copy_array(data, other.data, data_count, other.data_count);

    child_count = other.child_count;
    for (int i = 0; i < child_count; ++i) {
        subset[i] = new BPlusTree<T>(dups_ok);
        subset[i]->copy_tree(*other.subset[i], last_node);
    }

    if(is_leaf()){
        if(!last_node) last_node = this;
        else {
            last_node->next = this;
            last_node = this;
        }
    }
}

template<class T>
BPlusTree<T>::BPlusTree(const BPlusTree<T> &other) {
    data_count = 0;
    child_count = 0;
    next = NULL;
    tree_size = 0;
    copy_tree(other);
}

template<class T>
BPlusTree<T>& BPlusTree<T>::operator=(const BPlusTree<T> &RHS) {
    copy_tree(RHS);
    return *this;
}

template<class T>
bool BPlusTree<T>::is_valid() {
    if(is_leaf()) return true;

    if(!is_le(subset[child_count - 1]->data, subset[child_count - 1]->data_count, data[data_count - 1]))
        return false;

    for (int i = 0; i < data_count; ++i) {
        if(!is_gt(subset[i]->data, subset[i]->data_count, data[i]))
            return false;
    }

    for (int j = 0; j < child_count; ++j) {
        if(!subset[j]->is_valid()) return false;
    }

    return true;
}

template<class T>
void BPlusTree<T>::remove(const T &entry) {
    loose_remove(entry);
    tree_size--;
    if(data_count == 0 && child_count == 1){
        BPlusTree<T>* shrink_ptr = subset[0];
        copy_tree(*shrink_ptr);
        delete shrink_ptr;
    }
}

template<class T>
void BPlusTree<T>::loose_remove(const T &entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(child_count == 0){
        if(found){
            delete_index(data, i, data_count);
        }
    } else {
        if(found){
            subset[i + 1]->loose_remove(entry);
            if(subset[i + 1]->data_count < MINIMUM) fix_shortage(i + 1);
            if(i < child_count - 1)
                data[i] = subset[i + 1]->get_smallest_node()->data[0];
        } else {
            subset[i]->loose_remove(entry);
            if(subset[i]->data_count < MINIMUM) fix_shortage(i);
        }
    }
}

template<class T>
BPlusTree<T>* BPlusTree<T>::fix_shortage(int i) {
    if((i + 1 < child_count) && subset[i + 1]->data_count > MINIMUM){
        transfer_left(i + 1);
    } else if(i > 0 && subset[i - 1]->data_count > MINIMUM){
        transfer_right(i - 1);
    } else if(i > 0){
        merge_with_next_subset(i - 1);
    } else {
        merge_with_next_subset(i);
    }
}

template<class T>
void BPlusTree<T>::transfer_left(int i) {
    if(subset[i]->is_leaf()){
        T middle;
        delete_item(subset[i]->data, 0, subset[i]->data_count, middle);
        attach_item(subset[i - 1]->data, subset[i - 1]->data_count, middle);
        data[i - 1] = subset[i]->data[0];
    } else {
        T middle = data[i - 1];
        delete_item(subset[i]->data, 0, subset[i]->data_count, data[i - 1]);
        attach_item(subset[i - 1]->data, subset[i - 1]->data_count, middle);
        if(subset[i]->child_count > 0){
            BPlusTree<T>* carry = NULL;
            delete_item(subset[i]->subset, 0, subset[i]->child_count, carry);
            attach_item(subset[i - 1]->subset, subset[i - 1]->child_count, carry);
        }
    }
}

template<class T>
void BPlusTree<T>::transfer_right(int i) {
    if(subset[i]->is_leaf()){
        T middle;
        detach_item(subset[i]->data, subset[i]->data_count, middle);
        insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, middle);
        data[i] = middle;
    } else {
        T middle = data[i];
        detach_item(subset[i]->data, subset[i]->data_count, data[i]);
        insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, middle);
        if(subset[i]->child_count > 0){
            BPlusTree<T>* carry = NULL;
            detach_item(subset[i]->subset, subset[i]->child_count, carry);
            insert_item(subset[i + 1]->subset, 0, subset[i + 1]->child_count, carry);
        }
    }
}

template<class T>
void BPlusTree<T>::merge_with_next_subset(int i) {
    if(subset[i]->is_leaf()){
        delete_index(data, i, data_count);
        merge(subset[i]->data, subset[i]->data_count, subset[i + 1]->data, subset[i + 1]->data_count);
        subset[i]->next = subset[i + 1]->next;
        delete_index(subset, i + 1, child_count);
    } else {
        T middle;
        delete_item(data, i, data_count, middle);
        attach_item(subset[i]->data, subset[i]->data_count, middle);
        merge(subset[i]->data, subset[i]->data_count, subset[i + 1]->data, subset[i + 1]->data_count);
        merge(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset, subset[i + 1]->child_count);
        delete_index(subset, i + 1, child_count);
    }

}

#endif //BPLUSTREE_BPLUSTREE_H
