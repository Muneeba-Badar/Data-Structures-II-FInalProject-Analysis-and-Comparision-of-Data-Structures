#include "BST.hpp"
#include "AVL.hpp"
#include <random>
#pragma once
class Treaps: public BSTIndex
{
    public:
        Treaps();
        void Add(const int i, const string& Key) override;
        vector<int> Search(const string& Key) override;
        ~Treaps();
    private:
        Node* root;
        Node* insertHelper(Node*& node, const string& Key, const int i);
        Node* rightRotate(Node* y);
        Node* leftRotate(Node* x);
        int getHeight(Node* node);
        int generatePriority();
};