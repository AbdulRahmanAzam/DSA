#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node* left;
  node* right;

  node(int data){
    this->data = data;
    left = NULL;
    right = NULL; 
  }
};

node* buildTree(node* root){
  int data;
  cout<<"Enter data: "<<endl;
  cin >> data;

  if(data == -1)
    return nullptr;

  root = new node(data);

  cout << "Enter for left of " << data;
  root->left = buildTree(root->left);

  cout << "Enter for right of " << data;
  root->right = buildTree(root->right);

  return root;
}
// 1 2 3 -1 -1 -1 3 5 -1 -1 6 -1 -1
int main() {
  node* root = nullptr;

  root = buildTree(root);
}
