// Provide your implementation for the AVLIndex class here
#include "AVL.hpp"
AVLIndex::AVLIndex() : root(nullptr){}

Node::Node(string k, int i) : key(k), left(nullptr), right(nullptr), height(0){
    indices.push_back(i);
}

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

vector<int> AVLIndex::searchHelper(Node* node, const string& Key) {
        if (node == nullptr) {
            return vector<int>();
        }
        if (Key == node->key) {
            return node->indices;
        } else if (Key < node->key) {
            return searchHelper(node->left, Key);
        } else {
            return searchHelper(node->right, Key);
        }
}

void AVLIndex::CreateIndex(vector<FileSystemEntry> &Data)
{
    //will create index on the given key in files data
    for (int i = 0; i < Data.size(); ++i) {
        Add(i, Data[i].word);
    }

}

void AVLIndex::AddNewWord(const int i, const string &Key) {
    root = insertNewWord(root, Key, i);
}

Node* AVLIndex::insertNewWord(Node*& node, const string& key, const int i) {
    if (node == nullptr) {
        return new Node(key, i);
    }
    Node* current = node;

    while (current != nullptr) {
        if (key < current->key) {
            if (current->left == nullptr) {
                current->left = new Node(key, i);
                break;
            } else {
                current = current->left;
            }
        } else if (key > current->key) {
            if (current->right == nullptr) {
                current->right = new Node(key, i);
                break;
            } else {
                current = current->right;
            }
        } else {
            current->indices.push_back(i);  // Handle duplicate keys
            break;
        }
    }

    return node;
}
void AVLIndex::postOrderDeletion(Node* root){
    if (root == nullptr){
        return;
    }
    postOrderDeletion(root->left);
    postOrderDeletion(root->right);
    delete root;
    root = nullptr;
}