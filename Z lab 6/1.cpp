#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[10000];

public:
    Stack() : top(-1) {}

    void push(int n) {
        if (top < 9999) { 
            arr[++top] = n;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if (top > -1) {
            top--;
        } else {
            cout << "Stack underflow" << endl;
        }
    }

    int peek() {
        if (top > -1) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1; 
        }
    }

    void print() {
        Stack temp;
        
        
        while (top > -1) {
            cout << peek() << " "; 
            temp.push(peek());
            pop();
        }
        
       
        while (temp.top > -1) {
            push(temp.peek());
            temp.pop();
        }
        cout << endl;
    }
    
    
    void seperate(){
        Stack even;
        Stack odd;
        
        while(top > -1){
            if(this->peek() & 1) // this is odd
                odd.push(this->peek());
            else
                even.push(this->peek());
            
            this->pop();
        }
        
        cout << "Printing Even stack: \n";
        even.print();
        
        cout << "\n\nPrinting Odd Stack: \n";
        odd.print();
        
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(3);
    s.push(20);
    s.push(5);
    s.push(30);
    s.push(19);
    s.print();
    // cout << "Top element: " << s.peek() << endl;
    // s.pop();
    s.print();
    cout << "Top element: " << s.peek() << endl; 
    s.seperate();
    
    return 0;
}
