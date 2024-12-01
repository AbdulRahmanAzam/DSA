#include <iostream>
#include <vector>
using namespace std;

class BankingSystem {
    vector<int> table;
    int capacity;
    int size;

public:
    BankingSystem(int tableSize) : capacity(tableSize), size(0) {
        table.resize(capacity, -1); // -1 indicates empty slot
    }

    int primaryHash(int key) {
        return key % capacity;
    }

    int secondaryHash(int key) {
        return 7 - (key % 7);
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Hash table full!" << endl;
            return;
        }

        int index = primaryHash(key);
        int step = secondaryHash(key);
        while (table[index] != -1) {
            index = (index + step) % capacity;
        }

        table[index] = key;
        size++;
    }

    bool search(int key) {
        int index = primaryHash(key);
        int step = secondaryHash(key);
        for (int i = 0; i < capacity; i++) {
            if (table[index] == key)
                return true;
            if (table[index] == -1)
                return false;
            index = (index + step) % capacity;
        }
        return false;
    }

    void remove(int key) {
        int index = primaryHash(key);
        int step = secondaryHash(key);
        for (int i = 0; i < capacity; i++) {
            if (table[index] == key) {
                table[index] = -1;
                size--;
                return;
            }
            if (table[index] == -1)
                return; // Not found
            index = (index + step) % capacity;
        }
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
    BankingSystem bank(11);

    // Insert account numbers
    bank.insert(101);
    bank.insert(111);
    bank.insert(121);
    bank.insert(131);
    bank.insert(141);
    bank.insert(151);

    cout << "Banking System after insertion:" << endl;
    bank.display();

    // Search account numbers
    cout << "\nSearch results:" << endl;
    cout << "Account 111: " << (bank.search(111) ? "Found" : "Not Found") << endl;
    cout << "Account 141: " << (bank.search(141) ? "Found" : "Not Found") << endl;
    cout << "Account 161: " << (bank.search(161) ? "Found" : "Not Found") << endl;

    // Delete accounts and demonstrate secondary hashing
    bank.remove(111);
    bank.remove(131);
    bank.insert(161);
    bank.insert(171);
    cout << "\nBanking System after deletions and new insertions:" << endl;
    bank.display();

    return 0;
}
