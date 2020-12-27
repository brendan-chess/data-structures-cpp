/*
 * Author: Brendan Chess
 * Project: Airport Simulation
 * Purpose: Simulate the traffic that flows in/out of an airport runway to
 *      find the average waiting times for planes landing and taking off, as
 *      well as the number of planes that passed through or crashed waiting
 * Notes: This simulation can use any number of runway strips
 */
#include <cassert>
#include <cstdlib>
#include "airport.h"
using namespace std;

//Set the probability of the boolean generator
bool_source::bool_source(double p) {
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
}

//Get a boolean value
bool bool_source::query() const {
    return (rand() < probability * RAND_MAX);
}

averager::averager(){
    count = 0;
    sum = 0;
}

void averager::next_number(double value) {
    ++count;
    sum += value;
}

double averager::average() const {
    assert(how_many_numbers() > 0);
    return sum / count;
}

//Initializes duration of landing and takeoff operations on the runway
runway::runway(unsigned int landing, unsigned int takeoff){
    seconds_for_landing = landing;
    seconds_for_takeoff = takeoff;
    use_time_left = 0;
}

//Advance the simulation by one second
void runway::one_second() {
    if(is_busy())
        --use_time_left;
}

//Use the runway to land a plane
void runway::start_landing() {
    assert(!is_busy());
    use_time_left = seconds_for_landing;
}

//Use the runway to let a plane take off
void runway::start_takeoff() {
    assert(!is_busy());
    use_time_left = seconds_for_takeoff;
}