#include "Treaps.hpp"

Treaps::Treaps() : root(nullptr) {
    generatePriority();
}

Treaps::~Treaps(){
    postOrderDeletion(root);
}

int Treaps::generatePriority()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(1, 1000000);
    return dis(gen);
}

void Treaps::Add(const int i, const string &Key)
{
    //will add a new key to the index along with the details of files containing that key.
    root = insertHelper(root, Key, i);
}

int Treaps::getHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
} 

Node* Treaps::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* Treaps::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* Treaps::insertHelper(Node*& node, const string& key, const int i) {
    // Adding to the BST
    if (node == nullptr) {
        // If the node is null, create a new node and return it
        return new Node(key, i);
    } 
    else if (key < node->key) {
        // Recursively insert into the left subtree
        node->left = insertHelper(node->left, key, i);
    } 
    else if (key > node->key) {
        // Recursively insert into the right subtree
        node->right = insertHelper(node->right, key, i);
    } 
    else {
        // key already exists, add index to the existing node
        node->indices.push_back(i);
    }
    // Perform rotations if necessary
    if (node->left != nullptr && node->left->p > node->p) {
        if (node->left->left != nullptr && node->left->left->p > node->left->p) {
            node = rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }
    } else if (node->right != nullptr && node->right->p > node->p) {
        if (node->right->right != nullptr && node->right->right->p > node->right->p) {
            node = leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            node = leftRotate(node);
        }
    }

    // Return the updated node
    return node;
}

vector<int> Treaps::Search(const string& Key) {
    return searchHelper(root, Key);
}