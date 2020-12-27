//
// Created by Brendan Chess on 2/27/20.
//

#ifndef CAR_WASH_WASHING_H
#define CAR_WASH_WASHING_H

#include <cstdlib>

class bool_source{
public:
    bool_source(double p = 0.5);
    bool query() const;

private:
    double probability;
};

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

class washer{
public:
    washer(unsigned int s = 60);
    void one_second();
    void start_washing();
    bool is_busy() const { return (wash_time_left > 0); }

private:
    unsigned int seconds_for_wash;
    unsigned int wash_time_left;
};

#endif //CAR_WASH_WASHING_H
