#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

void testList() {
    cout << "\nЗадание1" << endl;
    
    SinglyLinkedList<int> list;
    
    cout << "Добавляем элементы в начало:" << endl;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.print();
    
    cout << "Добавляем элементы в конец:" << endl;
    list.push_back(5);
    list.push_back(1);
    list.print();
    
    cout << "Первый элемент: " << list.front() << endl;
    cout << "Последний элемент: " << list.back() << endl;
    cout << "Размер: " << list.size() << endl;
    
    cout << "\ninsertAt" << endl;
    list.insertAt(0, 100);
    list.insertAt(2, 200);
    list.insertAt(6, 300);
    list.print();
    
    cout << "\ndeleteAt" << endl;
    list.deleteAt(0);
    list.deleteAt(2);
    list.deleteAt(4);
    list.print();
    
    cout << "\nОчистка списка" << endl;
    list.clear();
    cout << "Список пуст: " << (list.empty() ? "да" : "нет") << endl;
    
    cout << "\nСписок строк" << endl;
    SinglyLinkedList<string> strList;
    strList.push_back("Привет");
    strList.push_back("Мир");
    strList.push_back("C++");
    strList.insertAt(1, "красивый");
    strList.print();
}

void testPalindrome() {
    cout << "\nЗадание 2а" << endl;
    
    string words[] = {"radar", "hello", "level", "world", "madam", "racecar"};
    
    for (const string& word : words) {
        Stack<char> st;
        
        for (char c : word) {
            st.push(c);
        }
        
        bool isPalindrome = true;
        for (char c : word) {
            if (c != st.top()) {
                isPalindrome = false;
                break;
            }
            st.pop();
        }
        
        cout << "\"" << word << "\" - " 
             << (isPalindrome ? "палиндром" : "не палиндром") << endl;
    }
}

void testQueue() {
    cout << "\nЗадание 2б" << endl;
    
    Queue<int> tasks;
    
    cout << "Добавляем задачи в очередь:" << endl;
    tasks.enqueue(1);
    tasks.enqueue(2);
    tasks.enqueue(3);
    tasks.enqueue(4);
    tasks.enqueue(5);
    tasks.print();
    
    cout << "\nОбработка задач:" << endl;
    int order = 1;
    while (!tasks.empty()) {
        cout << "Обрабатываем задачу " << tasks.front() 
             << " (порядок обработки: " << order << ")" << endl;
        tasks.dequeue();
        order++;
    }
    cout << "Все задачи обработаны!" << endl;
}

void testStack() {
    cout << "\nСтэк" << endl;
    
    Stack<int> st;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.print();
    
    cout << "Верхний элемент: " << st.top() << endl;
    cout << "Размер: " << st.size() << endl;
    
    st.pop();
    st.print();
    
    st.pop();
    st.print();
}

int main() {
    setlocale(LC_ALL, "");
    
    testList();
    testStack();
    testPalindrome();
    testQueue();
    
    return 0;
}