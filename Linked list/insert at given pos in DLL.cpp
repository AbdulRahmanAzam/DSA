void addNode(Node *head, int pos, int data)
{   
    while(pos--){
        head = head->next;
    }
    
    Node* newNode = new Node(data);
    
    if(head->next == nullptr){
        newNode->prev = head;
        head->next = newNode;
    }else{
        // stored value of another one
        Node* tempN = head->next;
        
        // storing values of head and newNode prev
        newNode->prev = head;
        head->next = newNode;
        
        // storing values of next head's prev and newNode's next
        newNode->next = tempN;
        tempN->prev = newNode;
    }
}
