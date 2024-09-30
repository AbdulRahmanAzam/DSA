
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
};


class SinglyList{
    Node* head;
    public:
    
    SinglyList(Node* head = nullptr) : head(head) {}
    
    void reverse(){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    
    Node* reverseHelper(Node* curr){
        if(!curr or !curr->next)
            return curr;
            
        Node* newHead = reverseHelper(curr->next);
        
        curr->next->next = curr;
        curr->next = nullptr;
        return newHead;
    }
    
    void reverseRecursion(){
        head = reverseHelper(head);
    }
    
    void insert(int data){
        Node* newNode = new Node(data, head);
        head = newNode;
    }
    
    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl << endl;
    }
};


int main(){
    SinglyList s;
    
    s.insert(5);
    s.insert(9);
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(8);
    s.insert(3);
    s.insert(2);
    
    s.print();
    
    cout << "reversed" << endl;
    s.reverse();
    s.print();
    
}







