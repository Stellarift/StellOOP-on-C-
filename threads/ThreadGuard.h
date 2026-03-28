#pragma once

#include <thread>
#include <iostream>
using namespace std;

class ThreadGuard {
private:
    thread t;

public:
    template <typename Callable>
    ThreadGuard(Callable&& func) : t(forward<Callable>(func)) {
        cout << "ThreadGuard: поток запущен" << endl;
    }
    
    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;
    
    ~ThreadGuard() {
        if (t.joinable()) {
            t.join();
            cout << "ThreadGuard: поток завершён (join)" << endl;
        }
    }
};