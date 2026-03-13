#include <iostream>
using namespace std;

template <typename T>
T min2(T a, T b) {
    return (a < b) ? a : b;
}

void demoTask4() {
    cout << "\nЗадание 4: Минимум из двух" << endl;
    
    cout << "min(5, 10) = " << min2(5, 10) << endl;
    cout << "min(3.14, 2.71) = " << min2(3.14, 2.71) << endl;
    cout << "min('a', 'z') = " << min2('a', 'z') << endl;
}