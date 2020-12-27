/*
 * Author: Brendan Chess
 * Project: AVL Tree Class
 * Purpose: Implement a binary search tree that is always balanced
 * Notes: None
 */
#ifndef BST_FUNCTIONS_BST_FUNCTIONS_H
#define BST_FUNCTIONS_BST_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include "tree_node.h"
using namespace std;


template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me){
    if(root == NULL){
        root = new tree_node<T>(insert_me);
    } else if(insert_me < root->_item){
        tree_insert(root->_left, insert_me);
    } else {
        tree_insert(root->_right, insert_me);
    }
    root->update_height();
    root = rotate(root);
}


template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target){
    if(!root){
        return nullptr;
    } else if(root->_item == target){
        return root;
    } else if(target < root->_item){
        return tree_search(root->_left, target);
    } else if(target >= root->_item){
        return tree_search(root->_right, target);
    }
}


template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr){
    found_ptr = tree_search(root, target);
    if(!found_ptr) return false;
    return true;
}


template<typename T>
void tree_print(tree_node<T>* root, int level=0,
                ostream& outs=cout){
    if(root){
        tree_print(root->_right, level + 1);
        outs << setw(4 * level) << "" << "[" << root->_item << "]" << endl;
        tree_print(root->_left, level + 1);
    }
}


template<typename T>       //prints details info about each node
void tree_print_debug(tree_node<T>* root, int level=0,
                      ostream& outs=cout){
    if(root){
        tree_print_debug(root->_right, level + 1);
        outs << setw(4 * level) << "" << "[" << root->_item
            << "|H:" << root->_height
            << "|BF:" << root->balance_factor()
            << "]" << endl;
        tree_print_debug(root->_left, level + 1);
    }
}


template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root){
    if(root) {
        tree_clear(root->_left);
        tree_clear(root->_right);
        delete root;
        root = NULL;
    }
}


template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target){
    if(!root){
        return false;
    } else if(root->_item < target){
        tree_erase(root->_right, target);
    } else if(root->_item > target){
        tree_erase(root->_left, target);
    } else if(root->_item == target){
        if(!root->_left){
            tree_node<T>* temp = root;
            root = root->_right;
            delete temp;
        } else {
            T max_value;
            tree_remove_max(root->_left, max_value);
            root->_item = max_value;
        }
        return true;
    }
}


template <typename T>       //erase rightmost node from the tree
// store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value){
    if(!root->_right){
        tree_node<T>* temp = root;
        max_value = temp->_item;
        root = root->_left;
        delete temp;
    } else {
        tree_remove_max(root->_right, max_value);
    }
}


template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root){
    if(root) {
        return new tree_node<T>(root->_item,
                tree_copy(root->_left),
                tree_copy(root->_right));
    } else return NULL;
}


template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int start, int end){
    if(start > end) return NULL;

    int mid = (start + end) / 2;

    tree_node<T>* root = new tree_node<T>(a[mid]);

    root->_left = tree_from_sorted_list(a, start, mid - 1);
    root->_right = tree_from_sorted_list(a, mid + 1, end);

    return root;
}


template <typename T>
int tree_size(const tree_node<T>* root){
    if(root) { return tree_size(root->_left) + tree_size(root->_right) + 1; }
    else return 0;
}


template <typename T>       // tree -> sorted array
int tree_to_sorted_list(const tree_node<T>* root, T* list, int index = 0){
    if(root){
        index = tree_to_sorted_list(root->_left, list, index);
        list[index++] = root->_item;
        index = tree_to_sorted_list(root->_right, list, index);
    }
    return index;
}


template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src){
    T dest_size = tree_size(dest);
    T src_size = tree_size(src);

    T* dest_arr = new T[tree_size(dest)];
    T* src_arr = new T[tree_size(src)];

    tree_to_sorted_list(dest, dest_arr);
    tree_to_sorted_list(src, src_arr);

    T* union_arr = new T[dest_size + src_size];
    int u = 0;

    for (u = 0; u < dest_size; ++u) {
        union_arr[u] = dest_arr[u];
    }
    for (int s = 0; s < src_size; ++s) {
        bool duplicate = false;
        for (int d = 0; d < dest_size; ++d) {
            if(src_arr[s] == dest_arr[d]){
                duplicate = true;
                break;
            }
        }
        if(!duplicate) union_arr[u++] = src_arr[s];
    }

    dest = tree_from_sorted_list(union_arr, 0, u - 1);
}


template <typename T>
tree_node<T>* rotate_right(tree_node<T>* &root){
    tree_node<T>* temp = root->_left;
    root->_left = temp->_right;
    temp->_right = root;
    root->update_height();
    temp->update_height();
    return temp;
}


template <typename T>
tree_node<T>* rotate_left(tree_node<T>* &root){
    tree_node<T>* temp = root->_right;
    root->_right = temp->_left;
    temp->_left = root;
    root->update_height();
    temp->update_height();
    return temp;
}


template <typename T>
tree_node<T>* rotate(tree_node<T>* & root){
    if(root->balance_factor() == 2){
        if(root->_right->balance_factor() == -1){
            root->_right = rotate_right(root->_right);
            root = rotate_left(root);
        } else {
            root = rotate_left(root);
        }
    } else if(root->balance_factor() == -2){
        if(root->_left->balance_factor() == 1){
            root->_left = rotate_left(root->_left);
            root = rotate_right(root);
        } else {
            root = rotate_right(root);
        }
    }
    return root;
}


#endif //BST_FUNCTIONS_BST_FUNCTIONS_H
