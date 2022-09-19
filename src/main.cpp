#include "read.hpp"

int main(){

    Read r;
    unordered_map<string, vector<int>> data;
    unordered_map<int, vector<string>> dataT;
    unordered_map<int, vector<string>> combinacoes;
    unordered_map<int, vector<string>>::iterator itT;

    r.readFile("D", true, &data, &dataT);
    r.readFile("T", false, &data, &dataT);
    r.processamento(&data, &dataT, &combinacoes);

    for(itT=combinacoes.begin();itT!=combinacoes.end();++itT){
        cout << itT->first << "\n";
        for(auto v : itT->second)
            cout << v << " " << endl;
        cout << endl << endl;
    }
  
    return 0;
}