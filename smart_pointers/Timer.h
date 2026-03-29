#pragma once

#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;

class Timer {
private:
    steady_clock::time_point startTime;

public:
    Timer();
    ~Timer();
    
    void reset();
    double elapsed() const;
};