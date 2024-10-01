#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;
    
public:
    Queue(int size) : size(size) {
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }    
    
    bool isEmpty(){
        if(qfront == rear)
            return true;
        
        return false;
    }
    
    void enqueue(int data){
        if(rear == size)
            cout << "Queue is full" << endl;
        else{
            arr[rear] = data;
            rear++;
        }
    }
    
    int dequeue(){
        if(qfront == rear){
            return -1;
        }
        
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        
        if(qfront == rear)
            qfront = rear = 0;
        
        return ans;
    }
    
    int front(){
        if(qfront == rear)
            return -1;
        else
            return arr[qfront];
    }
};

int main() {
    Queue q(5); // Initialize a queue of size 5

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Trying to enqueue more than capacity
    q.enqueue(60); // Should print "Queue is full"

    // Dequeue elements
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 10
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 20

    // Check the front element
    cout << "Front element: " << q.front() << endl; // Should print 30

    // Dequeue remaining elements
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 30
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 40
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 50

    // Trying to dequeue from an empty queue
    cout << "Dequeued: " << q.dequeue() << endl; // Should print -1 (queue is empty)

    return 0;
}
