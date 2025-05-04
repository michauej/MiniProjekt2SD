#pragma once
#include "IQueue.h"

class HeapPriorityQueue : public IQueue {
private:
    struct Element {
        int value;
        int priority;
        Element(int v = 0, int p = 0) : value(v), priority(p) {}
    };

    Element* heap;
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();

public:
    HeapPriorityQueue(int initialCapacity = 10);
    ~HeapPriorityQueue();

    void insert(int value, int priority) override;
    int extractMax() override;  
    void changePriority(int value, int priority) override;
    int getMax() override;
    int getSize() override;
    bool isEmpty() const;
};
