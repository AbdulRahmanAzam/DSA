#include <iostream>
using namespace std;

class Stack{
    int top;
    int *arr;
    int maxSize;
    
    public:
    Stack(int size){
        top = -1;
        arr = new int[size];
        maxSize = size;
    }
    
    bool isfull(){
        return top == maxSize - 1;
    }
    
    bool isEmpty(){
        return top == -1;
    }
    
    void push(int n){
        if(isfull()){
            cout << "stack is full" << endl;
        }else{
            top++;
            arr[top] = n;
            cout << n << " is pushed into the stack\n";
        }
    }
    
    void pop(){
        if(isEmpty()){
            cout << "Stack is empty" << endl; 
        }else{
            cout << arr[top] << " popped from the stack\n";
            top--;
        }
    }
    
    int peek(){
       if(!isEmpty()){
           return arr[top]; 
       }else{
           cout << "Stack is empty\n";
       }
       return -1;
    }
    
};

int main() {
    Stack s(10);
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
