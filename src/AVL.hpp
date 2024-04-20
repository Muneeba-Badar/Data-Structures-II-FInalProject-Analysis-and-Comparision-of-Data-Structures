#include <algorithm>
#include "FileSystem.hpp"
#include "BST.hpp"
#pragma once
using namespace std;

class AVLIndex : public BSTIndex {
public:
    AVLIndex();
    void Add(const int i, const string& Key) override;
    vector<int> Search(const string& Key) override;
    ~AVLIndex();
private:
    Node* root;
    Node* insertHelper(Node*& node, const int i, const string& Key);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    int getHeight(Node* node);
    int balanceFactor(Node* node);
};