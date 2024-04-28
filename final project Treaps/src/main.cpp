#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>
#include "FileSystem.hpp"
#include "Treaps.hpp"
#include "FileExplorer.hpp"
#include <chrono>
using namespace std::chrono;
using namespace std;

void FindByWord(const string &filename, const string &output_path, const string &word) {
    FileExplorer *fe = new FileExplorer(filename);
    fe->FindByWord(word, output_path);
    delete fe;
}

void InsertNewWord(const string &filename, const string &word) {
    FileExplorer *fe = new FileExplorer(filename);
    fe->InsertWord(word);
    delete fe;
}

int main()
{
    //Treaps
    vector<string> wordList {"fell", "calpulli", "lemography", "unplentiful", "unturbid", "media", "snowbird", "vilayet", "universology", "differentiable"}; //dataSet1
    // vector<string> wordList2 {"saily", "flabellum", "responsive", "aeolicism", "misperceive", "forset", "semiautomatic", "kitcheny", "implorator", "nuance"}; //dataSet2
    // vector<string> wordList3 {"prelocate", "archvillainy", "ophiurid", "zoomantic", "nympholept", "joinant", "oghamic", "gersum", "uncondescending", "syllis"}; //dataSet3
    // vector<string> wordList4 {"intraovarian", "vaginipennate", "footfarer", "insignia", "servomechanism", "lower", "submitter", "cullis", "seligmannite", "rechristen"}; //dataSet4
    // vector<string> wordList5 {"percylite", "enteroischiocele", "pincoffin", "serratoglandulous", "interknit", "prisonful", "gutlike", "trichogenous", "waterdoe", "bice"}; //dataSet5
    // vector<string> wordList6 {"divisional", "pinfeather", "repayal", "unwadeable", "achigan", "sainfoin", "tammy", "helm", "liebfraumilch", "forwardal"}; //dataSet6
    // vector<string> wordList7 {"fijian", "venkata", "erotylidae", "automorphic", "exile", "abluvion", "nietzschean", "drudgery", "saburral", "mucroniferous"}; //dataSet7
    // vector<string> wordList8 {"yee", "demob", "hydrophora", "lupid", "grissel", "triamino", "garfish", "costing", "springerle", "laceless"}; //dataSet8
    // vector<string> wordList9 {"babite", "rejuvenescence", "unequaled", "reglue", "lophiidae", "pox", "apprizer", "stradl", "panama", "tripinnatisect"}; //dataSet9
    // vector<string> wordList10 {"latian", "divellent", "epidermal", "celestially", "agnoetism", "towerwise", "repentable", "thready", "emblemology", "upwarp"}; //dataSet10
    vector<string> insertList {"iam", "outof", "ideasnow", "whatto", "addtothe", "datasetin", "myfinal", "datastrutures","twoproject","theend"};

//search
    // ofstream timeFile("./output/time.csv");
    // for(int j=1; j<11;j++){
    //     string inputFileName = "./input/dataSet"+to_string(j)+".csv";
    //     for (int i=0; i<10;i++){
    //         auto start = steady_clock::now();
    //         FindByWord(inputFileName, "./output/output_Treap_find_by_word.txt",wordList[i]);
    //         auto stop = steady_clock::now();
    //         auto duration = duration_cast<microseconds>(stop-start);
    //         // cout << "Time taken by Treap Find by Word: "
    //         //     << duration.count() << " microseconds" << endl;
    //         timeFile<<duration.count()<<", ";
    //     }
    //     timeFile<<'\n';
    // }
    // timeFile.close();
//insert
    ofstream timeFile("./output/timeInsert.csv");
    for(int j=1; j<11;j++){
        string inputFileName = "./input/dataSet"+to_string(j)+".csv";
        for (int i=0;i<10;i++){
            auto start = steady_clock::now();
            InsertNewWord(inputFileName, insertList[i]);
            auto stop = steady_clock::now();
            auto duration = duration_cast<microseconds>(stop-start);
            // cout << "Time taken by Treap Find by Word: "
            //     << duration.count() << " microseconds" << endl;
            timeFile<<duration.count()<<", ";
        }
        timeFile<<'\n';
    }
    timeFile.close();

    return 0;
}

