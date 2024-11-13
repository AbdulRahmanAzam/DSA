#include <bits/stdc++.h>
using namespace std;

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
        return rear == SIZE-1;
    }
    
    bool isEmpty(){
        return front == -1 || front > rear;
    }

    void enqueue(int ID){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }

        if(isEmpty())
            front = 0;

        tickets[++rear] = ID;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        front++;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Tickets are: \n";
        for(int i = 0; i < SIZE; i++){
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
