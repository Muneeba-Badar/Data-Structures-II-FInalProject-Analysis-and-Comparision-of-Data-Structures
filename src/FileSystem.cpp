#include "FileSystem.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

void FileSystem::LoadFiles(const string &txtFile)
{
    ifstream file(txtFile);
    if (!file.is_open()) 
    {
        cerr << "Failed to open file: " << txtFile << endl;
        return;
    }
    string line;
    getline(file, line); // Skip header
    while (std::getline(file, line)) {
        stringstream ss(line);
        FileSystemEntry entry;
        std::getline(ss, entry.word, ',');
        std::getline(ss, entry.meaning, ',');
        std::getline(ss, entry.partOfSpeech, ',');

        // ss.ignore();
        // getline(ss, entry.path, ',');
        entries.push_back(entry);
    }

    file.close();
}

void FileSystem::PrintFileEntry()
{
    // print the file entry
    for (const auto &entry : entries)
    {
        // print each column on a new line
        cout << "word: " << entry.word << "\n";
        cout << "meaning: " << entry.meaning << "\n";
        cout << "partOfSpeech: " << entry.partOfSpeech << "\n";
        cout << "\n";
    }
}
