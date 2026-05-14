#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    vector<int> grades;
    double average;
};

// Вычисление среднего балла
double calculateAverage(const vector<int>& grades) {
    if (grades.empty()) {
        return 0.0;
    }
    double sum = accumulate(grades.begin(), grades.end(), 0.0);
    return sum / grades.size();
}

// Ввод одного студента
Student readStudent() {
    Student s;
    
    cin.ignore(); // очистка буфера после предыдущего ввода
    cout << "Введите имя студента: ";
    getline(cin, s.name);
    
    int gradeCount;
    cout << "Введите количество оценок: ";
    cin >> gradeCount;
    
    // Проверка на корректность
    if (gradeCount <= 0) {
        cout << "Ошибка: количество оценок должно быть больше 0\n";
        return s;
    }
    
    s.grades.resize(gradeCount);
    cout << "Введите оценки через пробел: ";
    for (int i = 0; i < gradeCount; ++i) {
        cin >> s.grades[i];
    }
    
    s.average = calculateAverage(s.grades);
    return s;
}

// Ввод всех студентов
vector<Student> readAllStudents() {
    int studentCount;
    cout << "Введите количество студентов: ";
    cin >> studentCount;
    
    if (studentCount <= 0) {
        cout << "Ошибка: количество студентов должно быть больше 0\n";
        return {};
    }
    
    vector<Student> students;
    for (int i = 0; i < studentCount; ++i) {
        cout << "\n--- Студент " << (i + 1) << " ---\n";
        students.push_back(readStudent());
    }
    
    return students;
}

// Вывод топ-3 студентов
void printTop3(const vector<Student>& students) {
    if (students.empty()) {
        cout << "Нет студентов для отображения\n";
        return;
    }
    
    int topCount = min(3, static_cast<int>(students.size()));
    
    // Копируем и сортируем только топ элементов
    vector<Student> sorted = students;
    partial_sort(sorted.begin(), sorted.begin() + topCount, sorted.end(),
        [](const Student& a, const Student& b) {
            return a.average > b.average;
        });
    
    cout << "\n=== ТОП-" << topCount << " студентов ===\n";
    for (int i = 0; i < topCount; ++i) {
        cout << (i + 1) << ". " << sorted[i].name 
                  << " - средний балл: " << fixed << setprecision(2)
                  << sorted[i].average << "\n";
    }
}

// Вывод всех студентов, отсортированных по среднему баллу
void printSorted(const vector<Student>& students) {
    if (students.empty()) {
        cout << "Нет студентов для отображения\n";
        return;
    }
    
    // Создаём копию и сортируем
    vector<Student> sorted = students;
    sort(sorted.begin(), sorted.end(),
        [](const Student& a, const Student& b) {
            return a.average > b.average;
        });
    
    cout << "\n=== Все студенты (по убыванию среднего балла) ===\n";
    for (size_t i = 0; i < sorted.size(); ++i) {
        cout << (i + 1) << ". " << sorted[i].name 
                  << " - средний балл: " << fixed << setprecision(2)
                  << sorted[i].average << "\n";
        
        // Вывод всех оценок
        cout << "   Оценки: ";
        for (int grade : sorted[i].grades) {
            cout << grade << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "=== Программа для обработки студентов ===\n";
    
    auto students = readAllStudents();
    
    if (!students.empty()) {
        printTop3(students);
        printSorted(students);
    }
    
    return 0;
}