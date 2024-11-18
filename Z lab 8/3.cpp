# COmpleted the same quesiton in leetcode
https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/1456061562/

class Solution {
public:
    int find(TreeNode* root, int& max_price){
        if(!root)
            return 0;

        int left = max(find(root->left, max_price), 0);
        int right = max(find(root->right, max_price), 0);

        max_price = max(max_price, root->val + left + right);

        return root->val + max(left, right);
    } 
    int maxPathSum(TreeNode* root) {
        int max_price = INT_MIN;
        find(root, max_price);
        return max_price;
    }
};
