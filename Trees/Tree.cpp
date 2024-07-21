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



void buildFromLevelOrder(node* &root){
  queue<node*> que;
  int data;
  cout << "Enter data for root: " << endl;
  cin >> data;

  root = new node(data);
  que.push(root);

  while(!que.empty()){
    node* temp = que.front();
    que.pop();

    cout << "Enter left node for " << temp->data << endl;
    int left;
    cin >> left;

    if(left != -1){
      temp->left = new node(left);
      que.push(temp->left); 
    }

    cout << "Enter right node for " << temp->data << endl;
    int right;
    cin >> right;

    if(right != -1){
      temp->right = new node(right);
      que.push(temp->right);
    }
  }
}




// 1 2 3 -1 -1 -1 3 5 -1 -1 6 -1 -1
int main() {
  node* root = nullptr;

  root = buildTree(root);
}
