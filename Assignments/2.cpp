#include <bits/stdc++.h>
using namespace std;

class Table{
    public:
    int ID;
    string name;
    int age;

    Table(int ID = 0, string name= "", int age= 0) : ID(ID), name(name), age(age) {}
};

// ====================================== B S T ======================================================

class BST{
    public:
    Table keys;
    BST* left;
    BST* right;

    BST(int ID = 0, string name = 0, int age = 0) { // PARAMETRIZED DEFAULT CONSTRUCTOR
        keys = Table(ID, name, age);
        left = nullptr;
        right = nullptr;
    }

    BST(Table key) {
        keys = key;
        left = nullptr;
        right = nullptr;
    }
    // --------------------------------------------INSERTION----------------------------------------------
    void insert(BST*& node, Table key){
        if(!node){
            node = new BST(key);
            return;
        }

        if(node->keys.ID == key.ID) // when the same key is already insert
            return;

        if(node->keys.ID < key.ID){
            insert(node->right, key);
        }else{
            insert(node->right,key);
        }
    }

    // --------------------------------------------DELETE NODE----------------------------------------------
    BST* getMinValueNode(BST* root){
        BST* temp = root;
        while(temp && temp->left){
            temp = temp->left;
        }
        return temp;
    }
    void delNode(BST*& root, int id){
        if(!root) return;

        if(root->keys.ID > id){
            delNode(root->left, id);

        }else if(root->keys.ID < id){
            delNode(root->right, id);

        }else{

            if(!root->left){ // no left child
                BST* temp = root;
                root = root->right;
                delete temp;
                return;
            }

            if(!root->right){ // no right child
                BST* temp = root;
                root = root->left;
                delete temp;
                return;
            }

            // if both child are present
            BST* temp = getMinValueNode(root->right);
            root->keys = temp->keys;
            delNode(root->right, temp->keys.ID);
        }
    }
    // --------------------------------------------SEARCH----------------------------------------------
    void search(BST* root, int id){
        if(!root){
            cout << "The id is not found in the record" << endl;
            return;
        }

        if(root->keys.ID == id){
            cout << "The id is found" << endl;
            cout << "ID: " << root->keys.ID << " name: " << root->keys.name << " age: " << root->keys.age << endl;     
        }

        if(root->keys.ID < id){
            search(root->right, id);
        }else{
            search(root->left, id);
        }
    }

};

 // ======================================  A V L ======================================================
class AVL{
    public:
    int height;
    Table keys;
    AVL* left;
    AVL* right;

    AVL(int id = 0, string name = "", int age=0){
        keys = Table(id, name, age);
        left = nullptr;
        right = nullptr;
        height = 1;
    }
    AVL(Table key){
        keys = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    void updateHeight(AVL*& node){
        if(node){
            int leftHeight = (node->left) ? node->left->height : 0;
            int rightHeight = (node->right) ? node->right->height : 0;
            node->height = 1 + max(node->left->height, node->right->height);
        }
    }

    void rightRotate(AVL*& root){
        if (!root || !root->left) return;
        AVL* temp = root->left;
        root->left = temp->right;
        temp->right = root;
        updateHeight(root);
        updateHeight(temp);
        root = temp;
    }

    void leftRotate(AVL*& root){
        if (!root || !root->left) return;
        AVL* temp = root->right;
        root->right = temp->left;
        temp->left = root;
        updateHeight(root);
        updateHeight(temp);
        root = temp;
    }

    int getHeight(AVL* root){
        return root ? root->height : 0;
    }
    int getBalanceFactor(AVL* root){
        return root ? getHeight(root->left) - getHeight(root->right): 0;
    }
    void insert(AVL*& root, Table key){
        if(!root){
            root = new AVL(key);
            return;
        }

        if(root->keys.ID < key.ID){
            insert(root->right, key);
        }else if(root->keys.ID > key.ID){
            insert(root->left, key);
        }else{
            cout << "ID already exists" << endl;
        }


        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalanceFactor(root);


        if(balance > 1){
            if(key.ID < root->left->keys.ID){
                rightRotate(root);
            }else{
                leftRotate(root->left);
                rightRotate(root);
            }
        }else if(balance < -1){
            if(key.ID > root->right->keys.ID){
                leftRotate(root);
            }else{
                rightRotate(root->right);
                leftRotate(root);
            }
        }
    }


    AVL* minValueNode(AVL* root){
        AVL* current = root;
        while(current->left != NULL){
            current = current->left;
        }
        return current;
    }
    void deleteNode(AVL*& root, int ID){
        if(!root)
            return;

        if(ID < root->keys.ID){
            deleteNode(root->left, ID);
        }else if(ID > root->keys.ID){
            deleteNode(root->right, ID);
        }else{
            if(!root->left || !root->right){
                AVL* temp = root->left ? root->left : root->right;

                if(!temp){
                    temp = root;
                    root = nullptr;
                }else{
                    *root = *temp;
                }
            }else{
                AVL* temp = minValueNode(root->right);
                root->keys = temp->keys;
                deleteNode(root->right, temp->keys.ID);
            }
        }

        if(!root)
            return;

        updateHeight(root);

        int balance = getBalanceFactor(root);

        if(balance > 1 && root->left){
            if(root->left->keys.ID >= ID){
                rightRotate(root);
                return;
            }else{
                leftRotate(root->left);
                rightRotate(root);
            }
        }

        if(balance < -1 && root->right){
            if(root->right->keys.ID <= ID){
                leftRotate(root);
                return;
            }else{
                rightRotate(root->right);
                leftRotate(root);
                return;
            }
        }
    }
};
 // ========================================== B TREE is taken help grom gfg ======================================
class BTree{
    public:
    vector<BTree*> children;
    vector<Table> keys; 
    bool isLeaf;
    int minDegree;

    BTree* root;

    BTree(int minDegree = 0, bool isLeaf = true) {
        root = nullptr;
        minDegree = minDegree;
        isLeaf = isLeaf;
    }

     void insert(Table key);
    void insertNonFull(Table key);
    void splitChild(int index, BTree* fullChild);
    

    void insert10(BTree*& root){
        if(!root)
            root = new BTree();

        for(int i=0; i < 10; i++){
            Table key(i, "any",(3*i+3)/2);
            root->insert(key);
        }
    }

    void traverse() {
    // Loop through all keys in the node
        for (size_t i = 0; i < keys.size(); i++) {
            // If the node is not a leaf, traverse the left subtree before printing the key
            if (!isLeaf) {
                children[i]->traverse();
            }

            // Print the current key (assume `ID` is the key field in `Table`)
            cout << keys[i].ID << " ";
        }

        // If the node is not a leaf, traverse the rightmost child
        if (!isLeaf && !children.empty()) {
            children[children.size() - 1]->traverse();
        }
    }
};



void BTree::insert(Table key) {
    // If tree is empty
    if (keys.empty()) {
        keys.push_back(key);
        return;
    }

    // If root is full
    if (keys.size() == 2 * minDegree - 1) {
        // Create a new root
        BTree* newRoot = new BTree(minDegree, false);
        newRoot->children.push_back(this);

        // Split the current root
        newRoot->splitChild(0, this);

        // Determine which child to insert into
        int i = (newRoot->keys[0].ID < key.ID) ? 1 : 0;
        newRoot->children[i]->insertNonFull(key);

        // Update the root
        *this = *newRoot;
    } else {
        insertNonFull(key);
    }
}

void BTree::insertNonFull(Table key) {
    int i = keys.size() - 1;

    if (isLeaf) {
        // Insert into leaf node
        keys.push_back(key);  // Add a placeholder at the end
        while (i >= 0 && keys[i].ID > key.ID) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        // Find the child to insert into
        while (i >= 0 && keys[i].ID > key.ID) {
            i--;
        }
        i++;  // Move to the correct child index

        // Split the child if it is full
        if (children[i]->keys.size() == 2 * minDegree - 1) {
            splitChild(i, children[i]);

            // After the split, determine which child to insert into
            if (keys[i].ID < key.ID) {
                i++;
            }
        }
        children[i]->insertNonFull(key);
    }
}

void BTree::splitChild(int index, BTree* fullChild) {
    // Create a new node for the right half of the full child
    BTree* newNode = new BTree(minDegree, fullChild->isLeaf);

    // Move the last (minDegree - 1) keys to the new node
    for (int i = 0; i < minDegree - 1; i++) {
        newNode->keys.push_back(fullChild->keys[i + minDegree]);
    }

    // Move the last minDegree children to the new node
    if (!fullChild->isLeaf) {
        for (int i = 0; i < minDegree; i++) {
            newNode->children.push_back(fullChild->children[i + minDegree]);
        }
    }

    // Reduce the size of the full child
    fullChild->keys.resize(minDegree - 1);
    fullChild->children.resize(minDegree);

    // Insert the new node into the children vector
    children.insert(children.begin() + index + 1, newNode);

    // Move the median key up to the parent node
    keys.insert(keys.begin() + index, fullChild->keys[minDegree - 1]);
}




template <typename TreeType>
void insert10(TreeType*& tree){
    if(!tree)
        tree = nullptr;

    for(int i=0; i < 1; i++){
        Table key(i, "n",(3*i+3)/2);
          tree->insert(tree, key);
    }
}

    // --------------------------------------------TRAVERSAL----------------------------------------------
template <typename TreeType>
void inorder(TreeType* node){
    if(!node)
        return; 
   
        inorder(node->left);
        cout << "ID: " << node->keys.ID << " name: " << node->keys.name << " age: " << node->keys.age << endl; 
        inorder(node->right);
}

int main(){
    // ======================================= B S T ===========================
    BST* bst = nullptr;
    cout << "INSERTING INTO BST" << endl;
    insert10(bst);

    cout << "\nInorder traversal BST" << endl;
    inorder(bst);

    bst->delNode(bst, 5);

    cout << "\nInorder traversal of BST after deletion" << endl;
    inorder(bst);

    // ========================================== A V L ===========================================
    cout << "\nINSERTING INTO AVL" << endl;
    AVL* avl = nullptr;
    insert10(avl);
    
    cout << "\nInorder Traversal of AVL" << endl;
    inorder(avl);

    avl->deleteNode(avl, 3);
    avl->deleteNode(avl, 4);
    cout << "\nInorder Traversal of AVL after deletion" << endl;

    // ========================================== B - TREES =================================
    cout << "\nINSERTING INTO B-TREE" << endl;
    BTree* btree = new BTree(3);
    
    // Table key(23, "dsf", 5);
    btree->insert10(btree);

    // cout << btree->keys[0].ID << endl;


    btree->traverse();
}







    // void splitChild(int index, BTree* fullChild, int minDegree, vector<Table>& keys, vector<BTree*>& children, bool isLeaf){
    //     BTree* newNode = new BTree(fullChild->minDegree, fullChild->isLeaf);

    //     for(int i=0; i < minDegree - 1; i++)
    //         newNode->keys.push_back(fullChild->keys[i + minDegree]);

    //     if(!fullChild->isLeaf){
    //         for(int i=0; i < minDegree; i++)
    //             newNode->children.push_back(fullChild->children[i + minDegree]);
    //     }

    //     fullChild->keys.resize(minDegree - 1);  // keys will always we 1 less than minDegree
    //     fullChild->children.resize(minDegree);

    //     children.insert(children.begin() + index + 1, newNode);

    //     keys.insert(keys.begin() + index, fullChild->keys[minDegree - 1]);

    // }
    // void insertNonFull(Table key, vector<Table>& keys, vector<BTree*>& children, int minDegree, bool isLeaf){
    //     int i = keys.size() - 1;

    //     if(isLeaf){
    //         keys.push_back(key);

    //         while(i >= 0 && keys[i].ID > key.ID){
    //             keys[i + 1] = keys[i];
    //             i--;
    //         }
    //         keys[i + 1] = key;
    //     }else{
    //         while(i >= 0 && keys[i].ID > key.ID)
    //             i--;


    //         if(children[i + 1]->keys.size() == 2 * minDegree - 1){
    //             splitChild(i + 1, children[i + 1], minDegree, keys, children, isLeaf);

    //             if(keys[i + 1].ID < key.ID)
    //                 i++;
    //         }

    //         children[i]->insertNonFull(key, children[i+1]->keys, children[i+1]->children, minDegree, children[i+1]->isLeaf);
    //     }
    // }
    // void insert(BTree*& root, Table key, int minDegree){
    //     if(!root){
    //         root = new BTree(minDegree, true);
    //         root->keys.push_back(key);
    //         return;
    //     }

    //     if(root->keys.size() == 2 * minDegree -1){
    //         BTree* newRoot = new BTree(minDegree, false);
    //         newRoot->children.push_back(root);

    //         splitChild(0, root, minDegree, newRoot->keys, newRoot->children, false);

    //         int i = (newRoot->keys[0].ID < key.ID) ? 1 : 0;
    //         newRoot->children[i]->insertNonFull(key, newRoot->children[i]->keys, newRoot->children[i]->children, minDegree, newRoot->children[i]->isLeaf);

    //         root = newRoot;
    //     }else{
    //         root->insertNonFull(key, root->keys, root->children, minDegree, root->isLeaf);
    //     }
    // }

