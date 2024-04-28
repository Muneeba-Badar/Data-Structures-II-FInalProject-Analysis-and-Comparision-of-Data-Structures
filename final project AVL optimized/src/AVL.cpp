#include "AVL.hpp"

Node::Node(string k, int i) : key(k), left(nullptr), right(nullptr), height(0){
    indices.push_back(i);
}

Node::Node(const string& k, int i, const string& m, const string& pos) 
        : key(k), index(i), meaning(m), partOfSpeech(pos), left(nullptr), right(nullptr) {
    indices.push_back(i);
}

AVLIndex::AVLIndex() : root(nullptr) {}

AVLIndex::~AVLIndex(){
    postOrderDeletion(root);
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
    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (key < node->left->key) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balance < -1) {
        if (key > node->right->key) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

void AVLIndex::AddNewWord(const int i, const string &Key) {
    root = insertNewWord(root, Key, i);
}


int AVLIndex::getHeight(Node* node) {
    return (node == nullptr) ? -1 : node->height;
}

int AVLIndex:: getBalanceFactor(Node* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

Node* AVLIndex::rightRotate(Node* y) {
    if (y == nullptr || y->left == nullptr) {
        return y; // Return y unchanged if it's null or its left child is null
    }
    
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights after rotation
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x; // Return the new root of the subtree
}

//old
// Node* AVLIndex::leftRotate(Node* x) {
//     Node* y = x->right;
//     Node* T2 = y->left;

//     y->left = x;
//     x->right = T2;

//     x->height = 1 + max(getHeight(x->left), getHeight(x->right));
//     y->height = 1 + max(getHeight(y->left), getHeight(y->right));

//     return y;
// }

Node* AVLIndex::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Node* AVLIndex::insertHelper(Node*& node, const int i, const string& Key) {
//     if (node == nullptr) {
//         return new Node(Key, i);
//     }

//     if (Key < node->key) {
//         node->left = insertHelper(node->left, i, Key);
//     } else if (Key > node->key) {
//         node->right = insertHelper(node->right, i, Key);
//     } else {
//         node->indices.push_back(i);
//         return node;
//     }

//     node->height = 1 + max(getHeight(node->left), getHeight(node->right));

//     int balance = balanceFactor(node);

//     if (balance > 1 && Key < node->left->key) {
//         return rightRotate(node);
//     }

//     if (balance < -1 && Key > node->right->key) {
//         return leftRotate(node);
//     }

//     if (balance > 1 && Key > node->left->key) {
//         node->left = leftRotate(node->left);
//         return rightRotate(node);
//     }

//     if (balance < -1 && Key < node->right->key) {
//         node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }

//     return node;
// }


Node* AVLIndex::insertHelper(Node*& node, const string& Key, const int i) {
    if (node == nullptr) {
        return new Node(Key, i);
    }

    if (Key < node->key) {
        node->left = insertHelper(node->left, Key, i);
    } else if (Key > node->key) {
        node->right = insertHelper(node->right, Key, i);
    } else {
        node->indices.push_back(i);
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (Key < node->left->key) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balance < -1) {
        if (Key > node->right->key) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

void AVLIndex::Add(const int i, const string& Key) {
    root = insertHelper(root, Key, i);
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
void AVLIndex::CreateIndex(vector<FileSystemEntry>& Data, const string& IndexType) {
    for (int i = 0; i < Data.size(); ++i) {
        Add(i, Data[i].word);
    }
}

void AVLIndex::postOrderDeletion (Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrderDeletion(root->left);
    postOrderDeletion(root->right);
    delete root;
}

