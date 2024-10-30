#include <iostream>
#include <stack>
#include <queues>
#include <vector>
#include <string>
using namespace std;

class Ticket{
    public:
    int ticketID;
    string name;
    int priority;
    string description;
    auto timestampStart;
    string status;
    auto timestampClose;
    
    Ticket* next;
    
    Ticket(int ticketID, string name, int priority, string desc) : ticketID(ticketID), name(name), priority(priority), description(desc), timestampStart(time(nullptr)), status("open"), next(nullptr) {}
    
};

class service_request_management{
    public:
        Ticket* head;
        
        service_request_management() : head(nullptr) {}
        
        void addTicket(int ticketID, string name, int priority, string description){
            Ticket* newTicket = new Ticket(ticketID, name, priority, description);
            
            if(!head){
                head = newTicket;
            }else{
                head->next = newTicket;
                head = newTicket;
            }
        }
        
        void removeTicket(int ticketID){
            if(!head)
                return;
            
            if(head->ticketID == ticketID){
                Ticket* del = head;
                head = head->next;
                delete del;
                return;
            }
                
            Ticket* temp = head;
            
            while(temp->next != nullptr && temp->next->ticketID != ticketID){
                temp = temp->next;
            }
            Ticket* del = temp->next;
            temp = temp->next->next;
            delete del;
        }
        
        void searchTicket(int TicketID = 0, string name = ""){
            Ticket* temp = head;
            if(TicketID == 0 && !name.empty()){
                while(temp != nullptr){
                    if(temp->ticketID == ticketID){
                        temp.print();
                        return;
                    }
                    temp = temp->next;
                }
            }else if(TicketID != 0 && name.empty()){
                while(temp != nullptr){
                    if(temp->name == name){
                        temp.print();
                        return;
                    }
                    temp = temp->next;
                }
            }
        }
        
        void sortTickets(){
            int choice;
            cout <<"which sorting algorithm you want to use: Enter there number:\n1 Priority\n2 Creation Time \nCustomer Name" << endl << endl;
            
            cin >> choice;
            Ticket* temp = head;
            if(choice == 1){
                while(temp != nullptr){
                    Ticket* temp2 = temp;
                    while(temp2->next != nullptr){
                        if(choice == 1 && temp2->priority > temp2->next->priority){
                            swap(temp2->priority, temp2->next->priority);
                            
                        }else if(choice == 2 && temp2->timestampStart > temp2->next->timestampStart){
                            swap(temp2->timestampStart, temp2->next->timestampStart);
                            
                        }else if(choice == 3 && temp2->name > temp2->next->name){
                            swap(temp2->name, temp2->next->name);
                        }
                        temp2 = temp2->next;
                    }
                    temp = temp->next;
                }
            }
        }
};

class Agent{
    public:
        int ID;
        string name;
        vector<int> Tickets;
        bool availablity;
        string status;
        
        Agent(ID, name) : ID(ID), name(name), status("Available"), availability(True) {}
        
        void addTicket(int Ticket){
            if(Tickets.size() > 5){
                cout << "Agent is at full capacity" << endl;
                availability = false;
                status = "Unavailable"
            }else{
                status = "Available"
                Tickets.push_back(Ticket);
            }
        }        
}

class AgentManagement{
    public:
    vector<Agent> Agents;
    
    AgentManagement(){}
    
    void addAgent(int ID, string name){
        Agent newAgent = new Agent(ID, name);
        Agents.push_back(newAgent);
    }
    
    void AssignTickets(service_request_management list){
        Node* temp = list->head;
        
        // it is assigning high priority tickets first
        vector <pair <int, Ticket>> priorities;
        int i = 0;
        while(temp != nullptr){
            priorities[i++] = temp;
            temp = temp->next;
        }
        
        for(auto agent : Agents){
            // when the agent is available and the agent is already assigned some tasks already
            if(agent.availability == true && agent.Tickets.size() > 0){
                while(temp != nullptr && agent.availability == true){
                    agent.addTicket(temp->ID);
                   temp = temp->next;
                }
                
                // when the agent is available and it was not having any tickets assigned
            }else if(agent.availability() == true){
                while(temp != nullptr && agent.availability == true){
                    agent.addTicket(temp->ID);
                   temp = temp->next;
                }
            }
        }
    }
};

class TransactionLog{
    public:
    stack<int> Tlog;
    queue 
}

int main() {
    auto now = chrono::system_clock::now();
    
    
}


//     auto timestamp = std::chrono::system_clock::to_time_t(now);
