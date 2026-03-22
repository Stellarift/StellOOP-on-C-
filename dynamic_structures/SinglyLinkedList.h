#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    size_t listSize;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    
    void insertAt(size_t index, const T& value);
    void deleteAt(size_t index);
    
    T& front();
    T& back();
    
    bool empty() const;
    size_t size() const;
    void clear();
    
    void print() const;
    
    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
};

#include "SinglyLinkedList.cpp"
#endif