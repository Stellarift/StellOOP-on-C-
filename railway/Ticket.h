#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "Train.h"
using namespace std;

namespace Ticketing {

using namespace Railway;

class Ticket {
private:
    string passenger;
    string trainNumber;
    int seat;
    weak_ptr<Train> trainWeak;

public:
    Ticket(const string& pass, const string& trainNum, int s, shared_ptr<Train> train)
        : passenger(pass), trainNumber(trainNum), seat(s), trainWeak(train) {
        cout << "Ticket created: " << passenger << " -> " << trainNumber << ", seat " << seat << endl;
    }
    
    void print() const {
        cout << "Ticket: passenger=" << passenger << ", train=" << trainNumber << ", seat=" << seat << endl;
    }
    
    void saveToFile(ofstream& file) const {
        file << passenger << " " << trainNumber << " " << seat << endl;
    }
    
    string getTrainNumber() const { return trainNumber; }
    string getPassenger() const { return passenger; }
    int getSeat() const { return seat; }
};

} // namespace Ticketing