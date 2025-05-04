#include <iostream>
#include "ArrayPriorityQueue.h"
#include "HeapPriorityQueue.h"

using namespace std;

int main()
{
    int choice;
    cout << "1. Array\n";
    cout << "2. Heap\n";
    cin >> choice;

    if (choice == 1) {
        cout << "\n--- Test ArrayPriorityQueue ---\n";
        ArrayPriorityQueue a;
        a.insert(1, 1);
        a.insert(12, 2);
        a.insert(13, 2);
        a.insert(15, 4);
        a.show();
        a.changePriority(15, 1);
        cout << endl;
        a.show();
    }
    else if (choice == 2) {
        cout << "\n--- Test HeapPriorityQueue ---\n";
        HeapPriorityQueue h;
        h.insert(5, 10);
        h.insert(2, 20);
        h.insert(8, 5);
        h.insert(9, 15);
        h.show();
        h.changePriority(5, 25);
        cout << "Po zmianie priorytetu:\n";
        h.show();
        cout << "Max: " << h.getMax() << endl;
        h.extractMax();
        cout << "Po extractMax:\n";
        h.show();
    }
    else {
        cout << "Nieprawid³owy wybór.\n";
    }

    return 0;
}
