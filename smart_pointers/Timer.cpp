#include "Timer.h"
#include <iostream>
using namespace std;

Timer::Timer() {
    startTime = steady_clock::now();
    cout << "Timer: запущен" << endl;
}

Timer::~Timer() {
    auto endTime = steady_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime).count();
    cout << "Timer: остановлен, прошло " << duration << " мс" << endl;
}

void Timer::reset() {
    startTime = steady_clock::now();
    cout << "Timer: сброшен" << endl;
}

double Timer::elapsed() const {
    auto now = steady_clock::now();
    return duration_cast<milliseconds>(now - startTime).count();
}