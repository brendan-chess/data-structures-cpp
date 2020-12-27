#include <cassert>
#include <cstdlib>
#include "washing.h"
using namespace std;

bool_source::bool_source(double p) {
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
}

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

washer::washer(unsigned int s){
    seconds_for_wash = s;
    wash_time_left = 0;
}

void washer::one_second() {
    if(is_busy())
        --wash_time_left;
}

void washer::start_washing() {
    assert(!is_busy());
    wash_time_left = seconds_for_wash;
}