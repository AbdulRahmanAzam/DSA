void levelOrderTraversal() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); 

            for (int i = 0; i < levelSize; i++) {
                Node* current = q.front();
                q.pop();

                for (int value : current->values)
                    cout << value << " ";

                for (Node* child : current->children)
                    q.push(child);
            }
            cout << endl;
        }
    }
