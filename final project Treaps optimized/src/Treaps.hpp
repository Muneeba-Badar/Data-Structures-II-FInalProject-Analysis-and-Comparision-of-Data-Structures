#include <random>
#include "FileSystem.hpp"
#pragma once

struct Node
{
    vector<FileSystemEntry> data;
    Node* left;
    Node* right;
    string key;
    int p; //priority for treaps
    vector<int> indices;
    Node(string k, int i, int priority);
};

class Treaps
{
    public:
        Treaps();
        void Add(const int i, const string& Key);
        vector<int> Search(const string& Key);
        void CreateIndex(vector<FileSystemEntry> &Data, const string &IndexType);
        void AddNewWord(const int i, const string &Key);
        ~Treaps();
    private:
        Node* root;
        Node* insertHelper(Node*& node, const string& Key, const int i);
        Node* rightRotate(Node* y);
        Node* leftRotate(Node* x);
        inline int generatePriority();
        vector<int> searchHelper(Node* node, const string& Key);
        void postOrderDeletion(Node* root);
        Node* insertNewWord(Node*& node, const string& key, const int i);
        
};