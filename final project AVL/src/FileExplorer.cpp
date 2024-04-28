// Provide your implementation for the FileExplorer class here
#include "FileExplorer.hpp"
FileExplorer::FileExplorer(const string &txtFile)
{
    //the constructor that creates indexes of the given type on word and lastModified POS.
    fs = new FileSystem();
    fs->LoadFiles(txtFile);

    WordIndex = new AVLIndex();

    // Create indexes on word and POS
    WordIndex->CreateIndex(fs->entries);

}

void FileExplorer::InsertWord(const string &word) {
    int index;  // Get the index for the new word from fs->entries

    // Add the word, meaning, and part of speech to the BST
    WordIndex->AddNewWord(index, word);
}

void FileExplorer::FindByWord(const string &word, const string &output_path)
{
    //Saves the words having the given name in a text file at the provided directory.
    vector<int> result = WordIndex->Search(word);
    ofstream outputFile(output_path);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return;
    }
    outputFile << "word\n";
    for (int index : result) {
        outputFile << fs->entries[index].word << endl;

    }
    outputFile.close();
}

FileExplorer::~FileExplorer(){
    delete WordIndex;
    delete fs;
    WordIndex = nullptr;
    fs = nullptr;
}