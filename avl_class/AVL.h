/*
 * Author: Brendan Chess
 * Project: AVL Tree Class
 * Purpose: Implement a binary search tree that is always balanced
 * Notes: None
 */
#ifndef AVL_CLASS_AVL_H
#define AVL_CLASS_AVL_H

using namespace std;

#include <iostream>
#include "../!includes/bst_functions/tree_node.h"
#include "../!includes/bst_functions/bst_functions.h"

template <typename T>
class AVL{
public:
    AVL();
    AVL(const T* sorted_list, int size=-1);

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    AVL(const AVL<T>& copy_me);
    AVL<T>& operator =(const AVL<T>& rhs);
    ~AVL();

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me);
    void erase(const T& target);
    bool search(const T& target, tree_node<T>* & found_ptr);
    void clear();

    friend ostream& operator <<(ostream& outs, const AVL<T>& tree){
        tree_print(tree.root, 0, outs);
        return outs;
    }

    AVL<T>& operator +=(const AVL<T>& rhs);
private:
    tree_node<T>* root;
};



template<typename T>
AVL<T>::AVL() {
    root = NULL;
}



template<typename T>
AVL<T>::AVL(const T *sorted_list, int size) {
    root = tree_from_sorted_list(sorted_list, 0, size - 1);
}



template<typename T>
AVL<T>::AVL(const AVL<T> &copy_me) {
    root = tree_copy(copy_me.root);
}



template<typename T>
AVL<T> &AVL<T>::operator=(const AVL<T> &rhs) {
    root = tree_copy(rhs.root);
    return *this;
}



template<typename T>
AVL<T>::~AVL() {
    tree_clear(root);
}



template<typename T>
void AVL<T>::insert(const T &insert_me) {
    tree_insert(root, insert_me);
}



template<typename T>
void AVL<T>::erase(const T &target) {
    tree_erase(root, target);
}



template<typename T>
bool AVL<T>::search(const T &target, tree_node<T> *&found_ptr) {
    return tree_search(root, target, found_ptr);
}



template<typename T>
AVL<T> &AVL<T>::operator+=(const AVL<T> &rhs) {
    tree_add(root, rhs.root);
    return *this;
}

template<typename T>
void AVL<T>::clear() {
    tree_clear(root);
}


#endif //AVL_CLASS_AVL_H
