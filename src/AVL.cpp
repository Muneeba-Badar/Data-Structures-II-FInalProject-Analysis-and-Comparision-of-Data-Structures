// Provide your implementation for the AVLIndex class here
#include "AVL.hpp"
AVLIndex::AVLIndex() : root(nullptr){}

AVLIndex::~AVLIndex(){
    postOrderDeletion(root);
}

int AVLIndex::getHeight(Node* node) {
            if (node == nullptr) {
                return -1;
            }
            return node->height;
        }

int AVLIndex::balanceFactor(Node* node) {
            if (node == nullptr) {
                return 0;
            }
            return getHeight(node->left) - getHeight(node->right);
        }

Node* AVLIndex::rightRotate(Node* y) {
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

Node* AVLIndex::leftRotate(Node* x) {
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

Node* AVLIndex::insertHelper(Node*& node, const int i, const string& Key) {
            // Perform normal BST insertion
            if (node == nullptr) {
                return new Node(Key, i);
            }

            if (Key < node->key) {
                node->left = insertHelper(node->left, i, Key);
            } else if (Key > node->key) {
                node->right = insertHelper(node->right, i, Key);
            } else {
                // Key already exists, add index to the existing node
                node->indices.push_back(i);
                // return node;
            }

            // Update height of this ancestor node
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));

            // Get the balance factor of this ancestor node to check whether this node became unbalanced
            int balance = balanceFactor(node);

            // If this node becomes unbalanced, then there are four cases

            // Left Case
            if (balance > 1 && Key < node->left->key) {
                return rightRotate(node);
            }

            // Right Case
            if (balance < -1 && Key > node->right->key) {
                return leftRotate(node);
            }

            // Left Right Case
            if (balance > 1 && Key > node->left->key) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // Right Left Case
            if (balance < -1 && Key < node->right->key) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            // Return the (unchanged) node pointer
            return node;
}

void AVLIndex::Add(const int i, const string& Key) {
    root = insertHelper(root, i, Key);
}

vector<int> AVLIndex::Search(const string& Key) {
    return searchHelper(root, Key);
}