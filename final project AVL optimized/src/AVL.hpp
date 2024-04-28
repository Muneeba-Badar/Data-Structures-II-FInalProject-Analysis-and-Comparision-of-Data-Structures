// #ifndef AVL_HPP
// #define AVL_HPP
#include <iostream>
#include <string>
#include "FileSystem.hpp"
#pragma once
using namespace std;

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
    Node(string k, int i);
    Node(const string& k, int i, const string& m, const string& pos);
};

class AVLIndex{
public:
    Node* root;
    Node* insertHelper(Node*& node, const string& Key, const int i);
    void Add(const int i, const string& Key);
    vector<int> Search(const string& Key);
    vector<int> searchHelper(Node* node, const string& Key);
    void CreateIndex(vector<FileSystemEntry>& Data, const string& IndexType);
    void postOrderDeletion (Node* root);
    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);
    Node* insertNewWord(Node*& node, const string& key, const int i);
    void AddNewWord(const int i, const string &Key);

// public:
    AVLIndex();
    ~AVLIndex();

};
