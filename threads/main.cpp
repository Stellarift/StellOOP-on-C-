#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "ThreadGuard.h"
#include "AtomicCounter.h"
using namespace std;

//функция для потока с задержкой
void slowTask() {
    cout << "Медленная задача: начало" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Медленная задача: конец" << endl;
}

//функция для быстрого потока
void fastTask() {
    cout << "Быстрая задача: начало" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Быстрая задача: конец" << endl;
}

//функция для тестирования счётчика
void counterTask(AtomicCounter& counter, int increments, int decrements) {
    for (int i = 0; i < increments; i++) {
        counter.increment();
    }
    for (int i = 0; i < decrements; i++) {
        counter.decrement();
    }
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Задание 2.1" << endl;
    
    {
        cout << "\nСоздаём два потока" << endl;
        ThreadGuard t1(slowTask);
        ThreadGuard t2(fastTask);
        
        cout << "Потоки созданы" << endl;
    }
    cout << "Потоки завершены" << endl;
    
    // Демонстрация с лямбдой
    {
        cout << "\nПоток с лямбдой" << endl;
        ThreadGuard t3([](){
            cout << "Лямбда: начало" << endl;
            this_thread::sleep_for(chrono::milliseconds(200));
            cout << "Лямбда: конец" << endl;
        });
    }
    
    cout << "\nЗадание 2.2" << endl;
    
    AtomicCounter counter(0);
    const int THREAD_COUNT = 10;
    const int OPERATIONS_PER_THREAD = 10000;
    
    vector<thread> threads;
    
    // Запускаем потоки
    for (int i = 0; i < THREAD_COUNT; i++) {
        threads.emplace_back([&counter]() {
            for (int j = 0; j < OPERATIONS_PER_THREAD; j++) {
                counter.increment();
                counter.decrement();
            }
        });
    }
    
    // Ждём завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }
    
    cout << "Финальное значение счётчика: " << counter.get() << endl;
    cout << "(должно быть 0, если нет гонок данных)" << endl;
    
    cout << "\nтест: 5 инкрементов и 3 декремента" << endl;
    AtomicCounter counter2(0);
    vector<thread> threads2;
    
    threads2.emplace_back(counterTask, ref(counter2), 5, 3);
    threads2.emplace_back(counterTask, ref(counter2), 2, 4);
    
    for (auto& t : threads2) {
        t.join();
    }
    
    cout << "Финальное значение: " << counter2.get() << endl;
    cout << "Ожидалось: (5+2) - (3+4) = 0" << endl;
    
    return 0;
}