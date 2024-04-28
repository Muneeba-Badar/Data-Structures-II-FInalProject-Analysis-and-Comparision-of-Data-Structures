// Provide the function signature for the BSTIndex class here
#include "FileSystem.hpp"
#pragma once
using namespace std;

// struct Node
// {
//     vector<FileSystemEntry> data;
//     Node* left;
//     Node* right;
//     string key;
//     int height;
//     vector<int> indices;
//     Node(string k, int i);
// };

struct Node {
    vector<FileSystemEntry> data;
    string key;             // The word
    int index;              // Index for the data entry
    int height;
    string meaning;         // Meaning of the word
    string partOfSpeech;    // Part of speech of the word
    vector<int> indices;    // To handle duplicate keys
    Node* left;
    Node* right;
    Node(const string& k, int i);
};

class BSTIndex
{
    protected:
        virtual Node* insertHelper(Node*& node, const string& key, const int i);
        virtual vector<int> searchHelper(Node* node, const string& Key);
        Node* root;
    public:
        BSTIndex();
        virtual void CreateIndex(vector<FileSystemEntry> &Data);
        virtual void Add(const int i, const string &Key);
        virtual vector<int> Search(const string &Key);
        ~BSTIndex();
        virtual void postOrderDeletion(Node* root);
        virtual Node* insertNewWord(Node*& node, const string& key, const int i);
        virtual void AddNewWord(const int i, const string &Key);
};