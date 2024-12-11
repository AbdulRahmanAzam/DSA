class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> topNode;
        vector<int> ans;
        queue<pair<Node*, int>> que;
        
        que.push(make_pair(root, 0));
        
        while(!que.empty()){
            pair<Node*, int> frontN = que.front();
            que.pop();
            
            Node* temp = frontN.first;
            int horizontalDist = frontN.second;
            
            // if nothing is present at that position then add temp->data
            if(topNode.find(horizontalDist) == topNode.end())
                topNode[horizontalDist] = temp->data;
            
            if(temp->left)
                que.push(make_pair(temp->left, horizontalDist-1));
                
            if(temp->right)
                que.push(make_pair(temp->right, horizontalDist+1));
        }
        for(auto& i : topNode){
            ans.push_back(i.second);
        }
        return ans;
    }
};
