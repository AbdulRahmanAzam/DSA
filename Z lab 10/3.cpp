ONE OF THE MOST DIFFICULT PROBLEM

https://leetcode.com/problems/merge-k-sorted-lists/submissions/1467385048
class Solution {
public:
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        for(auto list : lists){
            if(list)
                minHeap.push(list);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if(smallest->next)
                minHeap.push(smallest->next);
        }
        return dummy.next;
    }
};
