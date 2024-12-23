#include <bits/stdc++.h>
using namespace std;


// --------------------------------- SINGLY LINKED LIST ---------------------------------
// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int data= 0, Node* next = nullptr) : data(data), next(next) {}
// };

// class SinglyLinkedList{
//     public:
//     Node* head;

//     SinglyLinkedList(){
//         head = nullptr;
//     }

//     void insertAtEnd(int value){
//         Node* newNode = new Node(value);

//         if(!head){
//             head = newNode;
//             return;
//         }

//         Node* temp = head;
//         while(temp->next != nullptr){
//             temp = temp->next;
//         }

//         temp->next = newNode;
//     }

//     void insertAtHead(int value){
//         Node* newNode = new Node(value, head);

//         head = newNode;
//     }

//     void display(){
//         Node* temp = head;

//         while(temp != nullptr){
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//     }
// };



// --------------------------------- DOUBLY LINKED LIST ---------------------------------
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node* prev;

//     Node(int data= 0, Node* prev = nullptr, Node* next = nullptr) : data(data), next(next),  prev(prev) {} 
// };

// class DoublyLinkedList{
//     public:
//     Node* head;
//     DoublyLinkedList(){
//         head = nullptr;
//     }

//     void insertNodeAtEnd(int value){
//         Node* newNode = new Node(value);

//         if(!head){
//             head = newNode;
//             return;
//         }

//         Node* temp = head;
//         while(temp->next != nullptr){
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         newNode->prev = temp;
//     }

//     void insertAtHead(int value){
//         Node* newNode = new Node(value, nullptr, head);
//         head->prev = newNode;

//         head = newNode;
//     }

//     void deleteNode(int value){
//         if(!head){
//             cout << "List is emptyy" << endl;
//             return;
//         }

//         if(head->data == value){
//             Node* toDelete = head;
//             head = head->next;

//             if(head != nullptr) head->prev = nullptr;
//             delete toDelete;
//             return;
//         }

//         Node* temp = head;
//         while(temp != nullptr && temp->data != value){
//             temp = temp->next;
//         }

//         if(temp == nullptr){
//             cout << "Not found" << endl;
//             return;
//         }

//         if(temp->next != nullptr) temp->next->prev = temp->prev;
//         if(temp->prev != nullptr) temp->prev->next = temp->next;
//         delete temp;
//     }
// }

// --------------------------------- CIRCULAR SINGLY LINKED LIST ---------------------------------
class Node{
    public:
    int data;
    Node* next;

    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {} 
};

class CircularSinglyLinkedList{
    public:
    Node* head;

    CircularSinglyLinkedList(){
        head = nullptr;
    }

    void insertAtEnd(int value){
        Node* newNode = new Node(value);

        if(!head){
            cout << "Empty" << endl;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head; // for circular;
    }

    void deleteNode(int value){
        if(head== nullptr){
            cout <<"list is empty" << endl;
            return;
        }

        if(head->data == value){ // first element to remove
            Node* toDelete = head;


            if(head->next == head){ // only one element left
                head = nullptr;
            }else{
                Node* last = head;
                while(last->next != head){
                    last = last->next;
                }

                head =  head->next; // leaving what to delete
                last->next = head;
            }
            delete toDelete;
            return;
        }

        Node* temp = head;
        while(temp->next != head && temp->next->data != value){
            temp = temp->next;
        }

        if(temp == head){
            cout << "Not found" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void display(){
        Node* temp = head;
        do{
            cout << temp->data << " ";
            temp = temp->next; 
        }while(temp != head);
    }
}



int main(){

}