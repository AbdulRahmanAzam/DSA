#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    Node(int data = 0, Node* next= nullptr) : data(data), next(next){}
    
};

class Stack{
    public:
    Node* head;
    int top;
    Stack() : head(nullptr), top(0) {}
    
    
    void push(int data){
        Node* newData = new Node(data, head);
        
        if(!head)
            top = newData->data;
        
        head = newData;
    }
    
    void pop(){
        Node* temp = head;
        
        while(temp->next != nullptr || temp->next->next != nullptr){
            temp = temp->next;
        }
        temp->next = nullptr;
        top = temp->data;
    }
    
    int peek(){
        return top;
    }
    
    bool isEmpty(){
        return (head == nullptr ? true : false);
    }
    
    
    void print(){
        Node* temp = head;
        
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<< endl;
    }
};

void print(stack<int> st){
    stack<int> a = st;
    
    while(!a.empty()){
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
};

int main(){
    // BUILT IN STACK
    stack<int> st;
    st.push(5);
    st.push(3);
    st.push(1);
    print(st);

    // MANUAL STACK    
    Stack s;
    s.push(5);
    s.push(3);
    s.push(1);
    s.print();
}
