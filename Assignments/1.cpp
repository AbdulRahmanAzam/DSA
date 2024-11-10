#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Ticket{
    public:
    int ID;
    string name;
    int priority;
    string description;
    string status;
    tm *creationTime;
    tm * closeTime;

    Ticket* next;

    Ticket(int ID = 0, string name = "", int priority = 0, string description = "") : ID(ID), name(name), description(description), priority(priority), status("Open") {
        creationTime = new tm;
        closeTime = NULL;
    }
};

class TicketManagement{
    public:
    Ticket* head;

    TicketManagement() : head(nullptr) {}

    void addTicket(int ID, string name, int priority, string description){
        Ticket* newTicket = new Ticket(ID, name, priority, description);

        // if the head is already empty then add only ticket and return
        if(this->head == nullptr){
            this->head = newTicket;
            return;
        }

        // if there are already some tickets in the  list, then add this ticket at the end
        Ticket* current = this->head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newTicket;
    }

    void removeTicket(int ticketID){
        // if the first ticket matches the ticket id
        if(head->ID == ticketID){
            Ticket* temp = head;
            head = head->next;
            delete temp;
        }

        // other tickets than the first ticket
        // whenever that ticket found then delete that ticket from the list and return
        Ticket* temp = head;
        while(temp->next != nullptr){
            if(temp->next->ID == ticketID){
                Ticket* temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                return;
            }
        }
    }

    void print(){
        Ticket* current = this->head;
        while(current != nullptr){
            cout << "ID: " << current->ID << endl;
            cout << "Name: " << current->name << endl;
            cout << "Priority: " << current->priority << endl;
            cout << "Description: " << current->description << endl;
            cout << "Statis: " << current->status << endl;
            cout << "Creation Time: " << current->creationTime << endl;
            cout << "Close Time: " << current->closeTime << endl;
            cout << endl;
            current = current->next;
        }
    }

    // Search by ID
    void searchTicket(int ticketID){
        Ticket* current = head;
        while(current != nullptr){
            if(current->ID == ticketID){
                cout << "Ticket ID: " << current->ID << endl;
                cout << "Ticket Name: " << current->name << endl;
                cout << "Ticket Priority: " << current->priority << endl;
                cout << "Ticket Status: " << current->status << endl;
                return;
            }
            current = current->next;
        }
    }

    //Search by Name
    void searchTicket(string name){
        Ticket* current = head;
        while(current != nullptr){
            if(current->name == name){
                cout << "Ticket ID: " << current->ID << endl;
                cout << "Ticket Name: " << current->name << endl;
                cout << "Ticket Priority: " << current->priority << endl;
                cout << "Ticket Status: " << current->status << endl;
                return;
            }
            current = current->next;
        }
    }

    // ------------------ BELOW ARE ALL THE SORTING ALGORITHMS ------------------

    // MERGE SORT
    Ticket* getMiddle(Ticket* head){
        if(!head)   return head;

        Ticket* slow = head;
        Ticket* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Ticket* merge(Ticket* left, Ticket* right, string attribute){
        if(!left) return right;
        if(!right) return left;

        Ticket* result = nullptr;

        if(attribute == "priority"){
            if(left->priority <= right->priority){
                result = left;
                result->next = merge(left->next, right, attribute);
            }else{
                result = right;
                result->next = merge(left, right->next, attribute);    
            }
        }else if(attribute == "creationTime"){
            if(left->creationTime <= right->creationTime){
                result = left;
                result->next = merge(left->next, right, attribute);
            }else{
                result = right;
                result->next = merge(left, right->next, attribute);  
            }
        }else if(attribute == "customerName"){
            if(left->name <= right->name){
                result = left;
                result->next = merge(left->next, right, attribute);
            }else{
                result = right;
                result->next = merge(left, right->next, attribute);  
            }
        }
        return result;
    }
    void mergeSort(Ticket** headRef, string attribute){   
        Ticket* head = *headRef;
        if(!head || !head->next)  return; 

        Ticket* mid = getMiddle(head);
        Ticket* left = head;
        Ticket* right = mid->next;
        mid->next = nullptr;

        mergeSort(&left, attribute);
        mergeSort(&right, attribute);

        *headRef = merge(left, right, attribute);
    }


    // Quick SORT
    Ticket* partition(Ticket* head, Ticket* tail, Ticket** newHead, Ticket** newTail, string attribute){
        Ticket* pivot = tail;
        Ticket* prev = nullptr;

        Ticket* curr = head;
        Ticket* end = pivot;

        while(curr != pivot){
            if((attribute == "priority" && curr->priority < pivot->priority) || 
            (attribute == "creationTime" && curr->creationTime < pivot->creationTime) ||
            (attribute == "customerName" && curr->name < pivot->name)){

                if(!*newHead) 
                    *newHead = curr;

                prev = curr;
                curr = curr->next;
            }else{
                if(prev)
                    prev->next = curr->next;

                Ticket* temp = curr->next;
                curr->next = nullptr;
                end->next = curr;
                end = curr;
                curr = temp;
            }
        }

        if(!*newHead)
            *newHead = pivot;

        *newTail = end;
        end->next = nullptr;
        return pivot;
    }
    Ticket* quicksortRec(Ticket* head, Ticket* tail, string attribute){
        if(!head || head == tail) return head;

        Ticket* newHead = nullptr;
        Ticket* newTail = nullptr;

        // partition the LL, all will be updated from partition
        Ticket* pivot = partition(head, tail, &newHead, &newTail, attribute);

        // sorting the left part first
        if(newHead != pivot){
            Ticket* temp = newHead;
            while(temp->next != pivot)
                temp = temp->next;
            temp->next = nullptr;

            newHead = quicksortRec(newHead, temp, attribute);

            // left part is sorted, linking it with pivot
            temp = newHead;
            while(temp->next) 
                temp = temp->next;
            temp->next = pivot;
        }

        // sorting the right part
        pivot->next = quicksortRec(pivot->next, newTail, attribute);

        return newHead;
    }
    Ticket* getTail(Ticket* head){
         Ticket* current = head;
        while(current->next){
            current = current->next;
        }
        return current;
    }
    void quicksort(Ticket** headRef, string attribute){
        *headRef = quicksortRec(*headRef, getTail(*headRef), attribute);
    }


    // BUBBLE SORT
    void swapNodes(Ticket** headRef, Ticket* a, Ticket* b){
        if(a == b)
            return;

        Ticket* prev1 = nullptr;
        Ticket* prev2 = nullptr;
        Ticket* temp = *headRef;

        while(temp){
            if(temp->next == a)
                prev1 = temp;

            if(temp->next == b)
                prev2 = temp;

            temp = temp->next;
        }

        if(prev1)
            prev1->next = b;
        else
            *headRef = b;

        if(prev2)
            prev2->next = a;
        else
            *headRef = a;

        Ticket* swapp = a->next;
        a->next = b->next;
        b->next = swapp;
    }
    void bubbleSort(Ticket** headRef, string attribute){
        if(!*headRef) return;

        bool swapped = true;
        

        while(swapped){
            swapped = false;
            Ticket* temp = head;

            while(temp->next){
                 if ((attribute == "priority" && temp->priority > temp->next->priority) ||
                (attribute == "creationTime" && temp->creationTime > temp->next->creationTime) ||
                (attribute == "customerName" && temp->name > temp->next->name)) {
                
                swapNodes(headRef, temp, temp->next);
                swapped = true;
                
                } else {
                    temp = temp->next;
                }
            }
        }
    }
    
    
    // SelectionSort
    void selectionSort(Ticket** headRef, string attribute){
        Ticket* head = *headRef;

        if(!head)
            return;

        Ticket* curr1 = head;
        while(curr1){
            Ticket* curr2 = curr1->next;
            Ticket* min = curr1;

            while(curr2){
                if((attribute == "priority" && curr2->priority < min->priority) || 
                (attribute == "creationTime" && curr2->creationTime < min->creationTime) ||
                (attribute == "customerName" && curr2->name < min->name)){

                   min = curr2;
                }

                curr2 = curr2->next;
            }
            if(min != curr1){
                swapNodes(headRef, curr1, min);
                curr1 = min;
            }else
                curr1 = curr1->next;
        }
    }
    
    
    // INSERTION SORT
    void insertionSort(Ticket** headRef, string attribute){
        Ticket* head = *headRef;
        if(!head)
            return;

        Ticket* sorted = nullptr;
        Ticket* curr = head;

        while(curr){
            Ticket* next = curr->next;

            if(!sorted || (attribute == "priority" && curr->priority < sorted->priority) || 
                (attribute == "creationTime" && curr->creationTime < sorted->creationTime) ||
                (attribute == "customerName" && curr->name < sorted->name)){

                    curr->next = sorted;
                    sorted = curr;

            }else{
                Ticket* prev = sorted;

                while(prev->next && 
                ((attribute == "priority" && curr->priority >= prev->next->priority) || 
                (attribute == "creationTime" && curr->creationTime >= prev->next->creationTime) ||
                (attribute == "customerName" && curr->name >= prev->next->name))){
                    prev = prev->next;
                }
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = next;
        }
        *headRef = sorted;
    }
    
    
    void sortTickets(int choice, string attribute){
        if(choice == 1){
            mergeSort(&head, attribute);
        }else if(choice == 2){
            quicksort(&head, attribute);
        }else if(choice == 3){
            bubbleSort(&head, attribute);
        }else if(choice == 4){
            selectionSort(&head, attribute);
        }else if(choice == 5){
            insertionSort(&head, attribute);
        }else {
            cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }

    void configurationFile(){
        ifstream inputFile("config.txt");
        if (!inputFile) {
            cerr << "Unable to open file config.txt";
            return ; 
        }
        string  choice = "1";
        string  attribute = "merge";
        string line1, line2, line3; 
        int threshold = 21;
        if (getline(inputFile, line1) && getline(inputFile, line2) && getline(inputFile, line3)) {
            choice = line1;
            attribute = line2;
            threshold = stoi(line3);
        }
        inputFile.close();
        
        if(threshold < 15){
            sortTickets(stoi(choice), attribute);
        }else{
            // mergesort
            sortTickets(1, attribute);
        }
    }

    ~TicketManagement(){
        // all the nodes of the linked list is deleted
        while(head){
            Ticket* next = head->next;
            delete head;
            head = next;
        }
    }
};

class Agent{
    public:
    int ID;
    string name;
    bool isAvailable;
    int openTickets;
    const int MaxOpenTickets = 5;
    vector<int> TicketID;

// default and parametrized constructor
    Agent(int ID = 0, string name = "") : ID(ID), name(name), isAvailable(true), openTickets(0) {}

    void print(){
        cout << "Agent ID: " << ID << endl;
        cout << "Agent Name: " << name << endl;
        cout << "Agent isAvaailable? " << (isAvailable ? "True" : "False") << endl;
        cout << "Agent have Open Tickets: " << openTickets << endl;
        cout << "Agent have the following tickets: " << endl;

        for(auto x : TicketID){
            cout << x << " ";
        }

        cout << "\n\n";
    }
};

class AgentManagement{
    public:
    vector<Agent> agents;

    void addAgent(int ID, string name){
        // making new agent and adding it to the dynamic array
        Agent newAgent(ID, name);
        agents.push_back(newAgent);
    }

    void assignTickets(int ticketID){
        // if the agent is availabel and it has less open tickets than maxopenTickets
        // then assign it a ticket and increase openTickets
        // and check if the open ticket is equals to maxopenticket then make it unavailable

        // if it has already some ticket then assign it first
        for(auto& x : agents){
            if(x.isAvailable && x.openTickets != 0 && x.openTickets < x.MaxOpenTickets){
                x.TicketID.push_back(ticketID);
                x.openTickets++;
                
                if(x.openTickets == x.MaxOpenTickets)
                    x.isAvailable = false;
                    
                cout << "Ticket " << ticketID << " assigned to Agent " << x.ID << endl;
                return;
            }
        }

        // if it is not having any ticket previously
        for(auto& x : agents){
            if(x.isAvailable && x.openTickets == 0 && x.openTickets < x.MaxOpenTickets){
                x.TicketID.push_back(ticketID);
                x.openTickets++;
                
                if(x.openTickets == x.MaxOpenTickets)
                    x.isAvailable = false;
                    
                cout << "Ticket " << ticketID << " assigned to Agent " << x.ID << endl;
                return;
            }
        }

        cout << "No Agent is freee" << endl;
    }

    void printAgents(){
        for(auto x : agents){
            x.print();
        }
    }
};

class resolutionLog{
    public:
    // here vector is used instead of array
    // as array needs to have another integer of n
    // which will take its total size
    // so using vector for simplicity
    vector<Ticket> log;
    int top;

    resolutionLog() : top(-1) {}

    void push(Ticket* ticket){
        log.push_back(*ticket);
        ++top;
    }

    void pop(){
        if(top == -1){
            cout << "stack is empty" << endl;
        }else{
            log.pop_back();
            top--;
        }
    }
    Ticket peek(){
        if(top == -1){
            cout << "stack is empty" << endl;
            return Ticket();
        }else{
            return log[top];
        }
    }
    bool isEmpty(){
        return top == -1;
    }
};

class PendingTicket{
    public:
    int cap;
    int front;
    int rear;
    vector<Ticket> pendings;

    PendingTicket() : cap(1000){
        front = rear = -1;
    }

    void enqueue(Ticket ticket){
        if((rear + 1) % cap == front){
            cout << "queue is full" << endl;
        }else{
            if(front == -1)
                front = 0;

            rear = (rear + 1) % cap;
            pendings.push_back(ticket);
        }
    }

    Ticket dequeue(){
        if(rear == -1  || front == -1 || front > rear){
            cout << "Queue is empty" << endl;
            return Ticket();
        }else{
            Ticket ticket = pendings[front];
            pendings.erase(pendings.begin() + front);
            front = (front + 1) % cap;
            return ticket;
        }
    }

    Ticket Front(){
        if(rear == -1 || front == rear){
            cout << "Queue is Empty" << endl;
        }else{
            return pendings[front];
        }
    }

    bool isEmpty(){
        return (rear == -1 || front == rear);
    }

    bool isFull(){
        return (rear + 1) % cap == front;
    }
};

int main() {
    // Step 1: Initialize the classes
    TicketManagement tm;
    AgentManagement am;
    resolutionLog rl;
    PendingTicket pt;

    // Step 2: Add sample tickets
    cout << "Adding tickets to the Ticket Management system..." << endl;
    tm.addTicket(1, "Alice", 3, "Issue with login");
    tm.addTicket(2, "Bob", 1, "System crash");
    tm.addTicket(3, "Charlie", 2, "Password reset required");

    // Add sample agents
    cout << "Adding agents to the Agent Management system..." << endl;
    am.addAgent(101, "Agent Smith");
    am.addAgent(102, "Agent Johnson");

    // Step 3: Assign tickets to agents
    cout << "Assigning tickets to agents..." << endl;
    am.assignTickets(1);
    am.assignTickets(2);

    // Step 4: Enqueue some tickets in the pending queue
    cout << "Adding tickets to the pending queue..." << endl;
    pt.enqueue(*tm.head); // Add the first ticket
    pt.enqueue(*(tm.head->next)); // Add the second ticket

    // Step 5: Sorting tickets
    cout << "Choose a sorting algorithm:\n1. Merge Sort\n2. Quick Sort\n3. Bubble Sort\n4. Selection Sort\n5. Insertion Sort" << endl;
    int choice;
    cin >> choice;

    cout << "Enter attribute to sort by (priority, creationTime, customerName): ";
    string attribute;
    cin >> attribute;

    tm.sortTickets(choice, attribute);
    
    cout << "\nTickets after sorting by " << attribute << ":\n";
    tm.print();

    // Step 6: Resolve tickets
    cout << "Resolving tickets and moving them to the resolution log..." << endl;
    while (!pt.isEmpty()) {
        Ticket resolvedTicket = pt.dequeue();
        rl.push(&resolvedTicket);
    }

    cout << "\nResolved tickets:\n";
    while (!rl.isEmpty()) {
        Ticket ticket = rl.peek();
        cout << "Resolved Ticket ID: " << ticket.ID << ", Name: " << ticket.name << endl;
        rl.pop();
    }

    // Display agents and their assigned tickets
    cout << "\nCurrent agents and their tickets:\n";
    am.printAgents();

    return 0;
}
