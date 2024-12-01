// LINEAR PROBING



#include <bits/stdc++.h>
using namespace std;

class LinearProbing{
    public:
    int* table;
    int size;
    int capacity;

    LinearProbing(int capacity){
        this->capacity = capacity;
        this->size = 0;
        table = new int[capacity];
        for(int i = 0; i < capacity; i++){
            table[i] = -1;
        }
    }

    int hashFunction(int key){
        return key % capacity;
    }

    int linearProbe(int index, int key){
        while(table[index] != -1 && table[index] != key){
            index = (index + 1) % capacity;
        }
        return index;
    }


    void insert(int key){
        if(size >= capacity){
            cout << "Hash table is full" << endl;
        }

        int index = hashFunction(key);
        index = linearProbe(index, key);
        table[index] = key;
        size++;
    }

    bool search(int key){
        int index = hashFunction(key);
        index = linearProbe(index, key);
        return table[index] == key;
    }

    void deleteKey(int key){
        int index = hashFunction(key);
        index = linearProbe(index, key);
        if(table[index] != -1){
            table[index] = -1;
            size--;
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

int main(){

}
