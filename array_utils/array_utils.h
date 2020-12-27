/*
 * Author: Brendan Chess
 * Project: B+Tree Map & MultiMap
 * Purpose: Implement Map and MultiMap classes based on a B+Tree
 * Notes: Depends on B+Tree class and array util functions
 */
#ifndef ARRAY_UTILS_ARRAY_UTILS_H
#define ARRAY_UTILS_ARRAY_UTILS_H

#include <iostream>
using namespace std;

//returns a or b, whichever is larger
template <class T>
T maximal(const T& a, const T& b){
    if(a > b) return a;
    else if(b > a) return b;
    else return NULL; //what do we return if they are equal
}

template <class T>
void _swap(T& a, T& b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

//returns the index of the largest item in data
template <class T>
int index_of_maximal(T data[ ], int n){
    int largest_index = 0;
    for (int i = 1; i < n; ++i) {
        if(data[i] > data[largest_index]) largest_index = i;
    }
    return largest_index;
}



//return the index of the first element in data that is not less than entry
template <class T>
int first_ge(const T data[ ], int n, const T& entry){
    for (int i = 0; i < n; ++i) {
        if(!(data[i] < entry)) return i;
    }
    return n;
}

//insert entry at the end of data
template <class T>
void attach_item(T data[ ], int& n, const T& entry){
    data[n] = entry;
    n++;
}

//insert entry at index i in data of size n
template <class T>
void insert_item(T data[ ], int i, int& n, T entry){
    for (int j = n; j > i; --j) {
        data[j] = data[j-1];
    }

    data[i] = entry;
    n++;
}

//insert entry into the sorted array data of size n
template <class T>
void ordered_insert(T data[ ], int& n, T entry){
    int index = first_ge(data, n, entry);
    insert_item(data, index, n, entry);
}

//remove the last element in data of size n and set entry to that value
template <class T>
void detach_item(T data[ ], int& n, T& entry){
    n--;
    entry = data[n];
    data[n] = T();
}

//delete element at index i in data of size n and set entry to that value
template <class T>
void delete_item(T data[ ], int i, int& n, T& entry){
    entry = data[i];
    data[i] = T();

    n--;

    for (int j = i; j < n; ++j) {
        data[j] = data[j + 1];
    }
}

//delete element at index i in data of size n
template <class T>
void delete_index(T data[ ], int i, int& n){
    data[i] = T();

    n--;

    for (int j = i; j < n; ++j) {
        data[j] = data[j + 1];
    }
}

//add data2 to the end of data1 with sizes n2 and n1 respectively
template <class T>
void merge(T data1[ ], int& n1, T data2[ ], int& n2){
    for (int i = n1; i < n1 + n2; ++i) {
        data1[i] = data2[i - n1];
    }
    n1 += n2;
}

//splits data1 in half, puts right half into data2
template <class T>
void split(T data1[ ], int& n1, T data2[ ], int& n2){
    int i, halfway = n1/2;
    if(n1 % 2 == 1) halfway++;
    for (i = halfway; i < n1; ++i) {
        data2[i - halfway] = data1[i];
        data1[i] = T();
    }
    n1 = halfway;
    n2 = i - n1;
}

//copy src into dest
template <class T>
void copy_array(T dest[], const T src[],
                int& dest_size, int src_size){
    for (int i = 0; i < dest_size; ++i) {
        dest[i] = T();
    }

    dest_size = src_size;

    for (int j = 0; j < dest_size; ++j) {
        dest[j] = src[j];
    }
}

template <class T>
void print_array(const T data[], int n, int pos = -1){
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << data[i];
        if(i < n - 1) cout << ", ";
    }
    cout << "]\n";
}

//is item greater than all elements in data
template <class T>
bool is_gt(const T data[], int n, const T& item){
    for (int i = 0; i < n; ++i) {
        if(item <= data[i]) return false;
    }
    return true;
}

//is item less than or equal to all elements in data
template <class T>
bool is_le(const T data[], int n, const T& item){
    for (int i = 0; i < n; ++i) {
        if(data[i] < item) return false;
    }
    return true;
}

#endif //ARRAY_UTILS_ARRAY_UTILS_H
