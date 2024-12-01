// SEPERATE CHAINING HASHING



#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    Node* next;

    Node(int key) : key(key), next(nullptr) {}
};

class HashMap{
    public:
    Node** table;
    int size;
    int capacity;

    HashMap(int capacity){
        this->capacity = capacity;
        int size = 0;
        table = new Node*[capacity];
        for(int i  =0; i < size; i++){
            table[i] = nullptr;
        }
    }

    int hashFunction(int key){
        return key % capacity;
    }

    void insert(int key){
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        if(table[index] == nullptr){
            table[index] = newNode;
        }else {
            Node* temp = table[index];
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    bool search(int key){
        int index = hashFunction(key);
        Node* temp = table[index];
        while(temp){
            if(temp->key == key)
                return true;
            
            temp = temp->next;
        }
        return false;
    }

    void deleteKey(int key){
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while(temp){
            if(temp->key == key){
                if(prev == nullptr){
                    table[index] = temp->next;
                }else{
                    prev->next = temp->next;
                }
                delete temp;
                size--;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            while (temp) {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

int main(){

}
