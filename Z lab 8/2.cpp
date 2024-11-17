# i have done the type of same question in leetcode
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/1331255117

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> que;
        que.push(root);

        bool rightToLeft = true;
        while(!que.empty()){
            int size = que.size();
            vector<int> ans(que.size());

            for(int i = 0;i < size; i++){
                TreeNode* frontData = que.front();
                que.pop();

                // doing this to get in the right order
                int index = rightToLeft ? i : size - i - 1;
                ans[index] = frontData->val;

                if(frontData->left)
                    que.push(frontData->left);

                if(frontData->right)
                    que.push(frontData->right);
            }
            rightToLeft = !rightToLeft;

            result.push_back(ans);
        }
        return result;
    }
};
