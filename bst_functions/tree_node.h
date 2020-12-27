/*
 * Author: Brendan Chess
 * Project: AVL Tree Class
 * Purpose: Implement a binary search tree that is always balanced
 * Notes: None
 */
#ifndef BST_FUNCTIONS_TREE_NODE_H
#define BST_FUNCTIONS_TREE_NODE_H

using namespace std;

template <typename T>
struct tree_node{
    T _item;
    tree_node<T>* _left = NULL;
    tree_node<T>* _right = NULL;
    int _height = 0;
    int balance_factor(){
        int left_height, right_height;

        if(_left == NULL) { left_height = -1; }
        else { left_height = _left->_height; }

        if(_right == NULL) { right_height = -1; }
        else { right_height = _right->_height; }

        return right_height - left_height;
    }

    int height(){
        int left_height, right_height;

        if(_left == NULL) { left_height = -1; }
        else { left_height = _left->_height; }

        if(_right == NULL) { right_height = -1; }
        else { right_height = _right->_height; }

        return 1 + max(left_height, right_height);
    }
    int update_height(){
        _height = height();
        return _height;
    }

    tree_node(T item=T(), tree_node* left=NULL,
              tree_node* right=NULL):
            _item(item), _left(left), _right(right)
    {

    }
    friend ostream& operator <<(ostream& outs,
                                const tree_node<T>& t_node){
        outs<<"|"<<t_node._item<<"|";
    }
};

#endif //BST_FUNCTIONS_TREE_NODE_H
