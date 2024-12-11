
class Solution {
public:
    void leftTraversal(Node* root, vector<int>& ans){
        if(!root || (root->left == nullptr && root->right == nullptr))
            return;
            
        ans.push_back(root->data);
        if(root->left)
            leftTraversal(root->left, ans);
        else 
            leftTraversal(root->right, ans);
    }
    
    void LeafNodesOnly(Node* root, vector<int>& ans){
        if(!root)
            return;
            
        if(root->left == nullptr && root->right == nullptr)
            ans.push_back(root->data);
            
        LeafNodesOnly(root->left, ans);
        LeafNodesOnly(root->right, ans);
    }
    
    void rightTraverse(Node* root, vector<int>& ans){
        if(!root || (root->left == nullptr && root->right == nullptr))
            return;
            
        if(root->right)
            rightTraverse(root->right, ans);
        else
            rightTraverse(root->left, ans);
            
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {   
        vector<int> result;
        if(!root)
            return result;
            
        result.push_back(root->data);
            
        leftTraversal(root->left, result);
        
        LeafNodesOnly(root->left, result);
        LeafNodesOnly(root->right, result);
        
        rightTraverse(root->right, result);
        
        return result;
    }
};
