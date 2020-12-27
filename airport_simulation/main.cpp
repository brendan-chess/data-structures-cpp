/*
 * Author: Brendan Chess
 * Project: Airport Simulation
 * Purpose: Simulate the traffic that flows in/out of an airport runway to
 *      find the average waiting times for planes landing and taking off, as
 *      well as the number of planes that passed through or crashed waiting
 * Notes: This simulation can use any number of runway strips
 */
#include <iostream>
#include "./Simulation.h"

int main() {
    srand(time(0));
    Simulation s;
    s.run();
}
