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

    Ticket(int ID, string name, int priority, string description) : ID(ID), name(name), description(description), priority(priority), status("Open") {
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

    ~TicketManagement(){
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

    Agent(int ID, string name) : ID(ID), name(name), isAvailable(true), openTickets(0) {}

};

class AgentManagement{
    public:
    vector<Agent> agents;

    void addAgent(int ID, string name){
        Agent newAgent(ID, name);
        agents.push_back(newAgent);
    }

    void assignTickets(){
        
    }
}

int main(){
    TicketManagement tm;

    // Add sample tickets
    tm.addTicket(1, "Alice", 3, "Issue with login");
    tm.addTicket(2, "Bob", 1, "System crash");
    tm.addTicket(3, "Charlie", 2, "Password reset required");

    cout << "Tickets before sorting:\n";
    tm.print();

    cout << "Which sorting algorithm do you wanna use? \nMergeSort (1)\nQuicksort (2) \nBubbleSort (3) \nSelectionSort (4) \nInsertion Sort (5)" << endl;
    int choice;
    cin >> choice;


    cout << "Enter sorting attribute (priority, creationTime, customerName): ";
    string attribute;
    cin >> attribute;


    tm.sortTickets(choice, attribute);
   


    cout << "\nTickets after sorting by " << attribute << ":\n";
    tm.print();

}
