#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>
#include "FileSystem.hpp"
#include "BST.hpp"
#include "AVL.hpp"
#include "FileExplorer.hpp"
#include <chrono>
using namespace std::chrono;
using namespace std;

void FindByWord(const string &index, const string &filename, const string &output_path, const string &key) {
    FileExplorer *fe = new FileExplorer(index, filename);
    fe->FindByWord(key, output_path);
    delete fe;
}
void FindByPOS(const string &index, const string &filename, const string &output_path, const string &date) {
    FileExplorer *fe = new FileExplorer(index, filename);
    fe->FindByPOS(date, output_path);
    delete fe;
}

int main()
{
    auto start = high_resolution_clock::now();
    FindByWord("BST", "./input/sampleData.txt", "./output/output_BST_find_by_word.txt","baby");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Time taken by BST Find: "
        << duration.count() << " microseconds" << endl;
    FindByPOS("BST", "./input/sampleData.txt", "./output/output_BST_find_by_pos.txt","verb");
    auto start1 = high_resolution_clock::now();
    FindByWord("AVL", "./input/sampleData.txt", "./output/output_AVL_find_by_word.txt","abandon");
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1-start1);
    cout << "Time taken by AVL Find: "
        << duration1.count() << " microseconds" << endl;
    FindByPOS("AVL", "./input/sampleData.txt", "./output/output_AVL_find_by_pos.txt","noun");
    
    return 0;
}

