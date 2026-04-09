#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace Railway {

class Route {
private:
    string from;
    string to;
    double distance;

public:
    Route(const string& f, const string& t, double d)
        : from(f), to(t), distance(d) {
        cout << "Route constructor: " << from << " -> " << to << " (" << distance << " km)" << endl;
    }
    
    Route(const Route& other)
        : from(other.from), to(other.to), distance(other.distance) {
        cout << "Route copy constructor" << endl;
    }
    
    ~Route() {
        cout << "Route destructor: " << from << " -> " << to << endl;
    }
    
    string getFrom() const { return from; }
    string getTo() const { return to; }
    double getDistance() const { return distance; }
    
    void print() const {
        cout << "Route: " << from << " -> " << to << ", distance=" << distance << " km" << endl;
    }
    
    void saveToFile(ofstream& file) const {
        file << from << " " << to << " " << distance << endl;
    }
    
    Route operator+(const Route& other) const {
        return Route(from + "-" + other.from, to + "-" + other.to, distance + other.distance);
    }
    
    friend ostream& operator<<(ostream& os, const Route& route) {
        os << route.from << " -> " << route.to << " (" << route.distance << " km)";
        return os;
    }
};

} // namespace Railway