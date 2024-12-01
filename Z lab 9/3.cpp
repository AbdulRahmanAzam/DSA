#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
    vector<int> values; 
    vector<Node*> children; 
    bool isLeaf; 

    Node(bool leaf) : isLeaf(leaf) {}
};


class TwoThreeTree {
private:
    Node* root;

    void insertNonFull(Node* node, int value) {
        if (node->isLeaf) {
            node->values.push_back(value);
            sort(node->values.begin(), node->values.end());
        } else {
            int i = 0;
            while (i < node->values.size() && value > node->values[i]) i++;

            // Check if child node is full
            if (node->children[i]->values.size() == 3) {
                splitChild(node, i);
                if (value > node->values[i]) i++;
            }
            insertNonFull(node->children[i], value);
        }
    }

    void splitChild(Node* parent, int index) {
        Node* fullNode = parent->children[index];
        Node* newNode = new Node(fullNode->isLeaf);

        newNode->values.push_back(fullNode->values[2]);
        fullNode->values.pop_back();

        if (!fullNode->isLeaf) {
            newNode->children.push_back(fullNode->children[2]);
            newNode->children.push_back(fullNode->children[3]);
            fullNode->children.resize(2);
        }

        parent->values.insert(parent->values.begin() + index, fullNode->values[1]);
        fullNode->values.pop_back();

        parent->children.insert(parent->children.begin() + index + 1, newNode);
    }

    void inorder(Node* node) {
        if (!node) return;

        for (int i = 0; i < node->values.size(); i++) {
            if (!node->isLeaf) inorder(node->children[i]);
            cout << node->values[i] << " ";
        }
        if (!node->isLeaf) inorder(node->children.back());
    }

    Node* mergeNodes(Node* left, Node* right) {
        Node* newRoot = new Node(false);
        newRoot->values.insert(newRoot->values.end(), left->values.begin(), left->values.end());
        newRoot->values.insert(newRoot->values.end(), right->values.begin(), right->values.end());
        sort(newRoot->values.begin(), newRoot->values.end());

        if (!left->isLeaf && !right->isLeaf) {
            newRoot->children.insert(newRoot->children.end(), left->children.begin(), left->children.end());
            newRoot->children.insert(newRoot->children.end(), right->children.begin(), right->children.end());
        }

        return newRoot;
    }

public:
    TwoThreeTree() : root(nullptr) {}

    void insert(int value) {
        if (!root) {
            root = new Node(true);
            root->values.push_back(value);
        } else {
            if (root->values.size() == 3) {
                Node* newRoot = new Node(false);
                newRoot->children.push_back(root);
                splitChild(newRoot, 0);
                root = newRoot;
            }
            insertNonFull(root, value);
        }
    }

    void merge(TwoThreeTree& other) {
        if (!root) {
            root = other.root;
            return;
        }
        if (!other.root) return;

        // Collect all values from both trees
        vector<int> values = collectValues(root);
        vector<int> otherValues = collectValues(other.root);
        values.insert(values.end(), otherValues.begin(), otherValues.end());

        // Sort values and build a new tree
        sort(values.begin(), values.end());
        root = nullptr;
        for (int value : values) {
            insert(value);
        }
    }

    vector<int> collectValues(Node* node) {
        vector<int> values;
        if (!node) return values;

        for (int i = 0; i < node->values.size(); i++) {
            if (!node->isLeaf) {
                vector<int> childValues = collectValues(node->children[i]);
                values.insert(values.end(), childValues.begin(), childValues.end());
            }
            values.push_back(node->values[i]);
        }
        if (!node->isLeaf) {
            vector<int> childValues = collectValues(node->children.back());
            values.insert(values.end(), childValues.begin(), childValues.end());
        }
        return values;
    }

    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    TwoThreeTree tree1;
    tree1.insert(10);
    tree1.insert(20);
    tree1.insert(5);
    tree1.insert(15);
    tree1.insert(25);

    TwoThreeTree tree2;
    tree2.insert(35);
    tree2.insert(40);
    tree2.insert(30);
    tree2.insert(38);
    tree2.insert(50);

    tree1.merge(tree2);

    cout << "Merged Tree In-order Traversal: ";
    tree1.inorderTraversal();

    return 0;
}
