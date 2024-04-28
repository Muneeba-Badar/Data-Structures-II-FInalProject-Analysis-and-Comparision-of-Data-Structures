// Provide your implementation for the BSTIndex class here
#include "BST.hpp"
BSTIndex::BSTIndex() : root(nullptr) {}
Node::Node(const string& k, int i) : key(k), left(nullptr), right(nullptr), height(0){
    indices.push_back(i);
}

Node* BSTIndex::insertNewWord(Node*& node, const string& key, const int i) {
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

void BSTIndex::AddNewWord(const int i, const string &Key) {
    root = insertNewWord(root, Key, i);
}


// version 1 
// Node* BSTIndex::insertHelper(Node*& node, const string& key, const int i) {
//     // Adding to the BST
//     if (node == nullptr) {
//         // If the node is null, create a new node and return it
//         return new Node(key, i);
//     } 
//     else if (key < node->key) {
//         // Recursively insert into the left subtree
//         node->left = insertHelper(node->left, key, i);
//     } 
//     else if (key > node->key) {
//         // Recursively insert into the right subtree
//         node->right = insertHelper(node->right, key, i);
//     } 
//     else {
//         // key already exists, add index to the existing node
//         node->indices.push_back(i);
//     }
//     // Return the updated node
//     return node;
// }

// version 2 
Node* BSTIndex::insertHelper(Node*& node, const string& key, const int i) {
  // Handle empty tree (base case)
  if (node == nullptr) {
    return new Node(key, i);
  }

  Node* current = node;

  // Use loop for efficient descent
  while (current != nullptr) {
    if (key < current->key) {
      if (current->left == nullptr) {
        current->left = new Node(key, i);
        break; // Insertion complete
      } 
      else {
        current = current->left;
      }
    } 
    else if (key > current->key) {
      if (current->right == nullptr) {
        current->right = new Node(key, i);
        break; // Insertion complete
      } 
      else {
        current = current->right;
      }
    } 
    else { // Duplicate key
      current->indices.push_back(i);
      break; // Insertion complete
    }
  }

  return node; // Return the root (unchanged)
}


// version 1 (original)
// vector<int> BSTIndex::searchHelper(Node* node, const string& Key) {
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

// version 2 (optimized)
// vector<int> BSTIndex::searchHelper(Node* node, const string& Key) {
//     while (node != nullptr) {
//         if (Key == node->key) {
//             return node->indices;
//         } 
//         else if (Key < node->key) {
//             node = node->left;
//         } 
//         else {
//             node = node->right;
//         }
//     }
//     return vector<int>();
// }

// version 3 (most optimized)
vector<int> BSTIndex::searchHelper(Node* node, const string& Key) {
  if (node == nullptr) {
    return vector<int>(); // Early return if node is null
  }

  // Optimized comparison: avoid string copy in each iteration
  while (node != nullptr && Key != node->key) {
    node = (Key < node->key) ? node->left : node->right;
  }

  // Handle the cases: key found or not found
  if (node == nullptr) {
    return vector<int>(); // Key not found
  } 
  else {
    return node->indices; // Key found, return indices
  }
}


void BSTIndex::CreateIndex(vector<FileSystemEntry> &Data)
{
    //will create index on the given key in files data
    for (int i = 0; i < Data.size(); ++i) {
            Add(i, Data[i].word);
    }
}

// Node* BSTIndex::insert(Node* node, string name, string meaning, string partOfSpeech) {
//         if (node == nullptr) {
//             return new Node{(name, meaning, partOfSpeech), };
//         }

//         if (name < node->name) {
//             node->left = insert(node->left, name, meaning, partOfSpeech);
//         } else if (name > node->name) {
//             node->right = insert(node->right, name, meaning, partOfSpeech);
//         } else {
//             // Handle duplicate names (if needed)
//             return node;
// }


void BSTIndex::Add(const int i, const string &Key)
{
    //will add a new key to the index along with the details of files containing that key.
    root = insertHelper(root, Key, i);
}

vector<int> BSTIndex::Search(const string &Key)
{
    // traverses the index to return details of a given key. 
    //This method also returns number of nodes visited while searching for the given key
    return searchHelper(root, Key);
}

BSTIndex::~BSTIndex(){
    postOrderDeletion(root);
}
void BSTIndex::postOrderDeletion(Node* root){
    if (root == nullptr){
        return;
    }
    postOrderDeletion(root->left);
    postOrderDeletion(root->right);
    delete root;
    root = nullptr;
}