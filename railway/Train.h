#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
using namespace std;

namespace Railway {

class Train {
protected:
    string number;
    string model;
    int wagons;
    static int trainsSent;

public:
    Train(const string& num, const string& mdl, int w)
        : number(num), model(mdl), wagons(w) {
        cout << "Train constructor: " << number << endl;
    }
    
    Train(const Train& other)
        : number(other.number), model(other.model), wagons(other.wagons) {
        cout << "Train copy constructor: " << number << endl;
    }
    
    explicit Train(const string& num) : number(num), model("Unknown"), wagons(0) {
        cout << "Explicit Train constructor: " << number << endl;
    }
    
    virtual ~Train() {
        cout << "Train destructor: " << number << endl;
    }
    
    static int getTrainsSent() { return trainsSent; }
    static void incrementTrainsSent() { trainsSent++; }
    
    string getNumber() const { return number; }
    string getModel() const { return model; }
    int getWagons() const { return wagons; }
    
    virtual void print() const = 0;
    virtual void saveToFile(ofstream& file) const = 0;
    
    friend ostream& operator<<(ostream& os, const Train& train) {
        os << "Train " << train.number << " (" << train.model << ", " << train.wagons << " wagons)";
        return os;
    }
};

int Train::trainsSent = 0;

// производный класс PassengerTrain
class PassengerTrain : public Train {
private:
    int seats;
    int soldTickets;

public:
    PassengerTrain(const string& num, const string& mdl, int w, int s)
        : Train(num, mdl, w), seats(s), soldTickets(0) {
        cout << "PassengerTrain constructor: " << number << ", seats=" << seats << endl;
    }
    
    void print() const override {
        cout << "PassengerTrain: " << number << ", model=" << model
             << ", wagons=" << wagons << ", seats=" << seats
             << ", sold=" << soldTickets << endl;
    }
    
    void saveToFile(ofstream& file) const override {
        file << "P " << number << " " << model << " " << wagons << " " << seats << " " << soldTickets << endl;
    }
    
    void sellTicket() {
        if (soldTickets >= seats) {
            throw runtime_error("Нет свободных мест в поезде " + number);
        }
        soldTickets++;
        cout << "Продан билет на поезд " << number << ". Продано: " << soldTickets << "/" << seats << endl;
    }
    
    int getSeats() const { return seats; }
    int getSoldTickets() const { return soldTickets; }
};

// производный класс FreightTrain
class FreightTrain : public Train {
private:
    double capacity;

public:
    FreightTrain(const string& num, const string& mdl, int w, double cap)
        : Train(num, mdl, w), capacity(cap) {
        cout << "FreightTrain constructor: " << number << ", capacity=" << capacity << endl;
    }
    
    void print() const override {
        cout << "FreightTrain: " << number << ", model=" << model
             << ", wagons=" << wagons << ", capacity=" << capacity << " tons" << endl;
    }
    
    void saveToFile(ofstream& file) const override {
        file << "F " << number << " " << model << " " << wagons << " " << capacity << endl;
    }
    
    double getCapacity() const { return capacity; }
};

} // namespace Railway