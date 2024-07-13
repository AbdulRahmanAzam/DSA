class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        Node* curr = head;
        
        if(x == 1){
            head = head->next;
            if(head != nullptr) head->prev = nullptr;
            return head;
        }
        
        while(--x >= 1 && curr){
            curr = curr->next;
        }
        
        if(curr == nullptr) return head;
        
        if(curr->next != nullptr) curr->next->prev = curr->prev;
        if(curr->prev != nullptr) curr->prev->next = curr->next;
        
        return head;
    }
};
