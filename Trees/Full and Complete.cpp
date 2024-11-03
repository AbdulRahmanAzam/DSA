#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class FullBinaryTree{
    public:
    Node* root;
    
    FullBinaryTree() : root(nullptr) {}
    
    void insert(Node*& root, int data){
        if(!root){
            root = new Node(data);
            return;
        }
        
        if(!root->left)
            insert(root->left, data);
        else if(!root->right)
            insert(root->right, data);
        else
          insert(root->left, data);
    }
    
    void levelOrder(Node* root){
        if(!root) return;
            
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            
            if(current->left)
                q.push(current->left);
                
            if(current->right)
                q.push(current->right);
        }
    }
};


class CompleteBinaryTree{
    public:
    Node* root;
    
    CompleteBinaryTree() : root(nullptr){}
    
    void insert(int data){
        if(!root){
            root = new Node(data);
            return;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            
            if(!current->left){
                current->left = new Node(data);
                return;
            }else
                q.push(current->left);
                
            if(!current->right){
                current->right = new Node(data);
                return;
            }else{
                q.push(current->right);
            }
        }
    }
    
    void levelOrder(){
        if()
    }
}

int main(){
    FullBinaryTree fbt;
    fbt.insert(fbt.root, 1);
    fbt.insert(fbt.root, 2);
    fbt.insert(fbt.root, 3);
    fbt.insert(fbt.root, 4);
    fbt.insert(fbt.root, 5);
    fbt.insert(fbt.root, 6);
    
    fbt.levelOrder(fbt.root);
}






