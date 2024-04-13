// Provide your implementation for the FileExplorer class here
#include "FileExplorer.hpp"
FileExplorer::FileExplorer(const string &type, const string &txtFile)
{
    //the constructor that creates indexes of the given type on word and lastModified POS.
    fs = new FileSystem();
    fs->LoadFiles(txtFile);

    if (type == "BST") {
        WordIndex = new BSTIndex();
        POSIndex = new BSTIndex();
    } 
    else if (type == "AVL") {
        WordIndex = new AVLIndex();
        POSIndex = new AVLIndex();
    }
    // Create indexes on word and POS
    WordIndex->CreateIndex(fs->entries, "word");
    POSIndex->CreateIndex(fs->entries, "partOfSpeech");
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
    outputFile << "word" << ", " << "meaning" << ", " << "partOfSpeech"<< '\n';
    for (int index : result) {
        // outputFile << fs->entries[index].word << endl;
        outputFile << fs->entries[index].word << ", " << fs->entries[index].meaning << ", " << fs->entries[index].partOfSpeech << endl;

    }
    outputFile.close();
}

void FileExplorer::FindByPOS(const string &POS, const string &output_path)
{
    //Saves the words on the given POS in a text file at the provided directory
    vector<int> result = POSIndex->Search(POS);
        ofstream outputFile(output_path);
        if (!outputFile.is_open()) {
            cerr << "Error: Unable to open output file." << endl;
            return;
        }
        outputFile << "word" << ", " << "meaning" << ", " << "partOfSpeech"<< '\n';
        for (int index : result) {
            outputFile << fs->entries[index].word << ", " << fs->entries[index].meaning << ", " << fs->entries[index].partOfSpeech << endl;
        }
    outputFile.close();
}

FileExplorer::~FileExplorer(){
    delete WordIndex;
    delete POSIndex;
    delete fs;
    WordIndex = POSIndex =  nullptr;
    fs = nullptr;
}