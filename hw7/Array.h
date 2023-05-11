#pragma once
#include <iostream>

class IntArray 
{
public:
    IntArray() = default;
    IntArray(int length);
    IntArray(const IntArray& a);
    ~IntArray();

    void erase();

    int& operator[](int index);
    IntArray& operator=(const IntArray& a);

    int get_length() const;

    void reallocate(int new_len);
    void resize(int new_len);

    void insert(int value, int index);
    void remove(int index);

    void insertAtBeginning(int value);
    void insertAtEnd(int value);

    void removeFirst();
    void removeLast();
    
    int findByValue(int value);

    void print();
    
    void fill(int value, int index);

private: 
    int _length;
    int* _data{};

};