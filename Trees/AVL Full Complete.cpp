#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int data) : data(data), left(nullptr), right(nullptr), height(1) {}
};

class AVL{
public:
    Node* root;
    
    AVL() : root(nullptr) {}
    
    int getHeight(Node* node){
        return node->height;
    }
    
    int getBalance(Node* root){
        return getHeight(root->left) - getHeight(root->right);
    }
    
    // RIght rotation
    Node* LLrotation(Node* root){
        Node* child = root->left;
        root->left = child->right;
        child->right = root;
        
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        child->height = max(getHeight(child->left), getheight(child->right)) + 1;
        return child;
    }
    
    // Left Rotation
    Node* RRrotation(Node* root){
        Node* child = root->right;
        root->right = child->left;
        child->left = root;
        
        root->height = max(getHeight(root->left), getHeight(root->right));
        child->height = max(getHeight(child->left), getHeight(child->right));
        return child;
    }
    
    Node* insert(Node* root, int data){
        if(!root){
            return new Node(data);
        }
        
        if(data < root->data)
            root->left = insert(root->left, data);
        else if(data > root->data)
            root->right = insert(root->right, data);
        else
            return root;
        
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        int balance = getBalance(root);
        
        // LEFT (LL) case
        if(balance > 1 && data < root->data)
            return LLrotation(root);
        
        // RIGHT RR case    
        if(balance < -1 && data > root->data)
            return RRrotation(root);
            
        // left right
        if(balance > 1 && data > root->data){
            root->left = RRrotation(root->left);
            return LLrotation(root);
        }
        
        // right left
        if(balance < -1 && data < root->data){
            root->right = LLrotation(root->right);
            return RRrotation(root);
        }
        
        return root;
    }
    
    void inorder(Node* root){
        if(!root)
            return;
            
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
    Node* minValue(Node* root, int data){
        Node* current = root;
        while(current->left){
            current = current->left;
        }
        return current;
    }
    
    Node* deleteNode(Node* root, int data){
        if(!root)
            return root;
            
        if(data < root->data)
            root->left = deleteNode(root->left, data);
        else if (data > root->data)
            root->right = deleteNode(root->right, data);
        else{
            if(!root->left || !root->right){
                Node* temp = root->left ? root->left : root->right;
                
                if(!temp){
                    temp = root;
                    root = nullptr;
                }else
                    *root = *temp;
                    
                delete temp;
            }else{
                Node* temp = minValue(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        
         if(!root){
            return new Node(data);
        }
        
        root->height = max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);
        
        // LEFT (LL) case
        if(balance > 1 && data < root->data)
            return LLrotation(root);
        
        // RIGHT RR case    
        if(balance < -1 && data > root->data)
            return RRrotation(root);
            
        // left right
        if(balance > 1 && data > root->data){
            root->left = RRrotation(root->left);
            return LLrotation(root);
        }
        
        // right left
        if(balance < -1 && data < root->data){
            root->right = LLrotation(root->right);
            return RRrotation(root);
        }
        
        return root;
        
    }
}

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
        cout << endl << endl;
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
        if(!root) return;
        
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            
            if(current){
                cout << current->data << " ";
                
                if(current->left)   q.push(current->left);
                if(current->right) q.push(current->right);
            }else{
                cout << endl;
                if(!q.empty())
                    q.push(nullptr);
            }
        }
        cout << endl << endl;
    }
};

int main(){
    FullBinaryTree fbt;
    fbt.insert(fbt.root, 1);
    fbt.insert(fbt.root, 2);
    fbt.insert(fbt.root, 3);
    fbt.insert(fbt.root, 4);
    fbt.insert(fbt.root, 5);
    fbt.insert(fbt.root, 6);
    
    fbt.levelOrder(fbt.root);
    
    CompleteBinaryTree cbt;
    cbt.insert( 1);
    cbt.insert( 2);
    cbt.insert( 3);
    cbt.insert( 4);
    cbt.insert( 5);
    cbt.insert( 6);
    
    cbt.levelOrder();
}






