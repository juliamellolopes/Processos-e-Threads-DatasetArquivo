#include "read.hpp"
#include "processamento.hpp"
#include "kernel.hpp"

int main(){

    Read r;
    Processamento p;
    Kernel k;
    Token t;

    unordered_map<string, vector<int>> data;
    unordered_map<int, vector<string>> dataT;
    unordered_map<int, vector<string>> combinacoes;
    unordered_map<string, vector<int>>::iterator itT;
    vector<int>::iterator it;
    unordered_map<string, vector<int>> classes;

    r.readFile("D", true, &data, &dataT, &classes);
    r.readFile("T", false, &data, &dataT, &classes);
    p.processo(&data, &dataT, &combinacoes);
    k.interesecoes(&combinacoes);
  
    return 0;
}