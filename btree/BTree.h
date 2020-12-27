/*
 * Author: Brendan Chess
 * Project: BTree class
 * Purpose: Implement a complete BTree class
 * Notes: Dependent on array util functions
 */
#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H

#include "../!includes/array_utils/array_utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class BTree
{
public:
    BTree(bool dups = false); //allow duplicates or not

    //big 3
    BTree(const BTree<T>& other); //copy constructor
    ~BTree(); //destructor
    BTree<T>& operator =(const BTree<T>& RHS); //equals operator

    void insert(const T& entry); //insert entry into the btree
    void remove(const T& entry); //remove entry from the btree

    void clear_tree(); //deletes all children
    void copy_tree(const BTree<T>& other); //makes this tree look like other

    bool contains(const T& entry) const; //is entry found in the tree
    T& get(const T& entry); //returns a reference to entry as found in data
    T* find(const T& entry); //returns a pointer to entry as found in data

    int size() const; //how many elements are in the tree
    bool empty() const; //does data have zero elements

    void print_tree(int level = 0, ostream &outs=cout) const;
    friend ostream& operator<<(ostream& outs, const BTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }
private:
    static const int MINIMUM = 1; //range of size for data and subset
    static const int MAXIMUM = 2 * MINIMUM;

    int tree_size; //total # of data elements in tree
    bool dups_ok; //can we have duplicate entries
    int data_count; //how many elements are in data
    T data[MAXIMUM + 1]; //stores values
    int child_count; //how many subtrees are there off this object
    BTree* subset[MAXIMUM + 2]; //stores pointers to other btrees

    bool is_leaf() const {return child_count==0;} //are there subtrees

    void loose_insert(const T& entry);
    void fix_excess(int i);

    T& get_existing(const T& entry);

    void loose_remove(const T& entry);
    void fix_shortage(int i);

    void remove_biggest(T& entry);
    void rotate_left(int i);
    void rotate_right(int i);
    void merge_with_next_subset(int i);
};

template<class T>
BTree<T>::BTree(bool dups) {
    dups_ok = dups;
    data_count = 0;
    child_count = 0;
    tree_size = 0;

    for (int i = 0; i < MAXIMUM + 1; ++i) {
        data[i] = T();
        subset[i] = NULL;
    }
    subset[MAXIMUM + 1] = NULL;
}

template<class T>
BTree<T>::BTree(const BTree<T> &other) {
    copy_tree(other);
}

template<class T>
BTree<T>::~BTree() {
    clear_tree();
}

template<class T>
BTree<T> &BTree<T>::operator=(const BTree<T> &RHS) {
    copy_tree(RHS);
    return *this;
}

template<class T>
void BTree<T>::insert(const T &entry) {
    loose_insert(entry);
    tree_size++;
    //handle excess in root if needed
    if(data_count > MAXIMUM){
        BTree<T>* grow = new BTree<T>(dups_ok);
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
void BTree<T>::remove(const T &entry) {
    loose_remove(entry);
    tree_size--;
    if(data_count == 0 && child_count == 1){
        BTree<T>* shrink_ptr = subset[0];
        copy_tree(*shrink_ptr);
        delete shrink_ptr;
    }
}

template<class T>
void BTree<T>::clear_tree() {
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
void BTree<T>::copy_tree(const BTree<T> &other) {
    copy_array(data, other.data, data_count, other.data_count);
    child_count = other.child_count;
    for (int i = 0; i < child_count; ++i) {
        subset[i] = new BTree<T>(dups_ok);
        subset[i]->copy_tree(*other.subset[i]);
    }
}

template<class T>
bool BTree<T>::contains(const T &entry) const {
    int i = first_ge(data, data_count, entry);
    bool found = data[i] == entry;
    if(found) return true;
    else if(child_count == 0) return false;
    else return subset[i]->contains(entry);
}

template<class T>
T& BTree<T>::get(const T &entry) {
    if(!contains(entry)) insert(entry);
    return get_existing(entry);
}

template<class T>
T* BTree<T>::find(const T &entry) {
    int i = first_ge(data, data_count, entry);
    bool found = data[i] == entry;
    if(found) return &data[i];
    else if(child_count == 0) return NULL;
    else return subset[i]->find(entry);
}

template<class T>
int BTree<T>::size() const {
    return tree_size;
}

template<class T>
bool BTree<T>::empty() const {
    return data_count == 0;
}

template<class T>
void BTree<T>::print_tree(int level, ostream &outs) const {
    bool debug = false;

    //last childs index
    int index = child_count - 1;

    //print last child (if it exists)
    if(index >= 0) subset[index]->print_tree(level + data_count);

    //print this
    outs << setw(4 * level);
    if(debug)
        outs << "[" << "DC: " << data_count << "|CC: " << child_count << "] - ";
    print_array(data, data_count);

    //print other children (if they exist)
    index--;
    while(index >= 0){
        subset[index]->print_tree(level + data_count);
        index--;
    }
}

template<class T>
void BTree<T>::loose_insert(const T &entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(found){
        //data[i] += entry; //only use with pair/mpair struct as template
        //deal with duplicates
    } else {
        if(child_count == 0){
            insert_item(data, i, data_count, entry);
        }
        else {
            subset[i]->loose_insert(entry);
            if(subset[i]->data_count > MAXIMUM) fix_excess(i);
        }
    }
}

template<class T>
void BTree<T>::fix_excess(int i) {
    insert_item(subset, i + 1, child_count, new BTree<T>(dups_ok));
    split(subset[i]->data, subset[i]->data_count, subset[i + 1]->data, subset[i + 1]->data_count);
    split(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset, subset[i + 1]->child_count);
    T entry;
    detach_item(subset[i]->data, subset[i]->data_count, entry);
    ordered_insert(data, data_count, entry);
}

template<class T>
T& BTree<T>::get_existing(const T &entry) {
    int i = first_ge(data, data_count, entry);
    bool found = data[i] == entry;
    if(found) return data[i];
    else {
        assert(child_count > 0);
        return subset[i]->get_existing(entry);
    }
}

template<class T>
void BTree<T>::loose_remove(const T &entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(child_count == 0){
        if(found){
            delete_index(data, i, data_count);
        }
    } else {
        if(found){
            subset[i]->remove_biggest(data[i]);
        } else {
            subset[i]->loose_remove(entry);
        }
        if(subset[i]->data_count < MINIMUM) fix_shortage(i);
    }
}

template<class T>
void BTree<T>::fix_shortage(int i) {
    if(subset[i + 1] && subset[i + 1]->data_count > MINIMUM){
        rotate_left(i + 1);
    } else if(i > 0 && subset[i - 1]->data_count > MINIMUM){
        rotate_right(i - 1);
    } else if(i + 1 < child_count){
        merge_with_next_subset(i);
    } else {
        merge_with_next_subset(i - 1);
    }
}

template<class T>
void BTree<T>::remove_biggest(T &entry) {
    if(child_count > 0) {
        subset[child_count - 1]->remove_biggest(entry);
        if(subset[child_count - 1]->data_count < MINIMUM) fix_shortage(child_count - 1);
    } else {
        detach_item(data, data_count, entry);
    }
}

template<class T>
void BTree<T>::rotate_left(int i) {
    T middle = data[i - 1];
    delete_item(subset[i]->data, 0, subset[i]->data_count, data[i - 1]);
    attach_item(subset[i - 1]->data, subset[i - 1]->data_count, middle);
    if(subset[i]->child_count > 0){
        BTree<T>* carry = NULL;
        delete_item(subset[i]->subset, 0, subset[i]->child_count, carry);
        attach_item(subset[i - 1]->subset, subset[i - 1]->child_count, carry);
    }
}

template<class T>
void BTree<T>::rotate_right(int i) {
    T middle = data[i];
    detach_item(subset[i]->data, subset[i]->data_count, data[i]);
    insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, middle);
    if(subset[i]->child_count > 0){
        BTree<T>* carry = NULL;
        detach_item(subset[i]->subset, subset[i]->child_count, carry);
        insert_item(subset[i + 1]->subset, 0, subset[i + 1]->child_count, carry);
    }
}

template<class T>
void BTree<T>::merge_with_next_subset(int i) {
    T middle;
    delete_item(data, i, data_count, middle);
    attach_item(subset[i]->data, subset[i]->data_count, middle);
    merge(subset[i]->data, subset[i]->data_count, subset[i + 1]->data, subset[i + 1]->data_count);
    merge(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset, subset[i + 1]->child_count);

    delete_index(subset, i + 1, child_count);
}



#endif //BTREE_BTREE_H
