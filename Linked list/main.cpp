





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

    public:
    Node* head;
        SinglyLinkedList() : head(nullptr) {}
        
    void insertAtFront(int data){
        head = new Node(data, head);
    }
    
    void print(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    
    void reverse(){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while(curr != nullptr){
            next = curr->next; // storing next node
            curr->next = prev; // reversing  current nodes pointer
            prev = curr; // move prev to curr
            curr = next; // move curr to next
        }
        head = prev;
    } 


     Node* findMin(Node* ptr){
        int mini = 1000000;
        
        Node* temp = ptr;
        while(temp){
            if(temp->data < mini){
                mini = temp->data;
            }
            temp = temp->next;
        }
        
        Node* temp2 = ptr;
        while(temp2){
            if(mini == temp2->data)
                return temp2;
            temp2 = temp2->next;
        }
        return nullptr;
    }

// not completed
    void sort(){
        Node* temp = head;
        
        bool swapped = true;
        Node* sorted = findMin(temp);
        while(swapped){
            swapped = false;
            
            Node* ptr1 = temp;
            
            sorted->next = findMin(temp->next);
            sorted = sorted->next;
            
            temp = temp->next;
        }
    }

    
    void recursiveReverse(){
        head = recursiveReverseHelper(head);
    }
    Node* recursiveReverseHelper(Node* head){
        if(head == nullptr || head->next == nullptr)
            return head;
            
        Node* newHead = recursiveReverseHelper(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
    
    
    void singlyToCircular(){
        Node* temp = head;
        
        while(temp->next){
            temp = temp->next;
        }
        
        temp->next = head;
    }
    
    
    void recursiveSinglyToCircular(){
        recursiveSinglyToCircularHelper(head);
    }
    void recursiveSinglyToCircularHelper(Node* curr){
        if(curr->next == nullptr){
            curr->next = head;
            return;
        }
        
        recursiveSinglyToCircularHelper(curr->next);
    }
    
    
    Node* reverseInGroupsHelper(Node* head, int k){
        if(head == nullptr)
            return head;
            
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;
        
        while(curr && count < k){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
            
            count++;
        }
        
        if(next != nullptr)
            head->next = reverseInGroupsHelper(next, k);
        
        return prev;
    }
    void reverseInGroups(int k){
        head = reverseInGroupsHelper(head, k);
    }
    
    
    Node* mergeTwoSortedLists(SinglyLinkedList b){
        Node* tempA = head;
        Node* tempB = b.head;
        
        Node* dummy = new Node();
        Node* curr = dummy;
        
        while(tempA && tempB){
            if(tempA->data < tempB->data){
                curr->next = new Node(tempA->data);
                tempA = tempA->next;
            }else{
                curr->next = new Node(tempB->data);
                tempB = tempB->next;
            }
                curr = curr->next;
        }
        
        while(tempA){
            curr->next = new Node(tempA->data);
            curr = curr->next;
            tempA = tempA->next;
        }
        
        while(tempB){
            curr->next = new Node(tempB->data);
            curr = curr->next;
            tempB = tempB->next;
        }
        return dummy->next;
    }
   
    Node* mergeTwoSortedListsByNode(SinglyLinkedList tempA ,SinglyLinkedList tempB){
        Node* a = tempA.head;
        Node* b = tempB.head;
        if(a == nullptr) return b;
        if(b == nullptr) return a;
        
        Node* head = nullptr;
        Node* tail = nullptr;
        
        if(a->data <= b->data){
            head = tail = a;
            a = a->next;
        }else{
            head = tail = b;
            b = b->next;
        }
        
        while(a && b){
            if(a->data < b->data){
                tail->next = a;
                tail = a;
                a = a->next;
            }else{
                tail->next = b;
                tail = b;
                b = b->next;
            }
        }
        
        tail->next = (a) ? a : b;
        return head;
    }
};

int main() {
    SinglyLinkedList l1;
    l1.insertAtFront(5);
    l1.insertAtFront(4);
    l1.insertAtFront(3);
    l1.insertAtFront(2);
    l1.insertAtFront(1);
    
    SinglyLinkedList a;
    a.insertAtFront(15);
    a.insertAtFront(10);
    a.insertAtFront(5);
    
    SinglyLinkedList b;
    b.insertAtFront(20);
    b.insertAtFront(3);
    b.insertAtFront(2);
    
    l1.print();
    l1.reverseInGroups(2);
    l1.print();
    
    SinglyLinkedList c;
    c.head = c.mergeTwoSortedListsByNode(a, b);
    cout << "working" << endl;
    c.print();
    
}
