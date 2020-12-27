/*
 * Author: Brendan Chess
 * Project: Timing Sort Functions
 * Purpose: Implement sorting functions and test the average times that they
 *  take to sort a large array of random integers
 * Notes: Bubble sort and insertion sort are not tested here because they are
 *  too slow
 */

#include <iostream>
#include "timer.h"
#include "sort_functions.h"

float time_sort_routine(int a[], unsigned int  size,
                        void (*f)(int *, unsigned int)){
    timer t;
    t.start();
    f(a, size);
    t.stop();
    return t.duration();
}

void test_sort_function(void (*func)(int *, unsigned int), string fname){
    const int SIZE = 50000, LOOPS = 500;
    int numbers[SIZE];
    float average = 0;

    cout << "testing " << fname << "..." << endl;

    for (int i = 0; i < LOOPS; ++i) {
        //fill array
        for (int j = 0; j < SIZE; ++j) {
            numbers[j] = j;
        }

        shuffle(numbers, SIZE);

        //sort the array and record the time taken
        average += time_sort_routine(numbers, SIZE, func);
    }

    average /= LOOPS;

    //output results
    cout << fname << "(" << SIZE << ") average time: " << average << " seconds" << endl;
}

int main() {
    test_sort_function(merge_sort, "merge_sort");
    test_sort_function(quick_sort, "quick_sort");
    test_sort_function(heap_sort, "heap_sort");
}
