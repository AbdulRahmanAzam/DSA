// REHASHING




#include <bits/stdc++.h>
using namespace std;

class HashMap{
    public:
    vector<int> table;
    int capacity;
    int size;

    HashMap(int capacity){
        this->capacity = capacity;
        size = 0;
        table.resize(capacity, -1);
    }

    void rehash(){
        cout << "Rehashing..." << endl;

        int oldCapacity = capacity;
        vector<int> oldTable = table;

        capacity *= 2;
        table = vector<int>(capacity, -1);
        size = 0;

        for(int i= 0; i < oldCapacity; i++){
            if(oldTable[i] != -1)
                insert(oldTable[i]);
        } 
    }

    int hashFunction(int key){
        return (key % capacity);
    }

    void insert(int key){
        if(size >= 0.75 * capacity){
            rehash();
        }

        int index = hashFunction(key);
        while(table[index] != -1 && table[index] != key)
            index = (index + 1) % capacity;

        if(table[index] != key){
            table[index] = key;
            size++;
        }
    }
};

int main(){
    
}
