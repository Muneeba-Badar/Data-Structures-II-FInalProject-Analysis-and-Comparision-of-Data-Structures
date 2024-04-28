#include "Treaps.hpp"

Treaps::Treaps() : root(nullptr) {}

Node::Node(string k, int i, int priority) : key(k), left(nullptr), right(nullptr), p(priority){
    indices.push_back(i);
}

Treaps::~Treaps(){
    postOrderDeletion(root);
}

inline int Treaps::generatePriority()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(1, 100999);
    return dis(gen);
}

void Treaps::Add(const int i, const string &Key)
{
    //will add a new key to the index along with the details of files containing that key.
    root = insertHelper(root, Key, i);
}

Node* Treaps::rightRotate(Node* y) {
   Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

Node* Treaps::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Node* Treaps::insertHelper(Node*& node, const string& key, const int i) {
//     // Adding to the Treap
//     if (node == nullptr) {
//         // If the node is null, create a new node and return it
//         return new Node(key, i, generatePriority());
//     } 
//     if (key < node->key) {
//         // Recursively insert into the left subtree
//         node->left = insertHelper(node->left, key, i);
//         if (node->left->p > node->p)
//             node = rightRotate(node);
//     } 
//     else if (key > node->key) {
//         // Recursively insert into the right subtree
//         node->right = insertHelper(node->right, key, i);
//         // Fix Heap property if it is violated
//         if (node->right->p > node->p)
//             node = leftRotate(node);
//     } 
//     else {
//         // key already exists, add index to the existing node
//         node->indices.push_back(i);
//     }
//     // Return the updated node
//     return node;
// }

Node* Treaps::insertHelper(Node*& node, const string& key, const int i) {
    if (node == nullptr) {
        return new Node(key, i, generatePriority());
    }
    
    Node* current = node;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            current->indices.push_back(i); // Handle duplicate keys
            return node;
        }
    }

    current = new Node(key, i, generatePriority());
    if (key < parent->key) {
        parent->left = current;
    } else {
        parent->right = current;
    }

    while (parent != nullptr && current->p > parent->p) {
        if (parent->left == current) {
            parent = rightRotate(parent);
        } else {
            parent = leftRotate(parent);
        }
    }

    if (parent == nullptr) {
        return current;
    } else {
        return node;
    }
}

vector<int> Treaps::Search(const string& Key) {
    return searchHelper(root, Key);
}

void Treaps::CreateIndex(vector<FileSystemEntry> &Data, const string &IndexType)
{
    //will create index on the given key in files data
    for (int i = 0; i < Data.size(); ++i) {
        Add(i, Data[i].word);
    }
}

void Treaps::AddNewWord(const int i, const string &Key) {
    root = insertNewWord(root, Key, i);
}

Node* Treaps::insertNewWord(Node*& node, const string& key, const int i) {
    if (node == nullptr) {
        return new Node(key, i, generatePriority());
    }
    Node* current = node;

    while (current != nullptr) {
        if (key < current->key) {
            if (current->left == nullptr) {
                current->left = new Node(key, i, generatePriority());
                break;
            } else {
                current = current->left;
            }
        } else if (key > current->key) {
            if (current->right == nullptr) {
                current->right = new Node(key, i, generatePriority());
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

// vector<int> Treaps::searchHelper(Node* node, const string& Key) {
//         if (node == nullptr) {
//             return vector<int>();
//         }
//         if (Key == node->key) {
//             return node->indices;
//         } else if (Key < node->key) {
//             return searchHelper(node->left, Key);
//         } else {
//             return searchHelper(node->right, Key);
//         }
// }


vector<int> Treaps::searchHelper(Node* node, const string& Key) {
    while (node != nullptr) {
        if (Key == node->key) {
            return node->indices;
        } else if (Key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return vector<int>(); // Key not found
}

void Treaps::postOrderDeletion(Node* root){
    if (root == nullptr){
        return;
    }
    postOrderDeletion(root->left);
    postOrderDeletion(root->right);
    delete root;
    root = nullptr;
}
