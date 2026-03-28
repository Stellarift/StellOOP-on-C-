#pragma once

#include <mutex>
#include <iostream>
using namespace std;

class AtomicCounter {
private:
    int value;
    mutable mutex mtx;  // mutable для использования в const методах

public:
    AtomicCounter(int initial = 0) : value(initial) {}
    
    void increment() {
        lock_guard<mutex> lock(mtx);
        ++value;
    }
    
    void decrement() {
        lock_guard<mutex> lock(mtx);
        --value;
    }
    
    int get() const {
        lock_guard<mutex> lock(mtx);
        return value;
    }
};