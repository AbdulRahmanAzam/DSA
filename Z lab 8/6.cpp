https://leetcode.com/problems/recover-binary-search-tree/submissions/1458961548


class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* previous = nullptr;
    void inorder(TreeNode* root){
        if(!root)
            return;

        inorder(root->left);
        
        if(previous && previous->val > root->val){
            if(!first)
                first = previous;

            second = root;
        }
        previous = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if(first && second)
            swap(first->val, second->val);
    }
};
