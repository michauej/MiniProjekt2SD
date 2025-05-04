#include "HeapPriorityQueue.h"
#include <iostream>

using namespace std;

HeapPriorityQueue::HeapPriorityQueue(int cap) : capacity(cap), currentSize(0) {
    heap = new Element[capacity];
}

HeapPriorityQueue::~HeapPriorityQueue() {
    delete[] heap;
}

void HeapPriorityQueue::resize() {
    capacity *= 2;
    Element* newHeap = new Element[capacity];
    for (int i = 0; i < currentSize; i++) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
}

void HeapPriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].priority > heap[parent].priority) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

void HeapPriorityQueue::heapifyDown(int index) {
    while (index * 2 + 1 < currentSize) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int largest = index;

        if (left < currentSize && heap[left].priority > heap[largest].priority)
            largest = left;
        if (right < currentSize && heap[right].priority > heap[largest].priority)
            largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        }
        else {
            break;
        }
    }
}

void HeapPriorityQueue::insert(int value, int priority) {
    if (currentSize == capacity) resize();
    heap[currentSize] = Element(value, priority);
    heapifyUp(currentSize);
    currentSize++;
}

void HeapPriorityQueue::extractMax() {
    if (currentSize == 0) return;
    heap[0] = heap[currentSize - 1];
    currentSize--;
    heapifyDown(0);
}

int HeapPriorityQueue::getMax() {
    if (currentSize == 0) return -1;
    return heap[0].value;
}

void HeapPriorityQueue::changePriority(int value, int priority) {
    for (int i = 0; i < currentSize; i++) {
        if (heap[i].value == value) {
            int oldPriority = heap[i].priority;
            heap[i].priority = priority;

            if (priority > oldPriority) heapifyUp(i);
            else heapifyDown(i);
            break;
        }
    }
}

int HeapPriorityQueue::getSize() {
    return currentSize;
}

void HeapPriorityQueue::show() {
    for (int i = 0; i < currentSize; i++) {
        cout << heap[i].value << " ";
    }
    cout << endl;
}
