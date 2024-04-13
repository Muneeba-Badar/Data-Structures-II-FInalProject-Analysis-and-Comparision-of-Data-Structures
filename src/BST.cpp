// Provide your implementation for the BSTIndex class here
#include "BST.hpp"
BSTIndex::BSTIndex() : root(nullptr) {}
Node::Node(string k, int i) : key(k), left(nullptr), right(nullptr){
    indices.push_back(i);
}

Node* BSTIndex::insertHelper(Node*& node, const string& key, const int i) {
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
    // Return the updated node
    return node;
}

vector<int> BSTIndex::searchHelper(Node* node, const string& Key) {
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

void BSTIndex::CreateIndex(vector<FileSystemEntry> &Data, const string &IndexType)
{
    //will create index on the given key in files data
    for (int i = 0; i < Data.size(); ++i) {
        if (IndexType == "word") {
            Add(i, Data[i].word);
        } 
        else if (IndexType == "partOfSpeech") {
            Add(i, Data[i].partOfSpeech);
        }
    }
}

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