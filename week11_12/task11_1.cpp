#include <iostream>
using namespace std;

template <typename T>
double average(T arr[], int size) {
    if (size <= 0) return 0;
    
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return static_cast<double>(sum) / size;
}

void demoTask1() {
    cout << "\nЗадание 1: Среднее арифметическое" << endl;
    
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.5, 2.5, 3.5, 4.5};
    
    cout << "intArr: 1,2,3,4,5 -> среднее = " << average(intArr, 5) << endl;
    cout << "doubleArr: 1.5,2.5,3.5,4.5 -> среднее = " << average(doubleArr, 4) << endl;
}