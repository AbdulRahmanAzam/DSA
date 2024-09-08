#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}

    friend class DoublyLinkedList;
};

class DoublyLinkedList{
    public:
    Node* head;

    DoublyLinkedList(): head(nullptr){};

    void insertAtFront(int data){
        Node* newNode = new Node(data);

        if(head == nullptr){
            head = newNode;
            return;
        }
            
        newNode->next = head;
        head->prev = newNode;

        head = newNode;
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(!head){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertBefore(int data, int before){
        Node* temp = head;

        while(temp->next != nullptr){
            if(temp->next->data == before){
                Node* newNode = new Node(data, temp, temp->next);
                temp->next = newNode;

                temp = temp->next;
                if(temp->next != nullptr){  
                    temp->next->prev = temp;

                }
            }
            temp = temp->next;
        }
    }

    void insertAfter(int data, int after){
        Node* temp = head;

        while(temp != nullptr){
            if(temp->data == after){
                Node* newNode = new Node(data, temp, temp->next);
                temp->next = newNode;

                temp = temp->next;

                if(temp->next != nullptr){
                    temp->next->prev = newNode;
                    // newNode->next = temp->next;
                }
            }
            temp = temp->next;
        }
    }

    void print(){
        Node* temp = head;

        while(temp != nullptr){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteHead(){
        if(head == nullptr){
            cout << "List is empty" << endl;
        }

        Node* temp = head;
        // delete temp;
        head = head->next;
        head->prev = nullptr;
    }

    void deleteLast(){
        if(head == nullptr){
            cout << "List is empty" << endl;
        }

        Node* temp = head;

        while(temp->next->next != nullptr){
            temp = temp->next;
        }

        temp->next = nullptr;
    }

    void deleteNode(int data){
        Node* temp = head;

        while(temp->next != nullptr){
            if(temp->next->data == data){
                temp->next = temp->next->next;
                temp->next->next->prev = temp->next;
            }else
                temp = temp->next;
        }
    }
};

int main(){
    DoublyLinkedList dll;

    dll.insertAtFront(1);
    dll.insertAtFront(2);

    dll.insertAtEnd(5);
    dll.insertAtEnd(2);
    dll.insertAfter(4, 1);

    dll.insertBefore(3, 1);
    dll.print();
    dll.deleteHead();

    dll.print();
    dll.deleteLast();

    // dll.deleteNode();
    dll.print();
}
