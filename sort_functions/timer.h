/*
 * Author: Brendan Chess
 * Project: Timing Sort Functions
 * Purpose: Implement sorting functions and test the average times that they
 *  take to sort a large array of random integers
 * Notes: Bubble sort and insertion sort are not tested here because they are
 *  too slow
 */

#ifndef SORT_FUNCTIONS_TIMER_H
#define SORT_FUNCTIONS_TIMER_H
#include <time.h>
using namespace std;

class timer{
private:
    clock_t _start;
    clock_t _stop;
public:
    timer():_start(clock()), _stop(clock()){}
    void start(){
        _start = clock();
    }
    void stop(){
        _stop = clock();
    }
    float duration(){
        return (float(_stop) - float(_start))/CLOCKS_PER_SEC;
    }
};
#endif //SORT_FUNCTIONS_TIMER_H
