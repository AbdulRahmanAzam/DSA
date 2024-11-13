#include <bits/stdc++.h>
using namespace std;

// THe optimization we can do is, we can make a queue circular


class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


class TicketSystem{
    public:
    Node* front;
    Node* rear;

    TicketSystem() : front(nullptr), rear(nullptr) {}

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(int ID){
        Node* newTicket = new Node(ID);

        if(isEmpty()){
            front = rear = newTicket;
        }else{
            rear->next = newTicket;
            rear = newTicket;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        front = front->next;
        delete temp;

        if(front == nullptr) 
            rear = nullptr;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        cout << "Ticket are: \n";
        while(temp){
            cout << "\t" << temp->data << endl;
            temp = temp->next;
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
