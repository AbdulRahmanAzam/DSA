# completed in the leetcode
[LEETCODE SOLVED LINK](https://leetcode.com/problems/subtree-of-another-tree/submissions/1456265038


class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* sub){
        if(!root || !sub)
            return root == nullptr && sub == nullptr;

        if(root->val != sub->val)
            return false;

        return dfs(root->left, sub->left) && dfs(root->right, sub->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* sub) {
        // if root is empty but subtree didnt found then return false
        if(!root)
            return false;

        // if there dfs is same then always true, as it checks all the elements below root
        if(dfs(root, sub))
            return true;

        // reducing root one by one from left and right, and then passing to the dfs to get the answer
        return isSubtree(root->left, sub) || isSubtree(root->right, sub);
    }
};
