class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        struct Node* curr = head;
        
        while(curr->next != nullptr){
            if(curr->data == curr->next->data){
                
                // skiping the deleted node
                curr->next = curr->next->next;
                
                // storing value of previous in next one node
                if(curr->next != nullptr)
                    curr->next->prev = curr;
                
            }else
                curr = curr->next;
        }
        
        return head;
    }
};
