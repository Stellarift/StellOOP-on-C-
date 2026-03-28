#pragma pnce

#include <iostream>
using namespace std;

//анонимное пространство имён (доступно только в этом файле)
namespace {
    int counter = 0;
    
    void normalize(double& value) {
        counter++;
        if (value < 0) value = 0;
        if (value > 1) value = 1;
        cout << "normalize() вызвана " << counter << " раз(а)" << endl;
    }
}

namespace Utils {
    double clamp(double val, double min, double max) {
        double normalized = val;
        normalize(normalized);
        
        return min + normalized * (max - min);
    }
    
    int getCounter() {
        return counter;
    }
}