#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

struct FileSystemEntry
{
    string word;
};

class FileSystem
{

public:
    vector<FileSystemEntry> entries;
    void LoadFiles(const string &txtFile);
    void PrintFileEntry();
};