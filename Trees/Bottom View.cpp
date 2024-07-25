
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int, int> mp;
        queue<pair<Node*, int>> que;
        vector<int> ans;
        
        que.push(make_pair(root, 0));
        
        while(!que.empty()){
            pair<Node*, int> temp = que.front();
            que.pop();
            
            Node* frontNode = temp.first;
            int horizontalDist = temp.second;
            
            mp[horizontalDist] = frontNode->data;
            
            if(frontNode->left)
                que.push(make_pair(frontNode->left, horizontalDist-1));
                
            if(frontNode->right)
                que.push(make_pair(frontNode->right, horizontalDist+1));
        }
        for(auto& i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
