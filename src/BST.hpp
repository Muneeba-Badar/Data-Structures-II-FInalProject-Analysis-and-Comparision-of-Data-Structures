// Provide the function signature for the BSTIndex class here
#include "FileSystem.hpp"
#pragma once
using namespace std;

struct Node
{
    vector<FileSystemEntry> data;
    Node* left;
    Node* right;
    string key;
    int height;
    vector<int> indices;
    Node(string k, int i);
};

class BSTIndex
{
    private:
        Node* insertHelper(Node*& node, const string& key, const int i);
    protected:
        vector<int> searchHelper(Node* node, const string& Key);
    public:
        Node* root;
        BSTIndex();
        void CreateIndex(vector<FileSystemEntry> &Data, const string &IndexType);
        virtual void Add(const int i, const string &Key);
        virtual vector<int> Search(const string &Key);
        ~BSTIndex();
        void postOrderDeletion(Node* root);
};