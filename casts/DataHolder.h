#pragma once

#include <iostream>
#include <vector>
using namespace std;

class DataHolder {
private:
    vector<int> data;

public:
    DataHolder(const vector<int>& d) : data(d) {}
    
    const vector<int>& getData() const {
        return data;
    }
    
    void print() const {
        cout << "Data: ";
        for (int val : data) {
            cout << val << " ";
        }
        cout << endl;
    }
};