Node* constructDLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* curr = head;
        
        for(int i = 1; i < arr.size(); i++){
            Node* NewNode = new Node(arr[i]);
            curr->next = NewNode;
            NewNode->prev = curr;
            curr = NewNode;
        }
        return head;
    }
