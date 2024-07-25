void levelOrder(Node* root, vector<int>& ans, int level){
    if(root == nullptr)
        return;
        
    // as we know after each recursion the level changes, and every next level starts from left
    if(level == ans.size()){
        ans.push_back(root->data);
    }
        
    level++; // or this can be at the recursion like levelOrder(... level+1) in both
    levelOrder(root->left, ans, level);
    levelOrder(root->right, ans, level);
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   levelOrder(root, ans, 0);
   return ans;
}
