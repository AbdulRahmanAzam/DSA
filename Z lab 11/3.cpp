#include <iostream>
#include <vector>
using namespace std;

class AcademicPortal {
    vector<int> table;
    int capacity;
    int size;
    float loadFactorThreshold;

public:
    AcademicPortal(int initialSize, float threshold) : capacity(initialSize), size(0), loadFactorThreshold(threshold) {
        table.resize(capacity, -1); // -1 indicates empty slot
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void rehash() {
        cout << "Rehashing triggered! Expanding table size...\n";
        int oldCapacity = capacity;
        capacity *= 2;
        vector<int> oldTable = table;

        table.clear();
        table.resize(capacity, -1);
        size = 0;

        for (int key : oldTable) {
            if (key != -1) {
                insert(key);
            }
        }

        cout << "Rehashing complete. New capacity: " << capacity << endl;
    }

    void insert(int key) {
        if ((float)(size + 1) / capacity > loadFactorThreshold) {
            rehash();
        }

        int index = hashFunction(key);
        while (table[index] != -1) {
            index = (index + 1) % capacity; // Linear probing
        }

        table[index] = key;
        size++;
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < capacity; i++) {
            if (table[index] == key)
                return true;
            if (table[index] == -1)
                return false;
            index = (index + 1) % capacity;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1)
                cout << "Index " << i << ": " << table[i] << endl;
            else
                cout << "Index " << i << ": Empty" << endl;
        }
    }
};


// MAIN IS MADE BY GPT
int main() {
    AcademicPortal portal(7, 0.75);

    // Insert student IDs
    portal.insert(12);
    portal.insert(22);
    portal.insert(32);
    portal.insert(42);
    portal.insert(52);
    portal.insert(62);

    cout << "Academic Portal after initial insertion:" << endl;
    portal.display();

    // Search student IDs
    cout << "\nSearch results:" << endl;
    cout << "Student 22: " << (portal.search(22) ? "Found" : "Not Found") << endl;
    cout << "Student 42: " << (portal.search(42) ? "Found" : "Not Found") << endl;
    cout << "Student 72: " << (portal.search(72) ? "Found" : "Not Found") << endl;

    // Insert additional IDs to trigger rehashing
    portal.insert(72);
    portal.insert(82);
    cout << "\nAcademic Portal after inserting additional IDs:" << endl;
    portal.display();

    return 0;
}
