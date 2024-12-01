#include <bits/stdc++.h>

using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;
    int height;

    Node(int data=0, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right), height(1) {}
};
class AVL{
    public:
    Node* root;

    AVL(){
        root = nullptr;
    }

    int getHeight(Node* root){
        return root ? root->height : 0;
    }

    int getBalance(Node* root){
        return root ? getHeight(root->left) - getHeight(root->right) : 0;
    }

    Node* rotateRight(Node* root){
        Node* leftChild = root->left;
        Node* rightSub = leftChild->right;

        leftChild->right = root;
        root->left = rightSub;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        leftChild->height = 1 + max(getHeight(leftChild->left), getHeight(leftChild->right));

        return leftChild;
    }

    Node* rotateLeft(Node* root){
        Node* rightChild = root->right;
        Node* leftSub = rightChild->left;

        rightChild->left = root;
        root->right = leftSub;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        rightChild->height = 1 + max(getHeight(rightChild->left), getHeight(rightChild->right));

        return rightChild;
    }

    Node* insert(Node* root, int data, int& rotations){
        if(!root)
            return new Node(data);

        if(data < root->data)
            root->left = insert(root->left, data, rotations);
        else if(data > root->data)
            root->right = insert(root->right, data, rotations);
        else   
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        // left cases
        if(balance > 1){
            // left
            if(data < root->left->data){
                rotations++;
                return rotateRight(root);
            }
            // right 
            if(data > root->left->data){
                rotations += 2;
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }

        // right
        if(balance < -1){
            // right
            if(data > root->right->data){
                rotations++;
                return rotateLeft(root);
            }
            // left
            if(data < root->right->data){
                rotations += 2;
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }
        return root;
    }
};

void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

int countRotations(vector<int> nums) {
    AVL node;
    Node* root = nullptr;
    int rotations = 0;
    for (int num : nums)
        root = node.insert(root, num, rotations);

    inorder(root);
    cout << endl;
    return rotations;
}


int main(){
    vector<int> nums = {14, 17, 11, 7, 53, 4, 13, 12, 8 , 60, 19, 16, 20};
    
    cout << "The number of rotations are: "  << countRotations(nums) << endl;

}




