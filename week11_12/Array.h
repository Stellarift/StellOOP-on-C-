#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;       // текущий размер (количество элементов)
    int capacity;   // выделенная память (макс. количество)
    int grow;       // шаг увеличения

public:
    Array();
    explicit Array(int initialSize, int growValue = 1);
    Array(const Array& other);
    ~Array();
    
    int GetSize() const;
    void SetSize(int newSize, int growValue = -1);
    int GetUpperBound() const;
    bool IsEmpty() const;
    void FreeExtra();
    void RemoveAll();
    
    T& GetAt(int index);
    void SetAt(int index, const T& value);
    
    T& operator[](int index);
    const T& operator[](int index) const;
    
    void Add(const T& value);
    Array<T> Append(const Array<T>& other) const;
    Array<T>& operator=(const Array<T>& other);
    
    T* GetData();
    const T* GetData() const;
    
    void InsertAt(int index, const T& value);
    void InsertAt(int index, const Array<T>& other);
    void RemoveAt(int index);
    void RemoveAt(int index, int count);
    
    void Print() const;
};

// ========== РЕАЛИЗАЦИЯ МЕТОДОВ ==========

template <typename T>
Array<T>::Array() : data(nullptr), size(0), capacity(0), grow(1) {
    cout << "Array default constructor" << endl;
}

template <typename T>
Array<T>::Array(int initialSize, int growValue) 
    : size(initialSize), capacity(initialSize), grow(growValue) {
    cout << "Array constructor with size=" << initialSize << ", grow=" << growValue << endl;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = T();
    }
}

template <typename T>
Array<T>::Array(const Array& other) 
    : size(other.size), capacity(other.capacity), grow(other.grow) {
    cout << "Array copy constructor" << endl;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>::~Array() {
    cout << "Array destructor" << endl;
    delete[] data;
}

template <typename T>
int Array<T>::GetSize() const {
    return size;
}

template <typename T>
void Array<T>::SetSize(int newSize, int growValue) {
    if (growValue != -1) {
        grow = growValue;
    }
    
    if (newSize == size) return;
    
    if (newSize <= capacity) {
        if (newSize < size) {
            size = newSize;
        } else {
            size = newSize;
        }
        return;
    }
    
    int newCapacity = newSize;
    T* newData = new T[newCapacity];
    
    int copySize = (size < newSize) ? size : newSize;
    for (int i = 0; i < copySize; i++) {
        newData[i] = data[i];
    }
    
    for (int i = copySize; i < newSize; i++) {
        newData[i] = T();
    }
    
    delete[] data;
    data = newData;
    size = newSize;
    capacity = newCapacity;
}

template <typename T>
int Array<T>::GetUpperBound() const {
    return (size > 0) ? (size - 1) : -1;
}

template <typename T>
bool Array<T>::IsEmpty() const {
    return size == 0;
}

template <typename T>
void Array<T>::FreeExtra() {
    if (size == capacity) return;
    
    if (size == 0) {
        delete[] data;
        data = nullptr;
        capacity = 0;
        return;
    }
    
    T* newData = new T[size];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
    capacity = size;
}

template <typename T>
void Array<T>::RemoveAll() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template <typename T>
T& Array<T>::GetAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of bounds!" << endl;
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
void Array<T>::SetAt(int index, const T& value) {
    if (index < 0 || index >= size) {
        cout << "Index out of bounds!" << endl;
        return;
    }
    data[index] = value;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of bounds!" << endl;
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        cout << "Index out of bounds!" << endl;
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
void Array<T>::Add(const T& value) {
    if (size >= capacity) {
        int newCapacity = capacity + grow;
        T* newData = new T[newCapacity];
        
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
    data[size++] = value;
}

template <typename T>
Array<T> Array<T>::Append(const Array<T>& other) const {
    Array<T> result(size + other.size, grow);
    
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i];
    }
    
    for (int i = 0; i < other.size; i++) {
        result.data[size + i] = other.data[i];
    }
    
    return result;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    cout << "Array copy assignment" << endl;
    
    if (this != &other) {
        delete[] data;
        
        size = other.size;
        capacity = other.capacity;
        grow = other.grow;
        
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    
    return *this;
}

template <typename T>
T* Array<T>::GetData() {
    return data;
}

template <typename T>
const T* Array<T>::GetData() const {
    return data;
}

template <typename T>
void Array<T>::InsertAt(int index, const T& value) {
    if (index < 0 || index > size) {
        cout << "Index out of bounds!" << endl;
        return;
    }
    
    if (size >= capacity) {
        SetSize(size + 1, grow);
    } else {
        size++;
    }
    
    for (int i = size - 1; i > index; i--) {
        data[i] = data[i - 1];
    }
    
    data[index] = value;
}

template <typename T>
void Array<T>::InsertAt(int index, const Array<T>& other) {
    if (index < 0 || index > size) {
        cout << "Index out of bounds!" << endl;
        return;
    }
    
    int newSize = size + other.size;
    if (newSize > capacity) {
        SetSize(newSize, grow);
    } else {
        size = newSize;
    }
    
    for (int i = size - 1; i >= index + other.size; i--) {
        data[i] = data[i - other.size];
    }
    
    for (int i = 0; i < other.size; i++) {
        data[index + i] = other.data[i];
    }
}

template <typename T>
void Array<T>::RemoveAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of bounds!" << endl;
        return;
    }
    
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    
    size--;
}

template <typename T>
void Array<T>::RemoveAt(int index, int count) {
    if (index < 0 || index >= size || count <= 0) {
        cout << "Invalid parameters!" << endl;
        return;
    }
    
    int endIndex = index + count;
    if (endIndex > size) {
        endIndex = size;
    }
    
    int removeCount = endIndex - index;
    
    for (int i = index; i < size - removeCount; i++) {
        data[i] = data[i + removeCount];
    }
    
    size -= removeCount;
}

template <typename T>
void Array<T>::Print() const {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "] (size=" << size << ", cap=" << capacity << ")" << endl;
}

#endif