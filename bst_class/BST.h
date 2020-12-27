/*
 * Author: Brendan Chess
 * Project: Binary Search Tree Class
 * Purpose: Use functions that perform operations on binary search trees to
 *      implement a binary search tree class
 * Notes: None
 */
#ifndef BST_CLASS_BST_H
#define BST_CLASS_BST_H

using namespace std;

#include <iostream>
#include "../!includes/bst_functions/tree_node.h"
#include "../!includes/bst_functions/bst_functions.h"

template <typename T>
class BST{
public:
    BST();
    BST(const T* sorted_list, int size=-1);

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    BST(const BST<T>& copy_me);
    BST<T>& operator =(const BST<T>& rhs);
    ~BST();

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me);
    void erase(const T& target);
    bool search(const T& target, tree_node<T>* & found_ptr);
    void clear();

    friend ostream& operator <<(ostream& outs, const BST<T>& tree){
        tree_print(tree.root, 0, outs);
        return outs;
    }

    BST<T>& operator +=(const BST<T>& rhs);
private:
    tree_node<T>* root;
};



template<typename T>
BST<T>::BST() {
    root = NULL;
}



template<typename T>
BST<T>::BST(const T *sorted_list, int size) {
    root = tree_from_sorted_list(sorted_list, 0, size - 1);
}



template<typename T>
BST<T>::BST(const BST<T> &copy_me) {
    root = tree_copy(copy_me.root);
}



template<typename T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {
    root = tree_copy(rhs.root);
    return *this;
}



template<typename T>
BST<T>::~BST() {
    tree_clear(root);
}



template<typename T>
void BST<T>::insert(const T &insert_me) {
    tree_insert(root, insert_me);
}



template<typename T>
void BST<T>::erase(const T &target) {
    tree_erase(root, target);
}



template<typename T>
bool BST<T>::search(const T &target, tree_node<T> *&found_ptr) {
    return tree_search(root, target, found_ptr);
}



template<typename T>
BST<T> &BST<T>::operator+=(const BST<T> &rhs) {
    tree_add(root, rhs.root);
    return *this;
}

template<typename T>
void BST<T>::clear() {
    tree_clear(root);
}


#endif //BST_CLASS_BST_H
