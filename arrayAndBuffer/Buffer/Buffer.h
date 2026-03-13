#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <cstring>
using namespace std;

class Buffer {
private:
    char* data;
    size_t size;

public:
    explicit Buffer(size_t n);
    Buffer(const Buffer& other);
    Buffer(Buffer&& other) noexcept;
    ~Buffer();
    
    Buffer& operator=(const Buffer& other);
    Buffer& operator=(Buffer&& other) noexcept;
    
    void print() const;
};

#endif