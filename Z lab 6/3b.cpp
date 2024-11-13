#include <bits/stdc++.h>
using namespace std;

// THe optimization we can do is, we can make a queue circular

#define SIZE 10

class TicketSystem{
    public:
    int front, rear;
    int *tickets;

    TicketSystem(){
        tickets = new int[SIZE];
        front = rear = -1;
    }

    bool isFull(){
        return (rear + 1) % SIZE == front;
    }
    
    bool isEmpty(){
        return front == -1;
    }

    void enqueue(int ID){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }

        if(isEmpty())
            front = 0;

        rear = (rear + 1) % SIZE;

        tickets[rear] = ID;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1) % SIZE;
        }
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Tickets are: \n";
        int i = front;
        while(true){
            if (i == rear) 
                break;
            
            i = (i + 1) % SIZE;
            cout << "\t" << tickets[i] << endl;
        }
        cout << endl;
    }

};

// THE MAIN IS MADE BY GPT
int main(){
    TicketSystem ts;

    // Add 10 passengers
    for (int i = 1; i <= 10; i++) {
        ts.enqueue(i);
    }

    ts.display();

    // Remove 5 passengers
    for (int i = 0; i < 5; i++) {
        ts.dequeue();
    }

    ts.display();

    // Attempt to add 5 more passengers
    for (int i = 11; i <= 15; i++) {
        ts.enqueue(i);
    }

    ts.display();

    return 0;
}
