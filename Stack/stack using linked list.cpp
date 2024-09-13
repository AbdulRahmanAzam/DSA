#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data = 0){
        this->data = data;
        this->next = nullptr;
    }
};

class Stack{
    Node* top;
    
    public:
    Stack(){
        top = nullptr;
    }
    
    bool isEmpty(){
        return top == nullptr;
    }
    
    void push(int val){
        Node* newNode = new Node(val);
        cout << newNode->data << " is pushed\n";
        if(!top){
            top = newNode;
        }else{
            newNode->next = top;
            top = newNode;
        }
    }
    
    void pop(){
        if(!top){
            cout << "Stack overflow, there is no element\n";
        }else{
             Node* temp = top;
             cout << "The popped value is: " << top->data << endl;
             top = top->next;
             delete temp;
        }
    }
    
    int peek(){
        if(!top){
            cout << "There is no element\n";
            return -1;
        }else{
            return top->data;
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  // This will show stack overflow

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    cout << "Top element is: " << s.peek() << endl;

    return 0;
    
    
}
