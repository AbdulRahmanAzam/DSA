#include <iostream>

using namespace std;

class Node {
    int data;
    Node* next;

    public:
        Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}

        friend class SinglyLinkedList;
};

class SinglyLinkedList {
    Node* head;

    public:
        SinglyLinkedList() : head(nullptr) {}

        void insertAtFront(int data) {
            head = new Node(data, head);
        }

        void insertAtEnd(int data) {
            Node* newNode = new Node(data);
            if(!head) {
                head = newNode;
            } else {
                Node* curr = head;
                while(curr->next) {
                    curr = curr->next;
                }
                curr->next = newNode;
            }
        }

        void insertBeforedataue(int targetdata, int insertdata) {
            if(head->data == targetdata) {
                head = new Node(insertdata, head);
            } else {
                Node* curr = head;
                while(curr->next->data != targetdata) {
                    curr = curr->next;
                }
                curr->next = new Node(insertdata, curr->next);
            }
        }

        void insertAfterdataue(int targetdata, int insertdata) {
            Node* curr = head;
            while(curr->data != targetdata) {
                curr = curr->next;
            }
            curr->next = new Node(insertdata, curr->next);
        }

        void deleteAtFront() {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void deleteAtEnd() {
            Node* curr = head;
            while(curr->next->next) {
                curr = curr->next;
            }

            Node* temp = curr->next;
            curr->next = nullptr;
            delete temp;
        }

        void deleteParticulardataue(int data) {
            if(data == head->data) {
                deleteAtFront();
            } else {
                Node* curr = head;
                while(curr->next->data != data) {
                    curr = curr->next;
                }

                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
        }

        int countNodes() {
            int count = 0;
            for(Node* curr = head; curr; curr = curr->next) {
                ++count;
            }
            return count;
        }

        void printList() {
            for(Node* curr = head; curr; curr = curr->next) {
                cout << curr->data << " -> ";
            }
            cout << "NULL" << endl;
        }

        ~SinglyLinkedList() {
            while(head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

int main() {
    SinglyLinkedList sll;
    sll.insertAtFront(1);
    sll.insertAtFront(2);
    sll.insertAtFront(3);
    sll.insertAtFront(4);

    sll.printList();

    sll.insertAtEnd(5);
    sll.insertAtEnd(6);
    sll.insertAtEnd(7);
    sll.insertAtEnd(8);

    sll.printList();

    sll.insertBeforedataue(5, 9);
    sll.insertAfterdataue(2, 10);

    sll.printList();

    sll.deleteAtFront();
    sll.deleteAtEnd();
    sll.deleteParticulardataue(1);

    sll.printList();

    cout << endl << "Number of nodes in list : " << sll.countNodes() << endl;

    return 0;
}
