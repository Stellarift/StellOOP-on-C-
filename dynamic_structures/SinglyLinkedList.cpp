#include "SinglyLinkedList.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), listSize(0) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    listSize++;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    listSize++;
}

template <typename T>
void SinglyLinkedList<T>::pop_front() {
    if (empty()) {
        throw out_of_range("Список пуст");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    listSize--;
}

template <typename T>
void SinglyLinkedList<T>::pop_back() {
    if (empty()) {
        throw out_of_range("Список пуст");
    }
    
    if (listSize == 1) {
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    listSize--;
}

template <typename T>
void SinglyLinkedList<T>::insertAt(size_t index, const T& value) {
    if (index > listSize) {
        throw out_of_range("Индекс за пределами списка");
    }
    
    if (index == 0) {
        push_front(value);
        return;
    }
    
    Node* newNode = new Node(value);
    Node* current = head;
    
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    listSize++;
}

template <typename T>
void SinglyLinkedList<T>::deleteAt(size_t index) {
    if (index >= listSize) {
        throw out_of_range("Индекс за пределами списка");
    }
    
    if (index == 0) {
        pop_front();
        return;
    }
    
    Node* current = head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    listSize--;
}

template <typename T>
T& SinglyLinkedList<T>::front() {
    if (empty()) {
        throw out_of_range("Список пуст");
    }
    return head->data;
}

template <typename T>
T& SinglyLinkedList<T>::back() {
    if (empty()) {
        throw out_of_range("Список пуст");
    }
    
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
bool SinglyLinkedList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
size_t SinglyLinkedList<T>::size() const {
    return listSize;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    listSize = 0;
}

template <typename T>
void SinglyLinkedList<T>::print() const {
    Node* current = head;
    while (current) {
        cout << current->data;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}