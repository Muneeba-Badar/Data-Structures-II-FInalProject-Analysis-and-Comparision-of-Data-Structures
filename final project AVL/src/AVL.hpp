#include <algorithm>
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

class AVLIndex{
    public:
        AVLIndex();
        void Add(const int i, const string& Key);
        vector<int> Search(const string& Key);
        void CreateIndex(vector<FileSystemEntry> &Data);
        void AddNewWord(const int i, const string &Key);
        ~AVLIndex();
    private:
        Node* root;
        Node* insertHelper(Node*& node, const int i, const string& Key);
        Node* rightRotate(Node* y);
        Node* leftRotate(Node* x);
        int getHeight(Node* node);
        int balanceFactor(Node* node);
        vector<int> searchHelper(Node* node, const string& Key);
        void postOrderDeletion(Node* root);
        Node* insertNewWord(Node*& node, const string& key, const int i);
};