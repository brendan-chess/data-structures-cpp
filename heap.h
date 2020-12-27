/*
 * Author: Brendan Chess
 * Project: Heap Class
 * Purpose: Implement a class that stores data in a heap structure
 * Notes: None
 */
#ifndef HEAP_CLASS_HEAP_H
#define HEAP_CLASS_HEAP_H

#include <iomanip>
using namespace std;

template <typename T>
class Heap {
public:
    void insert(const T& insert_me);
    T pop();

    Heap();
    Heap<T>&operator =(const Heap<T>& rhs);
    ~Heap();

    bool is_empty() const;
    unsigned int size() const;
    unsigned int capacity() const;
    friend ostream& operator << (ostream& outs, const Heap<T>& print_me){
        print_me.print_tree(outs);
        return outs;
    }

private:
    unsigned int how_many; //memory allocated (capacity)
    T* elements;
    unsigned int last_index; //last memory position used (size)

    void print_tree(ostream& outs = cout) const;
    void print_tree(unsigned int root, int level = 0, ostream& outs = cout) const;


    bool is_leaf(int i) const;
    unsigned int parent_index(int i) const;
    unsigned int left_child_index(int i)const;
    unsigned int right_child_index(int i) const;
    unsigned int big_child_index(int i) const;
    void swap_with_parent(int i);
};





template<typename T>
void Heap<T>::insert(const T &insert_me) {
    //expand size of elements array
    how_many *= 2;
    last_index++;

    T* temp = new T[how_many];
    for (int i = 0; i < how_many; ++i) {
        temp[i] = elements[i];
    }

    delete[] elements;
    elements = temp;

    //add the next element at the end
    elements[last_index] = insert_me;

    //reheapify upward
    int inserted_index = last_index;
    while(elements[parent_index(inserted_index)] < insert_me){
        swap_with_parent(inserted_index);
        inserted_index = parent_index(inserted_index);
    }
}





template<typename T>
T Heap<T>::pop() {
    assert(!is_empty() && "Cannot pop empty heap");
    //get root
    T root = elements[0];
    //replace root with last element
    elements[0] = elements[last_index];
    last_index--;

    //reheapify down
    int moving_index = 0;
    int bci = big_child_index(moving_index);
    while(elements[bci] > elements[moving_index] && bci <= last_index){
        moving_index = bci;
        swap_with_parent(bci);
        bci = big_child_index(moving_index);
    }

    return root;
}





template<typename T>
Heap<T>::Heap() {
    how_many = 1;
    elements = new T[how_many];
    last_index = -1;
}





template<typename T>
Heap<T> &Heap<T>::operator=(const Heap<T> &rhs) {
    delete[] elements;
    how_many = rhs.how_many;
    last_index = rhs.last_index;

    elements = new T[how_many];
    for (int i = 0; i <= last_index; ++i) {
        elements[i] = rhs.elements[i];
    }

    return *this;
}





template<typename T>
Heap<T>::~Heap() {
    delete[] elements;
}




template<typename T>
bool Heap<T>::is_empty() const {
    return last_index == -1;
}





template<typename T>
unsigned int Heap<T>::size() const {
    return last_index;
}





template<typename T>
unsigned int Heap<T>::capacity() const {
    return how_many;
}





template<typename T>
void Heap<T>::print_tree(ostream &outs) const {
    print_tree(0, 0, outs);
}





template<typename T>
void Heap<T>::print_tree(unsigned int root, int level, ostream &outs) const {
    assert(!is_empty() && "Cannot print empty heap");
    if(root <= last_index){
        print_tree(right_child_index(root), level + 1);
        outs << setw(4 * level) << "" << "[" << elements[root] << "]" << endl;
        print_tree(left_child_index(root), level + 1);
    }
}






template<typename T>
bool Heap<T>::is_leaf(int i) const {
    return left_child_index(i) > last_index && right_child_index(i) > last_index;
}






template<typename T>
unsigned int Heap<T>::parent_index(int i) const {
    return (i - 1) / 2;
}






template<typename T>
unsigned int Heap<T>::left_child_index(int i) const {
    return (2 * i) + 1;
}






template<typename T>
unsigned int Heap<T>::right_child_index(int i) const {
    return (2 * i) + 2;
}






template<typename T>
unsigned int Heap<T>::big_child_index(int i) const {
    T left_child = elements[left_child_index(i)];
    T right_child = elements[right_child_index(i)];
    if(left_child > right_child) return left_child_index(i);
    return right_child_index(i);
}






template<typename T>
void Heap<T>::swap_with_parent(int i) {
    T temp = elements[i];
    elements[i] = elements[parent_index(i)];
    elements[parent_index(i)] = temp;
}





#endif //HEAP_CLASS_HEAP_H
