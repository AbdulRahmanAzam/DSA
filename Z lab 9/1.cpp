#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data=0, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right) {}
};

int height(Node* root){
    if(!root)
        return 0;

    return 1 +  max(height(root->left), height(root->right));
}

bool isBST(Node* root, Node* min, Node* max){
    if(!root)  return true;

    if((min && min->data >= root->data) || (max && max->data <= root->data))
        return false;
    
    return isBST(root->left, min, root) && isBST(root->right, root, max);
}

bool isAVL(Node* root){
    if(!root) return true;

    if(abs(height(root->left) - abs(height(root->right))) > 1)
        return false;
    
    return isAVL(root) && isAVL(root->left) && isAVL(root->right);
}

