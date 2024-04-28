#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include "FileSystem.hpp"
#include "AVL.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

class FileExplorer
{
private:
    AVLIndex *WordIndex;
    FileSystem *fs;

public:
    FileExplorer(const string &txtFile);
    void FindByWord(const string &word, const string &output_path);
    void InsertWord(const string &word);
    ~FileExplorer();
};
