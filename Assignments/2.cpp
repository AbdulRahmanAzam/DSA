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

    AVL* search(AVL* root, int ID) {
        if (!root || root->keys.ID == ID) {
            return root;
        }
    
        if (ID < root->keys.ID) {
            return search(root->left, ID);
        }
    
        return search(root->right, ID);
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
class BTreeNode {
public:
    vector<Table> keys;                // Vector of keys
    vector<BTreeNode*> children;       // Vector of child pointers
    int minDegree;                     // Minimum degree (defines the range for the number of keys)
    bool isLeaf;                       // True if the node is a leaf

    // Constructor
    BTreeNode(int minDegree, bool isLeaf) {
        this->minDegree = minDegree;
        this->isLeaf = isLeaf;
        keys.reserve(2 * minDegree - 1);   // Reserve space for max keys
        children.reserve(2 * minDegree);  // Reserve space for max children
    }

    // Function to traverse the B-Tree
    void traverse() {
        int i;
        for (i = 0; i < keys.size(); i++) {
            // If this is not a leaf, traverse the child before printing the key
            if (!isLeaf)
                children[i]->traverse();

            // Print the key
            cout << "ID: " << keys[i].ID << " Name: " << keys[i].name << " Age: " << keys[i].age << endl;
        }

        // Print the subtree rooted with the last child
        if (!isLeaf)
            children[i]->traverse();
    }

    // Insert a new key into the subtree rooted with this node
    void insertNonFull(const Table& key) {
        int i = keys.size() - 1;

        if (isLeaf) {
            // Insert into the correct position in the keys array
            keys.push_back(key); // Add a placeholder
            while (i >= 0 && keys[i].ID > key.ID) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
        } else {
            // Find the child which is going to have the new key
            while (i >= 0 && keys[i].ID > key.ID) {
                i--;
            }

            // Check if the found child is full
            if (children[i + 1]->keys.size() == 2 * minDegree - 1) {
                splitChild(i + 1, children[i + 1]);

                // Determine which child to insert into
                if (keys[i + 1].ID < key.ID)
                    i++;
            }
            children[i + 1]->insertNonFull(key);
        }
    }

    // Split a child of this node
    void splitChild(int i, BTreeNode* childToSplit) {
        // Create a new node to store (minDegree - 1) keys from childToSplit
        BTreeNode* newSibling = new BTreeNode(childToSplit->minDegree, childToSplit->isLeaf);
        newSibling->keys.resize(minDegree - 1);

        // Copy the last (minDegree - 1) keys of childToSplit to newSibling
        for (int j = 0; j < minDegree - 1; j++) {
            newSibling->keys[j] = childToSplit->keys[j + minDegree];
        }

        // Copy the last minDegree children of childToSplit to newSibling
        if (!childToSplit->isLeaf) {
            newSibling->children.resize(minDegree);
            for (int j = 0; j < minDegree; j++) {
                newSibling->children[j] = childToSplit->children[j + minDegree];
            }
        }

        // Reduce the number of keys in childToSplit
        childToSplit->keys.resize(minDegree - 1);

        // Insert the new sibling into this node's children
        children.insert(children.begin() + i + 1, newSibling);

        // Move the middle key of childToSplit to this node
        keys.insert(keys.begin() + i, childToSplit->keys[minDegree - 1]);
    }

    friend class BTree;
};

class BTree {
public:
    BTreeNode* root;  // Pointer to root node
    int minDegree;    // Minimum degree

    // Constructor
    BTree(int degree) {
        root = nullptr;
        minDegree = degree;
    }

    // Insert a new key
    void insert(const Table& key) {
        if (!root) {
            // Create the root if it doesn't exist
            root = new BTreeNode(minDegree, true);
            root->keys.push_back(key);
        } else {
            // If root is full, create a new root
            if (root->keys.size() == 2 * minDegree - 1) {
                BTreeNode* newRoot = new BTreeNode(minDegree, false);

                // Make old root a child of the new root
                newRoot->children.push_back(root);

                // Split the old root and move a key to the new root
                newRoot->splitChild(0, root);

                // Decide which of the two children to insert into
                if (key.ID > newRoot->keys[0].ID) {
                    newRoot->children[1]->insertNonFull(key);
                } else {
                    newRoot->children[0]->insertNonFull(key);
                }

                // Update root
                root = newRoot;
            } else {
                root->insertNonFull(key);
            }
        }
    }

    // Function to traverse the B-Tree
    void traverse() {
        if (root)
            root->traverse();
    }
};


// void insert10(BTree* tree){
//     for(int i = 0; i < 10; i++){
//         Table key = {i, to_string('a'+i), (3*i+3)/2};
//         tree->insert(key);
//     }
// }


template <typename TreeType>
void insert1000(TreeType*& tree){
    auto start = chrono::high_resolution_clock::now();
    if(!tree)
        tree = nullptr;

    for(int i=1; i <= 1000; i++){
        Table key = {i, "n",(3*i+3)/2};
        if constexpr (is_same<TreeType, BTree>::value)
            tree->insert(key);
        else
            tree->insert(tree, key);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken for 1000 insertions: " << duration.count() << " milliseconds" << endl;
}

template <typename TreeType>
void insert10000(TreeType*& tree){
    auto start = chrono::high_resolution_clock::now();
    if(!tree)
        tree = nullptr;

    for(int i=1001; i <= 11001; i++){
        Table key = {i, "n",(3*i+3)/2};
        if constexpr (is_same<TreeType, BTree>::value)
            tree->insert(key);
        else
            tree->insert(tree, key);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken for 10000 insertions: " << duration.count() << " milliseconds" << endl;
}

template <typename TreeType>
void insert50000(TreeType*& tree){
    auto start = chrono::high_resolution_clock::now();
    if(!tree)
        tree = nullptr;

    for(int i=11001; i <= 61001; i++){
        Table key = {i, "n",(3*i+3)/2};
        if constexpr (is_same<TreeType, BTree>::value)
            tree->insert(key);
        else
            tree->insert(tree, key);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken for 50000 insertions: " << duration.count() << " milliseconds" << endl;
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
    insert1000(bst);
    insert10000(bst);
    insert50000(bst);

    // YOU CAN UNCOMMENT TO CHECK THAT ALL THE FUNCTIONS ARE WORKING
    // cout << "\nInorder traversal BST" << endl;
    // inorder(bst);

    // bst->delNode(bst, 5);
    // cout << "\nInorder traversal of BST after deletion" << endl;
    // inorder(bst);

    // ========================================== A V L ===========================================
    cout << "\nINSERTING INTO AVL" << endl;
    AVL* avl = nullptr;
    insert1000(avl);
    insert10000(avl);
    insert50000(avl);
    
    // YOU CAN UNCOMMENT TO CHECK THAT ALL THE FUNCTIONS ARE WORKING
    // cout << "\nInorder Traversal of AVL" << endl;
    // inorder(avl);

    // avl->deleteNode(avl, 3);
    // avl->deleteNode(avl, 4);
    // cout << "\nInorder Traversal of AVL after deletion" << endl;
    // inorder(avl);

    // int keyToSearch = 20;
    // AVL* result = search(root, keyToSearch);

    // ========================================== B - TREES =================================
    cout << "\nINSERTING INTO B-TREE" << endl;
    BTree *btree = new BTree(4);

    insert1000(btree);
    insert10000(btree);
    insert50000(btree);

    // btree->traverse();
}
