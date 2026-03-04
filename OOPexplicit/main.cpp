#include <iostream>
#include "String.h"
#include "Array.h"
#include "Book.h"
#include "Worker.h"
using namespace std;

void testString() {
    cout << "\n1) String" << endl;
    
    String s1;                    
    String s2(20);               
    String s3("Привет, мир!"); 
    String s4 = s3;  
    
    cout << "\nВывод строк" << endl;
    s1.output();
    s2.output();
    s3.output();
    s4.output();
    
    cout << "\nВвод строки с клавиатуры" << endl;
    String s5;
    s5.input();
    s5.output();
}

void testArray() {
    cout << "\n2)Array" << endl;
    
    Array arr1;                   
    Array arr2(5);
    
    arr1.fillRandom();
    arr1.display();
    
    cout << "Min: " << arr1.getMin() << ", Max: " << arr1.getMax() << endl;
    
    arr1.sort();
    arr1.display();
    
    arr1.resize(7);
    arr1.display();
    
    Array arr3 = arr1;  // копирование
    cout << "Copy of arr1: ";
    arr3.display();
    
    cout << "\nВвод массива с клавиатуры" << endl;
    Array arr4(3);
    arr4.fillFromKeyboard();
    arr4.display();
}

void testBooks() {
    cout << "\n3)Books" << endl;
    
    Book books[] = {
        Book("Пушкин", "Евгений Онегин", "Азбука", 1833, 224),
        Book("Толстой", "Война и мир", "Эксмо", 1869, 1225),
        Book("Достоевский", "Преступление и наказание", "Азбука", 1866, 672),
        Book("Пушкин", "Капитанская дочка", "Детгиз", 1836, 320),
        Book("Тургенев", "Отцы и дети", "Азбука", 1862, 288)
    };
    int bookCount = 5;
    
    cout << "\nВсе книги" << endl;
    for (int i = 0; i < bookCount; i++) {
        books[i].display();
    }
    
    string author;
    cout << "\nВведите автора для поиска: ";
    cin.ignore();
    getline(cin, author);
    cout << "Книги автора " << author << ":" << endl;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getAuthor() == author) {
            books[i].display();
        }
    }
    
    string publisher;
    cout << "\nВведите издательство для поиска: ";
    getline(cin, publisher);
    cout << "Книги издательства " << publisher << ":" << endl;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getPublisher() == publisher) {
            books[i].display();
        }
    }
    
    int year;
    cout << "\nВведите год (книги после этого года): ";
    cin >> year;
    cout << "Книги после " << year << " года:" << endl;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getYear() > year) {
            books[i].display();
        }
    }
}

void testWorkers() {
    cout << "\n4)Workers" << endl;
    
    Worker workers[] = {
        Worker("Иванов Иван", "Инженер", 2015, 75000),
        Worker("Петров Петр", "Программист", 2020, 120000),
        Worker("Сидорова Анна", "Бухгалтер", 2018, 65000),
        Worker("Козлов Дмитрий", "Инженер", 2010, 90000),
        Worker("Смирнова Елена", "Программист", 2022, 110000)
    };
    int workerCount = 5;
    int currentYear = 2024;
    
    cout << "\nВсе работники" << endl;
    for (int i = 0; i < workerCount; i++) {
        workers[i].display();
    }
    
    int minExperience;
    cout << "\nВведите минимальный стаж (лет): ";
    cin >> minExperience;
    cout << "Работники со стажем больше " << minExperience << " лет:" << endl;
    for (int i = 0; i < workerCount; i++) {
        if (workers[i].getExperience(currentYear) > minExperience) {
            workers[i].display();
        }
    }
    
    double minSalary;
    cout << "\nВведите минимальную зарплату: ";
    cin >> minSalary;
    cout << "Работники с зарплатой выше " << minSalary << ":" << endl;
    for (int i = 0; i < workerCount; i++) {
        if (workers[i].getSalary() > minSalary) {
            workers[i].display();
        }
    }
    
    string position;
    cout << "\nВведите должность: ";
    cin.ignore();
    getline(cin, position);
    cout << "Работники с должностью \"" << position << "\":" << endl;
    for (int i = 0; i < workerCount; i++) {
        if (workers[i].getPosition() == position) {
            workers[i].display();
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    
    testString();
    testArray();
    testBooks();
    testWorkers();
    
    cout << "\nВыполнено" << endl;
    return 0;
}