/*
 * Author: Brendan Chess
 * Project: Stack and Queue
 * Purpose: Implement a stack data structure based on a doubly linked list
 * Notes: None
 */

#ifndef STACK_H
#define STACK_H

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <class T>
class Stack{
public:
    Stack():_top(NULL){}

    ~Stack(){
        delete_all(_top);
    }
    Stack(const Stack<T>& other){
        copy_list(other._top, _top);
    }
    Stack<T>& operator =(const Stack<T>& rhs){
        copy_list(rhs._top, _top);
        return *this;
    }

    void push(T item){
        insert_head(_top ,item);
    }
    T pop(){
        return delete_head(_top);
    }
    T top(){
        return _top->_item;
    }
    bool empty(){
        if(_top == NULL) return true;
        return false;
    }
    friend ostream& operator << (ostream& outs, const Stack& s){
        return print_list(s._top, outs);
    }
private:
    node<T>* _top;
};

#endif //_STACK_H
