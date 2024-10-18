#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    string name;
    int data;
    Node* next;
    
    Node(string name = "", int data = 0, Node* next = nullptr) : name(name), data(data), next(next) {}
    
};

class records{
    public:
    Node* head;
    
    records() : head(nullptr){}
    
    void add(string name, int data){
        Node* newNode = new Node(name, data);
        
        if(!head){
            head = newNode;
            return;
        }    
        
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void print(){
        Node* temp = head;
        
        while(temp != nullptr){
            cout << temp->name << "  " << temp->data << endl;
            temp = temp->next;
        }
    }
    
    int getMax(){
        Node* temp = head;
        int mx = head->data;
        
        while(temp != nullptr){
            if(mx < temp->data)
                mx = temp->data;
                
            temp = temp->next;
        }
        return mx;
    }
    
    Node* countSort(Node* head, int expe){
        Node* count[10] = {nullptr};
        Node* tails[10] = {nullptr};
        
        Node* temp = head;
        while(temp != nullptr){
            int digit = (temp->data / expe) % 10;
            
            if(count[digit] == nullptr)
                count[digit] = tails[digit] = temp;
            
            else{
                tails[digit]->next = temp;
                tails[digit] = temp;
            }
            temp = temp->next;
        }
        
        Node* newHead = nullptr;
        Node* newTail = nullptr;
        
        for(int i =0; i < 10; i++){
            if(count[i] != nullptr){
                if(newHead == nullptr){
                    newHead = count[i];
                    newTail = tails[i];
                }else{
                    newTail->next = count[i];
                    newTail = tails[i];
                }
            }
        }
        newTail->next = nullptr;
        return newHead;
    }
    
    void radixSort(){
        if(!head || !head->next)
            return;
            
        int mx = getMax();
        
        for(int expe = 1; mx / expe > 0; expe *= 10){
            head = countSort(head, expe);
        }
    }
    
};

int main(){
    records rc;
    
    rc.add("Ayan",90);
    rc.add("Ali",60);
    rc.add("Sara", 70);
    rc.add("Zara", 50);
    rc.add("Jeena", 40);
    
    rc.print();
    cout << endl << endl;
    
    rc.radixSort();
    rc.print();
    
    
}




