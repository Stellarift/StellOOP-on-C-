#include <iostream>
using namespace std;

template <typename T>
T max2(T a, T b) {
    return (a > b) ? a : b;
}

void demoTask3() {
    cout << "\nЗадание 3: Максимум из двух" << endl;
    
    cout << "max(5, 10) = " << max2(5, 10) << endl;
    cout << "max(3.14, 2.71) = " << max2(3.14, 2.71) << endl;
    cout << "max('a', 'z') = " << max2('a', 'z') << endl;
}