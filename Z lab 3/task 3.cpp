#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr){
        this->data = data;
        next = next;
    }

    friend class SinglyLinkedList;
};

class SinglyLinkedList{
    public:
    Node* head;
    SinglyLinkedList() : head(nullptr){}

    void insertAtFront(int data){
        Node* newNode = new Node(data);
        newNode->next = head;

        head = newNode;
    };

    void print(){
        Node* temp = head;

        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void segregatedList(){
        Node* temp = head;
        Node* evenHead = nullptr;
        Node* even = nullptr;
        Node* oddHead = nullptr;
        Node* odd = nullptr;

        while(temp != nullptr){

            if(temp->data % 2 == 0){ // even
                // if it is the beginning of the even numners
                if(!evenHead){
                    evenHead = temp;
                    even = temp;
                }else{
                    even->next = temp;
                    even = even->next;
                }

            }else{
                // if it is the beginning of the odd numners
                if(!oddHead){
                    oddHead = temp;
                    odd = temp;
                }else{
                    odd->next = temp;
                    odd = odd->next;
                }
            }

            temp = temp->next;
        }

        even->next = oddHead;
        odd->next = nullptr;

        head = evenHead;
    }

};

int main(){
    SinglyLinkedList l1;

    cout << "working" << endl;
    l1.insertAtFront(6);
    l1.insertAtFront(7);
    l1.insertAtFront(1);
    l1.insertAtFront(4);
    l1.insertAtFront(5);
    l1.insertAtFront(10);
    l1.insertAtFront(12);
    l1.insertAtFront(8);
    l1.insertAtFront(15);
    l1.insertAtFront(17);

    cout << "Original\n";
    l1.print();

    l1.segregatedList();

    cout << "Printing Segregated list\n";
    l1.print();
}
