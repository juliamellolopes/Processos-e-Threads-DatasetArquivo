#include "kernel.hpp"

Kernel::Kernel(){}
Kernel::~Kernel(){}

void Kernel::intersecao(vector<int>first, vector<int>second, vector<int> *resultado){
    resultado->resize(first.size()+second.size());                     
    vector<int>::iterator it;

    sort (first.begin(),first.end());     
    sort (second.begin(),second.end());

    it=set_intersection (first.begin(), first.end(), second.begin(), second.end(), resultado->begin());
                                               
    resultado->resize(it-resultado->begin());              
}

void Kernel::interesecoes(unordered_map<int, vector<string>> *salva){
    unordered_map<int, vector<string>>::iterator itT;
    
    for(itT=salva->begin();itT!=salva->end();++itT){
        // cout << itT->first << "\n";
        for(auto v : itT->second){
            
        }
            // cout << v << " " << endl;
        // cout << endl << endl;
    }
}