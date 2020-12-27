/*
 * Author: Brendan Chess
 * Project: Timing Sort Functions
 * Purpose: Implement sorting functions and test the average times that they
 *  take to sort a large array of random integers
 * Notes: Bubble sort and insertion sort are not tested here because they are
 *  too slow
 */

#ifndef SORT_FUNCTIONS_SORT_FUNCTIONS_H
#define SORT_FUNCTIONS_SORT_FUNCTIONS_H

#include <cstdlib>

//- - array helpers - -//

template <class T>
void swap_elements(T a[], int i, int j){
    T temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

template <class T>
void shuffle(T a[], unsigned int  size){
    srand(time(0));
    for (int i = 0; i < size * 3; ++i) {
        swap_elements(a, rand() % size, rand() % size);
    }
}

template <class T>
void print_array(const T a[], int size, bool status_only = false){
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << *(a + i);
        if(i < size - 1) cout  << ", ";
    }
    cout << "]" << endl;
}

template <class T>
bool verify(const T a[], unsigned int  size){
    for (int i = 0; i < size - 1; ++i) {
        if(a[i] > a[i+1]) return false;
    }
    return true;
}

template <class T>
string verifystr(const T a[], unsigned int  size){
    for (int i = 0; i < size - 1; ++i) {
        if(a[i] > a[i+1]) return "NOT SORTED";
    }
    return "SORTED";
}

template <class T>
void print_array_segment(T a[], unsigned int start, unsigned int end){
    cout << "[";
    for (int i = start; i < end; ++i) {
        cout << *(a + i);
        if(i < end - 1) cout  << ", ";
    }
    cout << "]" << endl;
}

template <class T>
void copy_array(T dest[], const T src[], unsigned int size){
    for (int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
}

//- - sort function helpers - -//

template <class T>
void merge(T a[], size_t n1, size_t n2){
    T* temp;
    size_t copied = 0, copied1 = 0, copied2 = 0, i;

    temp = new T[n1 + n2];

    while((copied1 < n1) && (copied2 < n2)){
        if(a[copied1] < (a + n1)[copied2]) temp[copied++] = a[copied1++];
        else temp[copied++] = (a + n1)[copied2++];
    }

    while(copied1 < n1) temp[copied++] = a[copied1++];
    while(copied2 < n2) temp[copied++] = (a + n1)[copied2++];

    for (i = 0; i < n1 + n2; ++i) a[i] = temp[i];

    delete[] temp;
}

template <class T>
void partition(T a[], size_t size, size_t &pivot_index){
    T pivot = a[0]; //select first element as pivot
    int too_big_index = 1;
    int too_small_index = size - 1;

    while(too_big_index <= too_small_index){
        while(too_big_index < size && a[too_big_index] <= pivot){
            too_big_index++;
        }
        while(a[too_small_index] > pivot){
            too_small_index--;
        }
        if(too_big_index < too_small_index){
            swap_elements(a, too_big_index, too_small_index);
        }
    }

    pivot_index = too_small_index;
    swap_elements(a, pivot_index, 0);
    a[pivot_index] = pivot;
}

unsigned int left_child_index(int i) {
    return (2 * i) + 1;
}

unsigned int right_child_index(int i) {
    return (2 * i) + 2;
}

template <class T>
void make_heap(T a[], size_t size, unsigned int root){
    unsigned int largest = root;
    unsigned int left_child = left_child_index(root);
    unsigned int right_child = right_child_index(root);

    if(left_child < size && a[left_child] > a[largest])
        largest = left_child;

    if(right_child < size && a[right_child] > a[largest])
        largest = right_child;

    if(largest != root){
        swap_elements(a, root, largest);
        make_heap(a, size, largest);
    }
}

//- - sort functions - -//

template <class T>
void insertion_sort(T a[], unsigned int size){
    size_t sort_me, sorted_index;
    T next;

    for (sort_me = 1; sort_me < size; ++sort_me) {
        next = a[sort_me];
        sorted_index = sort_me;
        while(sorted_index > 0 && next < a[sorted_index - 1]){
            a[sorted_index] = a[sorted_index - 1];
            --sorted_index;
        }
        a[sorted_index] = next;
    }
}

template <class T>
void bubble_sort(T a[], unsigned int size){
    size_t i, j;

    for (i = 0; i < size - 1; ++i) {
        for (j = 0; j < size - i - 1; ++j) {
            if(a[j] > a[j+1]) swap_elements(a, j, j+1);
        }
    }
}

template <class T>
void quick_sort(T a[], unsigned int size){
    size_t pivot_index, n1, n2;

    //base case
    if(size > 1){
        partition(a, size, pivot_index);

        n1 = pivot_index;
        n2 = size - n1 - 1;

        quick_sort(a, n1);
        quick_sort((a + pivot_index + 1), n2);
    }
}

template <class T>
void merge_sort(T a[], unsigned int size){
    size_t n1, n2;

    if(size > 1){
        n1 = size / 2;
        n2 = size - n1;

        merge_sort(a, n1);
        merge_sort((a + n1), n2);

        merge(a, n1, n2);
    }
}

template <class T>
void heap_sort(T a[], unsigned int size){
    for (int i = size / 2 - 1; i >= 0; i--)
        make_heap(a, size, i);
    for (int i = size - 1; i >= 0; i--) {
        swap_elements(a, 0, i);
        make_heap(a, i, 0);
    }
}

#endif //SORT_FUNCTIONS_SORT_FUNCTIONS_H
