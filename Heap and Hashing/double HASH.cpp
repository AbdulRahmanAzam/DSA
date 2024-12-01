// DOUBLE HASHING


#include <bits/stdc++.h>
using namespace std;

class HashMap{
    public:
    int *table;
    int size;
    int capacity;
    int prime; // for secondary hash

    HashMap(int capacity){
        this->capacity = capacity;
        size = 0;
        table = new int[capacity];
        for(int i=0; i < capacity; i++){
            table[i] = -1;
        }

        prime = getNextPrime(capacity - 1);
    }

    int HashFunction(int key){
        return key % capacity;
    }

    int secondaryHash(int index, int key){
        while(table[index] != -1 && table[index] != key){
            index = (index + (prime - (key % prime))) % capacity;
        }
        return index;
    }

    int getNextPrime(int n){
        while(true){
            n++;
            bool isPrime = true;
            for(int i = 2; i * i <= n; i++){
                if(n % i == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime)
                return n;
        }
    }

    void insert(int key){
        if(size >= capacity){
            cout << "HashMap is full" << endl;
            return;
        }


        int index = HashFunction(key);
        index = secondaryHash(index, key);

        if(table[index] == -1){
            table[index] = key;
            size++;
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


int main() {
    HashMap hashmap(7);

    hashmap.insert(10);
    hashmap.insert(20);
    hashmap.insert(30);
    hashmap.insert(40);
    hashmap.insert(50);

    cout << "hashmap after insertion:\n";
    hashmap.display();

    // cout << "\nSearch for key 20: " << (hashmap.search(20) ? "Found" : "Not Found") << endl;
    // cout << "Search for key 70: " << (hashmap.search(70) ? "Found" : "Not Found") << endl;

    cout << "\nDeleting key 20...\n";
    // hashmap.deleteKey(20);

    cout << "hashmap after deletion:\n";
    hashmap.display();

    return 0;
}
