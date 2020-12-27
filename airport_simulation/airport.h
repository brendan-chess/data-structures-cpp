/*
 * Author: Brendan Chess
 * Project: Airport Simulation
 * Purpose: Simulate the traffic that flows in/out of an airport runway to
 *      find the average waiting times for planes landing and taking off, as
 *      well as the number of planes that passed through or crashed waiting
 * Notes: This simulation can use any number of runway strips
 */
#ifndef AIRPORT_SIMULATION_AIRPORT_H
#define AIRPORT_SIMULATION_AIRPORT_H

#include <cstdlib>

//Generates a boolean value according to a given probability
class bool_source{
public:
    bool_source(double p = 0.5);
    bool query() const;

private:
    double probability;
};

//Stores a sum of numbers and returns the count and average
class averager{
public:
    averager();
    void next_number(double value);
    std::size_t how_many_numbers() const { return count; };
    double average() const;

private:
    std::size_t count;
    double sum;
};

//Keeps track of planes landing and taking off
class runway{
public:
    runway(unsigned int landing = 10, unsigned int takeoff = 10);
    void one_second();
    void start_landing();
    void start_takeoff();
    bool is_busy() const { return (use_time_left > 0); }

private:
    unsigned int seconds_for_landing;
    unsigned int seconds_for_takeoff;
    unsigned int use_time_left;
};

#endif //AIRPORT_SIMULATION_AIRPORT_H
