#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}
};

class DoublyLinkedList{
    public:
    Node* head;

    DoublyLinkedList() : head(nullptr){}

// Sort by  values
    // void sort(){
    //     if (head == nullptr) return;

    //     for(Node* temp = head; temp; temp = temp->next){

    //         Node* current = temp;
    //         while(current != nullptr){
    //             if(temp->data > current->data){
    //                 swap(temp->data, current->data);
    //             }
    //             current = current->next;
    //         }
    //     }
    // }


// sort by nodes
void sort() {
        Node* last_sorted = nullptr;
        Node* current = head;
        if (not current or not current->next) return;

        while (current) {
            Node* min_node = find_min(current);
            if (min_node == current) {
                last_sorted = current;
                current = current->next;
                continue;
            }

            if (min_node == tail)
                tail = min_node->prev;
            if (min_node->prev)
                min_node->prev->next = min_node->next;
            if (min_node->next)
                min_node->next->prev = min_node->prev;
            min_node->next = current;
            min_node->prev = last_sorted;
            if (last_sorted)
                last_sorted->next = min_node;
            else
                last_sorted = min_node, head = min_node;
            current->prev = min_node;
            last_sorted = min_node;
        }

        // removing duplicates
        current = head;
        while (current->next) {
            if (current->value == current->next->value) {
                Node* temp = current->next;
                if (temp == tail)
                    tail = current;
                current->next = current->next->next;
                if (current->next)
                    current->next->prev = current;
                delete temp;
            } else
                current = current->next;
        }
    }

    void removeDuplicates(){

        for(Node* temp = head; temp; temp = temp->next){
            Node* curr = temp;
            
            while(curr->next != nullptr){
                if(curr->data == curr->next->data){
                    Node* duplicate = curr->next;
                    curr->next = curr->next->next;
                    delete duplicate;
                }else{
                    curr = curr->next;
                }
            }
        }
    }
   

    void insertAtFront(int data){
        Node* newNode = new Node(data);

        if(!head){
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;

        head = newNode;
    }

    void print(){
        Node* temp = head;

        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl << endl;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.insertAtFront(1);
    dll.insertAtFront(5);
    dll.insertAtFront(2);
    dll.insertAtFront(5);
    dll.insertAtFront(3);
    dll.insertAtFront(4);
    dll.insertAtFront(5);

    dll.print();

    dll.sort();

    cout << "Sorted array \n";
    dll.print();

    dll.removeDuplicates();
    cout << "Removed Duplicates\n";
    dll.print();
}
