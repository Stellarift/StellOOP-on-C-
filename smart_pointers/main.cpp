#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include "Timer.h"
using namespace std;

unique_ptr<Timer> createTimer() {
    return make_unique<Timer>();
}

void testUniquePtr() {
    cout << "\nЗадание 3.1 uniqie ptr" << endl;
    
    cout << "Создаём Timer через unique_ptr" << endl;
    {
        auto timer = createTimer();
        cout << "Timer внутри блока" << endl;
    }
    cout << "Timer вышел из области видимости и был автоматически удалён" << endl;
    
    cout << "\nmove" << endl;
    unique_ptr<Timer> timer1 = make_unique<Timer>();
    cout << "timer1 создан" << endl;
    
    unique_ptr<Timer> timer2 = std::move(timer1);
    cout << "timer2 получил владение через move(timer1)" << endl;
    cout << "timer1 теперь пуст: " << (timer1 ? "не пуст" : "пуст") << endl;
}

void testSTL() {
    cout << "\nЗадание 3.2 лябмда" << endl;
    
    // Исходный список
    vector<string> names = {
        "Alice", "Bob", "Christopher", "Eve", 
        "Frank", "Geo", "Helen", "Ivy", "Jack", "Kim"
    };
    
    cout << "Исходный список:" << endl;
    for (const auto& name : names) {
        cout << "  " << name << " (" << name.length() << ")" << endl;
    }
    
    sort(names.begin(), names.end(), 
         [](const string& a, const string& b) {
             return a.length() < b.length();
         });
    
    cout << "\n1. После сортировки по длине:" << endl;
    for (const auto& name : names) {
        cout << "  " << name << " (" << name.length() << ")" << endl;
    }
    
    auto it = remove_if(names.begin(), names.end(),
                        [](const string& name) {
                            return name.length() < 4;
                        });
    names.erase(it, names.end());
    
    cout << "\n2. После удаления имён короче 4 символов:" << endl;
    for (const auto& name : names) {
        cout << "  " << name << " (" << name.length() << ")" << endl;
    }
    
    for (auto& name : names) {
        transform(name.begin(), name.end(), name.begin(),
                  [](unsigned char c) { return toupper(c); });
    }
    
    cout << "\n3. После преобразования в верхний регистр:" << endl;
    for (const auto& name : names) {
        cout << "  " << name << endl;
    }
    
    cout << "\nцепочка" << endl;
    vector<string> names2 = {"David", "Ann", "Jonathan", "Sam", "Victoria", "Tom"};
    
    cout << "Исходные: ";
    for (const auto& n : names2) cout << n << " ";
    cout << endl;
    
    auto it2 = remove_if(names2.begin(), names2.end(),
                         [](const string& s) { return s.length() < 4; });
    names2.erase(it2, names2.end());
    
    sort(names2.begin(), names2.end(),
         [](const string& a, const string& b) { return a.length() < b.length(); });
    
    for (auto& n : names2) {
        transform(n.begin(), n.end(), n.begin(), ::toupper);
    }
    
    cout << "Результат: ";
    for (const auto& n : names2) cout << n << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    testUniquePtr();
    testSTL();
    
    return 0;
}