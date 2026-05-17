#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Task {
    string description;
    int priority;
public:
    Task(string desc, int prio) : description(desc), priority(prio) {
        if (prio < 1 || prio > 5) throw runtime_error("Priority 1-5");
        if (desc.empty()) throw runtime_error("Description not empty");
    }
    int getPriority() const { return priority; }
    void print() const { cout << "[" << priority << "] " << description << "\n"; }
};

class TaskManager {
    vector<Task> tasks;
public:
    void add(string desc, int prio) { tasks.emplace_back(desc, prio); }
    void sortByPriority() {
        sort(tasks.begin(), tasks.end(),
            [](const Task& a, const Task& b) { return a.getPriority() > b.getPriority(); });
    }
    void printAll() const {
        for (const auto& t : tasks) t.print();
    }
    size_t count() const { return tasks.size(); }
};

int main() {
    TaskManager tm;
    int n;
    cout << "Сколько задач? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string desc;
        int prio;
        cout << "Описание: ";
        cin.ignore();
        getline(cin, desc);
        cout << "Приоритет (1-5): ";
        cin >> prio;
        try {
            tm.add(desc, prio);
        } catch (...) {
            cout << "Ошибка\n";
        }
    }

    tm.sortByPriority();
    tm.printAll();
}