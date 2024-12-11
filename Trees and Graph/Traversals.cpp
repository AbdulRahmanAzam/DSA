
void inorderTraversal(node* root){
  if(root == NULL)
      return;

  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}



void preorderTraversal(node* root){
  if(root == NULL)
      return;

  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}



void postorderTraversal(node* root){
  if(root == NULL)
    return;

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}



// BST
void levelOrderTraversal(node* root){
  queue<node*> que;
  que.push(root);
  que.push(nullptr);
  

  while(!que.empty()){
    node* temp = que.front();
    que.pop();
    
    if(temp == nullptr){
      cout << endl;
      
      if(!que.empty()){
        // when que has some child nodes
        que.push(nullptr);
      }
    }else{
      cout << temp->data << " ";
      if(temp->left)
          que.push(temp->left);
  
      if(temp->right)
          que.push(temp->right);
    }
  }
}
