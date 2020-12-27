#include <iostream>
#include "washing.h"
#include "../!includes/queue/Queue.h"

void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time);

int main() {
    car_wash_simulate(240, 0.0025, 6000);
}

void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time){
    Queue<unsigned int> arrival_times;
    unsigned int next;
    bool_source arrival(arrival_prob);
    washer machine(wash_time);
    averager wait_times;
    unsigned int current_second;

    cout << "Seconds to wash one car: " << wash_time << endl;
    cout << "Probability of customer arrival during a second: " << arrival_prob << endl;
    cout << "Total simulation seconds: " << total_time << endl;

    for(current_second = 1; current_second <= total_time; ++current_second){
        if(arrival.query()){
            arrival_times.push(current_second);
        }

        if((!machine.is_busy()) && (!arrival_times.empty())){
            next = arrival_times.front();
            arrival_times.pop();
            wait_times.next_number(current_second - next);
            machine.start_washing();
        }

        machine.one_second();
    }

    cout << "Customers served: " << wait_times.how_many_numbers() << endl;
    if(wait_times.how_many_numbers() > 0)
        cout << "Average wait: " << wait_times.average() << " sec" << endl;
}