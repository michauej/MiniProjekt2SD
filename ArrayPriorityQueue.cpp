#include "ArrayPriorityQueue.h"
#include <iostream>

using namespace std;
ArrayPriorityQueue::Element::Element(int value, int priority):value(value),priority(priority){}

ArrayPriorityQueue::ArrayPriorityQueue(int cap) : currentSize(0), capacity(cap) {
    array = new Element[capacity];
}

ArrayPriorityQueue::~ArrayPriorityQueue() {
    delete[] array;
}

void ArrayPriorityQueue::insert(int value, int priority) {
    if (currentSize == capacity) {
        resize();
    }

    int i;

    // znajdź miejsce do wstawienia — rosnąco wg priorytetu
    for (i = currentSize - 1; i >= 0 && array[i].priority > priority; i--) {
        array[i + 1] = array[i]; // przesuń w prawo
    }

    // wstaw nowy element
    array[i + 1] = Element(value, priority);
    currentSize++;
}


void ArrayPriorityQueue::extractMax() {
    if (currentSize > 0) {
        currentSize--;
    }
}

int ArrayPriorityQueue::getMax() {
    if (currentSize > 0) {
        return array[currentSize - 1].value;
    }
}

void ArrayPriorityQueue::changePriority(int value, int priority) {
    int index = -1;

    // 1. Znajdź element do zmiany
    for (int i = 0; i < currentSize; i++) {
        if (array[i].value == value) {
            index = i;
            break;
        }
    }

    if (index == -1) return; // Element nie znaleziony

    // 2. Usuń go z tablicy i zaktualizuj priorytet
    Element updatedElement = array[index];
    updatedElement.priority = priority;

    for (int i = index; i < currentSize - 1; i++) {
        array[i] = array[i + 1];
    }
    currentSize--;
    insert(updatedElement.value, updatedElement.priority);
}


int ArrayPriorityQueue::getSize() {
    return currentSize;
}

void ArrayPriorityQueue::show() {
    for (int i = 0; i < currentSize; i++) {
        std::cout << array[i].value << " ";
    }
}