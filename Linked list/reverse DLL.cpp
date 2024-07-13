Node* reverseDLL(Node * head)
    {
        Node* newHead = nullptr;
        while(head != nullptr){
            Node* temp = head->next;
            head->next = head->prev;
            head->prev = temp;
            
            newHead = head;
            head = head->prev;
        }
        return newHead;
    }
