/*
 * Author: Brendan Chess
 * Project: Priority Queue
 * Purpose: Use a heap to implement a queue that pops items that have the
 *      highest priority value as opposed to the usual FIFO structure
 * Notes: Duplicates are allowed in this structure
 */
#ifndef PRIORITY_QUEUE_PQUEUE_H
#define PRIORITY_QUEUE_PQUEUE_H

#include <iostream>
#include "heap.h"
using namespace std;

template <typename T>
struct info{
    T item;
    int priority{};

    info()= default;

    info(T i, int p){
        item = i;
        priority = p;
    }

    friend ostream& operator <<(ostream& outs, const info<T>& print_me){
        outs << "Item:" << print_me.item << "|Priority:" << print_me.priority;
        return outs;
    }

    friend bool operator <(const info<T>& lhs, const info<T>& rhs){
        return lhs.priority < rhs.priority;
    }
};



template <typename T>
class PQueue
{
public:
    PQueue()= default;

    bool insert(const T& value, int p);
    T pop();

    bool is_empty() const;
    int size() const;
    void print_tree() const;
    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me){
        outs << print_me.heap;
        return outs;
    }

private:
    Heap<info<T> > heap;

};

template<typename T>
bool PQueue<T>::insert(const T &value, int p) {
    heap.insert(info<T>(value, p));
    return true;
}

template<typename T>
int PQueue<T>::size() const {
    return heap.size();
}

template<typename T>
bool PQueue<T>::is_empty() const {
    return heap.is_empty();
}

template<typename T>
T PQueue<T>::pop() {
    return heap.pop().item;
}

template<typename T>
void PQueue<T>::print_tree() const {
    cout << heap;
}

#endif //PRIORITY_QUEUE_PQUEUE_H
