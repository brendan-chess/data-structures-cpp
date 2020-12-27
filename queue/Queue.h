/*
 * Author: Brendan Chess
 * Project: Stack and Queue
 * Purpose: Implement a queue data structure based on a doubly linked list
 * Notes: None
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <class T>
class Queue{
public:
    Queue():_head(NULL), _tail(NULL){}

    ~Queue(){
        delete_all(_head);
    }
    Queue(const Queue<T>& other){
        copy_list(other._head, _head);
    }
    Queue<T> &operator =(const Queue& rhs){
        copy_list(rhs._head, _head);
        return *this;
    }

    void push(T item){
        _tail = insert_after(_head, _tail, item);
    }
    T pop(){
        return delete_head(_head);
    }
    bool empty(){
        if(_head == NULL) return true;
        return false;
    }
    T front(){
        return _head->_item;
    }

    friend ostream& operator <<(ostream& outs, const Queue& q){
        return print_list(q._head, outs);
    }


private:
    node<T>* _head;
    node<T>* _tail;
};

#endif //QUEUE_H
