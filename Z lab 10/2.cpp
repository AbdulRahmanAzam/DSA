https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1467372063

class Solution {
public:
//  JUGAAR SOLUTION
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size()-k];
    // }

    int findKthLargest(vector<int>& nums, int k) {
        // should explicitly mention vector because explicity mentioning greater
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 0; i < nums.size(); i++){
            minHeap.push(nums[i]);

            // since max is storing from right to left, in this way if k exceeds then all the element from left is removed
            if(minHeap.size() > k)
                minHeap.pop();
        }
        // the element which is at the left will be return
        return minHeap.top();
    }
};
