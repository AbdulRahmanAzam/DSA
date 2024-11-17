# I have done this question in leetcode
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/1455686428


class Codec {
public:


    void buildString(TreeNode* root, string& s){
        if(!root){
            s += "null,";
            return;
        }

        s += to_string(root->val) + ',';
        buildString(root->left, s);
        buildString(root->right, s);        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        buildString(root, s);
        return s;    
    }

    TreeNode* buildTree(queue<string>& q){
        string s = q.front();
        q.pop();

        if(s == "null")
            return nullptr;

        TreeNode* newRoot = new TreeNode(stoi(s));
        newRoot->left = buildTree(q);
        newRoot->right = buildTree(q);

        return newRoot;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s = "";
        queue<string> q;

        for(char c : data){
            if(c == ','){
                q.push(s);
                s= "";
            }else{
                s += c;
            }
        }
        return buildTree(q);
    }
};
