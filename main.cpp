/*
 * Author: Brendan Chess
 * Project: Priority Queue
 * Purpose: Use a heap to implement a queue that pops items that have the
 *      highest priority value as opposed to the usual FIFO structure
 * Notes: Duplicates are allowed in this structure
 */
#include <iostream>
#include "PQueue.h"

int main() {
    srand(time(0));

    PQueue<int> pq;
    for (int i = 0; i < 100; i++) {
        pq.insert(rand() % 1000 + 1, rand() % 10 + 1);
    }

    cout << pq << endl;

    for (int i = 0; i < 100; i++) {
        cout << pq.pop() << endl;
    }
}
