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
