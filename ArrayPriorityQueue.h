#pragma once
#include "IQueue.h"

class ArrayPriorityQueue: public IQueue{
private:
    struct Element {
        int value;
        int priority;
        Element() : value(0), priority(0) {}
        Element(int value, int priority);
    };

    Element* array;
    int capacity;
    int currentSize;

    void resize() {
        capacity *= 2;
        Element* newArray = new Element[capacity];
        for (int i = 0; i < currentSize; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

public:
    ArrayPriorityQueue(int cap = 10);
    ~ArrayPriorityQueue()override;
    void insert(int value, int priority)override;
    void extractMax()override;
    int getMax()override;
    void changePriority(int value, int priority)override;
    int getSize()override;
    void show();
    
};