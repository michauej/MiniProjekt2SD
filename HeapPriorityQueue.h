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
    int currentSize;

    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();

public:
    HeapPriorityQueue(int cap = 10);
    ~HeapPriorityQueue() override;
    void insert(int value, int priority) override;
    void extractMax() override;
    int getMax() override;
    void changePriority(int value, int priority) override;
    int getSize() override;
    void show();
};
