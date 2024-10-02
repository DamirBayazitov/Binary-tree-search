struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

Node* balanceNode(Node* node) {
    // balance node somehow
    return node;
}

Node* insertNode(Node* root, int data) {
    if (root == nullptr)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    balanceNode(root);
    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    
    if (root->data < key)
        return searchNode(root->right, key);
    
    return searchNode(root->left, key);
}

Node* minimumNode(Node* root) {
    Node* current = root;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == nullptr) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        if (root->right == nullptr) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }

        Node* tmp = minimumNode(root->right);
        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
    }

    balanceNode(root);
    return root;
}

void traversal(Node* root) {
    if (root == nullptr) return;
    traversal(root->left);
    cout << root->data << " ";
    traversal(root->right);
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 9);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 8);
    root = insertNode(root, 4);
    root = insertNode(root, 0);

    cout << "inorder traversal: \n";
    traversal(root);
    cout << "\n";

    cout << "search for 3: " << (searchNode(root, 3) != nullptr) << "\n";

    cout << "try to delete 3: " << (deleteNode(root, 3) != nullptr) << "\n";

    cout << "search for 3: " << (searchNode(root, 3) != nullptr) << "\n";

    cout << "minimum for now: " << minimumNode(root)->data << "\n";

    cout << "try to delete 0: " << (deleteNode(root, 0) != nullptr) << "\n";

    cout << "minimum for now: " << minimumNode(root)->data << "\n";

    return 0;
}