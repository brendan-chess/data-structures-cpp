/*
 * Author: Brendan Chess
 * Project: Airport Simulation
 * Purpose: Simulate the traffic that flows in/out of an airport runway to
 *      find the average waiting times for planes landing and taking off, as
 *      well as the number of planes that passed through or crashed waiting
 * Notes: This simulation can use any number of runway strips
 */
#ifndef AIRPORT_SIMULATION_SIMULATION_H
#define AIRPORT_SIMULATION_SIMULATION_H

#include "../!includes/queue/Queue.h"
#include "airport.h"
//This class holds all variables and runs the simulation
class Simulation {
public:
    //Seconds needed for a plane to land or take off
    unsigned int time_to_land = 5;
    unsigned int time_to_take_off = 15;

    //Probability that a plane will get in queue to land or take off in any
    //given second
    double landing_probability = 0.10;
    double takeoff_probability = 0.08;

    //Seconds that a plane can stay in the air waiting to land before crashing
    unsigned int fuel_limit = 20;

    //Seconds to run the simulation for
    unsigned int simulation_time = 1440;

    unsigned int number_of_runways = 2;

    //Performs the simulation and prints results
    void run();
};

void Simulation::run() {
    //Queue to land
    Queue<unsigned int> landing_times;
    //Queue to take off
    Queue<unsigned int> takeoff_times;

    //Number of planes in the queues to land and take off
    unsigned int landing_queue_length = 0;
    unsigned int takeoff_queue_length = 0;

    //Number of planes that crashed
    unsigned int crashed = 0;

    //Generates the probability of a plane entering a queue
    bool_source landing(landing_probability);
    bool_source takeoff(takeoff_probability);

    averager landing_wait_times;
    averager takeoff_wait_times;

    unsigned int current_second;

    //Stores timestamps of planes that enter the runway
    unsigned int next;

    runway strips[number_of_runways];

    //Initialize array of runways
    for(int strip = 0; strip < number_of_runways; ++strip){
        strips[strip] = runway(time_to_land, time_to_take_off);
    }

    //Print simulation variables
    cout << "==============================================" << endl;
    cout << "Seconds to take off: " << time_to_take_off << endl;
    cout << "Seconds to land: " << time_to_land << endl;
    cout << "Probability of landing: " << landing_probability << endl;
    cout << "Probability of takeoff: " << takeoff_probability << endl;
    cout << "Fuel time to crash: " << fuel_limit << endl;
    cout << "Total simulation seconds: " << simulation_time << endl;
    cout << "Number of runways: " << number_of_runways << endl;
    cout << "----------------------------------------------" << endl;

    //Drive the simulation
    for(current_second = 1; current_second <= simulation_time; ++current_second){
        //Check if a new plane enters the queue to land
        if(landing.query()){
            landing_times.push(current_second);
            landing_queue_length++;
        }

        //Check if a new plane enters the queue to take off
        if(takeoff.query()){
            takeoff_times.push(current_second);
            takeoff_queue_length++;
        }

        //Operate on each runway
        for(int strip = 0; strip < number_of_runways; ++strip){
            //Let planes land if the current runway is not busy
            if((!strips[strip].is_busy()) && (!landing_times.empty())){
                next = landing_times.front();
                landing_times.pop();
                landing_queue_length--;
                landing_wait_times.next_number(current_second - next);
                strips[strip].start_landing();
            }

            //Let planes take off if the current runway is not busy
            if((!strips[strip].is_busy()) && (!takeoff_times.empty())){
                next = takeoff_times.front();
                takeoff_times.pop();
                takeoff_queue_length--;
                takeoff_wait_times.next_number(current_second - next);
                strips[strip].start_takeoff();
            }

            //Advance the current runway by one second
            strips[strip].one_second();
        }

        //Crash next plane in landing queue if it ran out of fuel
        if(!landing_times.empty()){
            next = landing_times.front();
            if(current_second - next >= fuel_limit){
                landing_times.pop();
                crashed++;
            }
        }
    }

    //Print simulation results
    cout << landing_wait_times.how_many_numbers() << " landed" << endl;
    cout << takeoff_wait_times.how_many_numbers() << " took off" << endl;
    cout << crashed << " crashed" << endl;
    cout << "Average waiting time to land: " << landing_wait_times.average() << endl;
    cout << "Average waiting time to take off: " << takeoff_wait_times.average() << endl;
    cout << "Planes in landing queue: " << landing_queue_length << endl;
    cout << "Planes in takeoff queue: " << takeoff_queue_length << endl;
    cout << "==============================================" << endl;
}

#endif //AIRPORT_SIMULATION_SIMULATION_H
