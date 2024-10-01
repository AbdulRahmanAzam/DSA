#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool isEmpty(){
        return front == -1;
    }
    
    void enqueue(int data){
        if(front == (rear + 1) % size){
            cout << "Queue is full" << endl;
            return;
        }
        
        // for the very first step when it becomes empty
        if(front == -1)
            front = 0;
        
        // when rear is at size
        rear = (rear+1) % size;
        arr[rear] = data;
    }
    
    int dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty " << endl;
            return;
        }
        
        int res = arr[front];
        
        if(front == rear){ // making it empty again
            front = rear = -1;
        }else{ // when the front-1 is at size so making it 0
            front = (front + 1) % size;
        }
            
        return res;
    }
    
}
