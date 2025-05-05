#include "Test.h"

vector<pair<int, int>> generateDataset(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 5 * size);
    vector<pair<int, int>> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = { i, dist(gen) };
    }
    return data;
}

void test() {
    const int DATASET_COUNT = 8;
    const int repeat = 10;
    int sizes[] = { 5000, 15000, 25000, 35000, 45000, 55000, 65000, 75000, 85000, 95000 };

    cout << "=== INSERT TEST ===" << endl;
    cout << "Size\tArrayPQ(us)\tHeapPQ(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long arrayTotal = 0;
        long long heapTotal = 0;
        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size);
            for (int x = 0; x < repeat; x++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 5 * size);
                int randomNumber = dist(gen);

                ArrayPriorityQueue apq(size);
                for (size_t j = 0; j < data.size(); j++)
                    apq.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                apq.insert(size + 1, randomNumber);
                auto end = high_resolution_clock::now();

                arrayTotal += duration_cast<nanoseconds>(end - start).count();

                HeapPriorityQueue hpq(size);
                for (size_t j = 0; j < data.size(); j++)
                    hpq.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                hpq.insert(size + 1, randomNumber);
                end = high_resolution_clock::now();
                heapTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << arrayTotal / DATASET_COUNT / 10 << "\t\t" << heapTotal / DATASET_COUNT / 10 << endl;

    }

    cout << "=== Extract Max TEST ===" << endl;
    cout << "Size\tArrayPQ(us)\tHeapPQ(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long arrayTotal = 0;
        long long heapTotal = 0;

        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size);

            ArrayPriorityQueue apq(size);
            for (size_t j = 0; j < data.size(); j++)
                apq.insert(data[j].first, data[j].second);

            auto start = high_resolution_clock::now();
            apq.extractMax();
            auto end = high_resolution_clock::now();
            arrayTotal += duration_cast<nanoseconds>(end - start).count();

            HeapPriorityQueue hpq(size);
            for (size_t j = 0; j < data.size(); j++)
                hpq.insert(data[j].first, data[j].second);
            start = high_resolution_clock::now();
            hpq.extractMax();
            end = high_resolution_clock::now();
            heapTotal += duration_cast<nanoseconds>(end - start).count();
        }
        cout << size << "\t" << arrayTotal / DATASET_COUNT << "\t\t" << heapTotal / DATASET_COUNT << endl;
    }

    cout << "=== Find Max TEST ===" << endl;
    cout << "Size\tArrayPQ(us)\tHeapPQ(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long arrayTotal = 0;
        long long heapTotal = 0;

        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size);
            for (int x = 0; x < repeat; x++) {
                ArrayPriorityQueue apq(size);
                for (size_t j = 0; j < data.size(); j++)
                    apq.insert(data[j].first, data[j].second);

                auto start = high_resolution_clock::now();
                apq.getMax();
                auto end = high_resolution_clock::now();
                arrayTotal += duration_cast<nanoseconds>(end - start).count();

                HeapPriorityQueue hpq(size);
                for (size_t j = 0; j < data.size(); j++)
                    hpq.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                hpq.getMax();
                end = high_resolution_clock::now();
                heapTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << arrayTotal / DATASET_COUNT << "\t\t" << heapTotal / DATASET_COUNT << endl;
    }
    cout << "=== Change priority TEST ===" << endl;
    cout << "Size\tArrayPQ(us)\tHeapPQ(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long arrayTotal = 0;
        long long heapTotal = 0;

        for (int i = 0; i < DATASET_COUNT; i++) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(1, size);
            uniform_int_distribution<int> dist2(1, 5 * size);
            int randomPlace = dist(gen);
            int randomPriority = dist2(gen);
            vector<pair<int, int>> data = generateDataset(size);
            for (int x = 0; x < repeat; x++) {
                ArrayPriorityQueue apq(size);
                for (size_t j = 0; j < data.size(); j++)
                    apq.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                apq.changePriority(data[randomPlace].first, randomPriority);
                auto end = high_resolution_clock::now();
                arrayTotal += duration_cast<nanoseconds>(end - start).count();

                HeapPriorityQueue hpq(size);
                for (size_t j = 0; j < data.size(); j++)
                    hpq.insert(data[randomPlace].first, data[j].second);
                start = high_resolution_clock::now();
                hpq.changePriority(data[randomPlace].first, randomPriority);
                end = high_resolution_clock::now();
                heapTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << arrayTotal / DATASET_COUNT << "\t\t" << heapTotal / DATASET_COUNT << endl;

    }

    cout << "=== Change priority TEST ===" << endl;
    cout << "Size\tArrayPQ(us)\tHeapPQ(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long arrayTotal = 0;
        long long heapTotal = 0;

        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size);
            for (int x = 0; x < repeat; x++) {
                ArrayPriorityQueue apq(size);
                for (size_t j = 0; j < data.size(); j++)
                    apq.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                apq.getSize();
                auto end = high_resolution_clock::now();
                arrayTotal += duration_cast<nanoseconds>(end - start).count();

                HeapPriorityQueue hpq(size);
                for (size_t j = 0; j < data.size(); j++)
                    hpq.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                hpq.getSize();
                end = high_resolution_clock::now();
                heapTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << arrayTotal / DATASET_COUNT << "\t\t" << heapTotal / DATASET_COUNT << endl;

    }
}