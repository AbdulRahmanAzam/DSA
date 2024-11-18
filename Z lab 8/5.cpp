
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1456331238

class Solution {
public:
    TreeNode* convert(vector<int>& nums, int s, int e){
        if(s > e){
            return nullptr;
        }

        int mid = (s + e)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = convert(nums, s, mid - 1);
        root->right = convert(nums, mid + 1, e);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert( nums, 0, nums.size()-1);
    }
};
