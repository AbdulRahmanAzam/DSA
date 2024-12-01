https://leetcode.com/problems/sliding-window-maximum/submissions/1467339040
// COMPLETED

class Solution {
public:
// USING DEQUEUE
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     deque<int> deq;
    //     vector<int> result;

    //     for(int i=0; i < n; i++){
            
    //         // deleting the first inserted elements
    //         while(!deq.empty() && deq.front() <= i - k)
    //             deq.pop_front();

    //         // deleting the last inserted elements
    //         // MONOTONIC DECREASING
    //         while(!deq.empty() && nums[i] > nums[deq.back()])
    //             deq.pop_back();

    //         // inserting the index
    //         deq.push_back(i);

    //         if(i >= k-1){
    //             result.push_back(nums[deq.front()]);
    //         }
    //     }
    //     return result;
    // }



    // USING HEAPS T.C O(n log(k))
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> maxHeap;

        for(int i=0; i < nums.size(); i++){

            maxHeap.push({nums[i], i});

            while(!maxHeap.empty() && maxHeap.top().second <= i-k){
                maxHeap.pop();
            }

            if(i >= k-1)
                result.push_back(maxHeap.top().first);
        }
        return result;
    }
};
