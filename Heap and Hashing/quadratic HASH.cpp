// QUADRATIC PROBING

#include <bits/stdc++.h>
using namespace std;

class HashMap{
    public:
    int* table;
    int size;
    int capacity;

    HashMap(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->table = new int[capacity];

        for(int i=0; i < capacity; i++){
            table[i] = -1;
        }
    }

    int hashFunction(int key){
        return key % capacity;
    }

    int quadraticProbe(int index, int key){
        int i = 1;
        while(table[index] != -1 && table[index] != key){
            index = (index + i * i) % capacity;
            i++;
        }
        return index;
    }

    void insert(int key){
        if(size >= capacity){
            cout << "HashMap is full "<< endl;
            return;
        }

        int index = hashFunction(key);
        index = quadraticProbe(index, key);
        table[index] = key;
        size++;
    }

    void deleteKey(int key){
        int index = hashFunction(key);
        index = quadraticProbe(index, key);
        table[index] = -1;
        size--;
    }
    bool search(int key){
        int index = hashFunction(key);
        index = quadraticProbe(index, key);
        return table[index] == key;
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

int main() {
    HashMap map(7); // Create a hash map with capacity 7

    // Insert elements
    map.insert(10);
    map.insert(20);
    map.insert(30);
    map.insert(40);
    map.insert(50);

    cout << "HashMap after inserting elements:\n";
    map.display();

    // Search for elements
    cout << "\nSearch for key 30: " << (map.search(30) ? "Found" : "Not Found") << endl;
    cout << "Search for key 70: " << (map.search(70) ? "Found" : "Not Found") << endl;

    // Delete a key
    cout << "\nDeleting key 30...\n";
    map.deleteKey(30);

    cout << "HashMap after deletion:\n";
    map.display();

    // Try to insert another element to check probing
    cout << "\nInserting key 60...\n";
    map.insert(60);
    map.insert(30);
    map.insert(90);
    map.insert(100);


    cout << "HashMap after inserting key 60:\n";
    map.display();

    return 0;
}
