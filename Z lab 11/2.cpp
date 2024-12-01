#include <iostream>
using namespace std;

class FitnessClub {
    int* table;
    int capacity;
    int size;

public:
    FitnessClub(int size) : capacity(size), size(0) {
        table = new int[capacity];
        for (int i = 0; i < capacity; i++)
            table[i] = -1; // -1 indicates empty slot
    }

    ~FitnessClub() {
        delete[] table;
    }

    int hashFunction(int memberID) {
        return memberID % capacity;
    }

    void insert(int memberID) {
        if (size == capacity) {
            cout << "Hash table full!" << endl;
            return;
        }
        int index = hashFunction(memberID);
        while (table[index] != -1) {
            index = (index + 1) % capacity; // Linear probing
        }
        table[index] = memberID;
        size++;
    }

    bool search(int memberID) {
        int index = hashFunction(memberID);
        for (int i = 0; i < capacity; i++) {
            if (table[index] == memberID)
                return true;
            if (table[index] == -1)
                return false;
            index = (index + 1) % capacity;
        }
        return false;
    }

    void remove(int memberID) {
        int index = hashFunction(memberID);
        for (int i = 0; i < capacity; i++) {
            if (table[index] == memberID) {
                table[index] = -1; // Mark as deleted
                size--;
                return;
            }
            if (table[index] == -1)
                return; // Not found
            index = (index + 1) % capacity;
        }
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] == -1)
                cout << "Index " << i << ": Empty" << endl;
            else
                cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};


// MAIN IS MADE BY GPT
int main() {
    FitnessClub club(7);

    // Insert members
    club.insert(10);
    club.insert(20);
    club.insert(30);
    club.insert(40);
    club.insert(50);
    club.insert(60);

    cout << "Fitness Club after insertion:" << endl;
    club.display();

    // Search members
    cout << "\nSearch results:" << endl;
    cout << "Member 30: " << (club.search(30) ? "Found" : "Not Found") << endl;
    cout << "Member 50: " << (club.search(50) ? "Found" : "Not Found") << endl;
    cout << "Member 70: " << (club.search(70) ? "Found" : "Not Found") << endl;

    // Remove members and reuse slots
    club.remove(20);
    club.remove(40);
    club.insert(70);
    club.insert(80);
    cout << "\nFitness Club after deletions and insertions:" << endl;
    club.display();

    return 0;
}
