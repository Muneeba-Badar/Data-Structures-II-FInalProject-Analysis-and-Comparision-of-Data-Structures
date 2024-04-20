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
#include "Treaps.hpp"
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
    auto start = steady_clock::now();
    FindByWord("BST", "./input/sampleData.txt", "./output/output_BST_find_by_word.txt","baby");
    auto stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Time taken by BST Find: "
        << duration.count() << " microseconds" << endl;

    FindByPOS("BST", "./input/sampleData.txt", "./output/output_BST_find_by_pos.txt","verb");

    auto start1 = steady_clock::now();
    FindByWord("AVL", "./input/sampleData.txt", "./output/output_AVL_find_by_word.txt","abandon");
    auto stop1 = steady_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1-start1);
    cout << "Time taken by AVL Find: "
        << duration1.count() << " microseconds" << endl;

    FindByPOS("AVL", "./input/sampleData.txt", "./output/output_AVL_find_by_pos.txt","noun");

    auto start2 = steady_clock::now();
    FindByWord("Treap", "./input/sampleData.txt", "./output/output_Treap_find_by_word.txt","baby");
    auto stop2 = steady_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2-start2);
    cout << "Time taken by Treap Find: "
        << duration2.count() << " microseconds" << endl;

    FindByPOS("Treap", "./input/sampleData.txt", "./output/output_Treap_find_by_pos.txt","verb");
    
    return 0;
}

