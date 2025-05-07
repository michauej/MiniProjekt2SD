#include "HeapPriorityQueue.h"
#include <iostream>

using namespace std;
//konstruktor- alokuje pamiec dla kopca o zadanej pojemnsci
HeapPriorityQueue::HeapPriorityQueue(int cap) : capacity(cap), currentSize(0) {
    heap = new Element[capacity];
}
//destruktor- zwalnia zaalokowana pamiec
HeapPriorityQueue::~HeapPriorityQueue() {
    delete[] heap;
}
//zwiekszanie pojemnosci tablicy dynamicznej gdy zabraknie miejsca
void HeapPriorityQueue::resize() {
    capacity *= 2;
    Element* newHeap = new Element[capacity];
    for (int i = 0; i < currentSize; i++) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
}
//przywracanie wartosci kopca po dodaniu nowego elementu
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
//przywracanie wlscnosci kopca po usunieciu elementu ze szczytu
void HeapPriorityQueue::heapifyDown(int index) {
    while (index * 2 + 1 < currentSize) {//dopóki istnieje lewe dziecko
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int largest = index;
        //znajdz wieksze dzieci
        if (left < currentSize && heap[left].priority > heap[largest].priority)
            largest = left;
        if (right < currentSize && heap[right].priority > heap[largest].priority)
            largest = right;
        //jesli ktores ma wiekszy priorytet- zamien z rodzicem
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        }
        else {
            break;
        }
    }
}
//dodaje nowy element do kopca z dana wartosciom i priorytetem
void HeapPriorityQueue::insert(int value, int priority) {
    if (currentSize == capacity) resize();
    heap[currentSize] = Element(value, priority);
    heapifyUp(currentSize);
    currentSize++;
}
//usuwa element o najwyzszym priorytecie (czyli ten ze szczytu)
void HeapPriorityQueue::extractMax() {
    if (currentSize == 0) return;
    heap[0] = heap[currentSize - 1];
    currentSize--;
    heapifyDown(0);
}
//zwraca wartosc z najwyzszym priorytetem
int HeapPriorityQueue::getMax() {
    if (currentSize == 0) return -1;
    return heap[0].value;
}
//zmienia priorytet elementu o danej wartosci
void HeapPriorityQueue::changePriority(int value, int priority) {
    for (int i = 0; i < currentSize; i++) {
        if (heap[i].value == value) {
            int oldPriority = heap[i].priority;
            heap[i].priority = priority;
            //w zaleznosci od zmiany priorytetu przywraca struktore w gore lub w dol
            if (priority > oldPriority) heapifyUp(i);
            else heapifyDown(i);
            break;
        }
    }
}
//zwraca aktualny rozmiar kolejki
int HeapPriorityQueue::getSize() {
    return currentSize;
}
//wyswietla wszystkie elementy w kolejce (ich wartosci)
void HeapPriorityQueue::show() {
    for (int i = 0; i < currentSize; i++) {
        cout << heap[i].value << " ";
    }
    cout << endl;
}