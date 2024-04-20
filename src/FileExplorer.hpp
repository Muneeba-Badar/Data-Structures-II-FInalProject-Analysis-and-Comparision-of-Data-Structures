#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include "FileSystem.hpp"
#include "AVL.hpp"
#include "BST.hpp"
#include "Treaps.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

class FileExplorer
{
private:
    BSTIndex *WordIndex;
    BSTIndex *POSIndex;
    FileSystem *fs;

public:
    FileExplorer(const string &type, const string &txtFile);
    void FindByWord(const string &word, const string &output_path);
    void FindByPOS(const string &POS, const string &output_path);
    ~FileExplorer();
};
