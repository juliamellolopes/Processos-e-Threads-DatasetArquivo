#include "processamento.hpp"

Processamento::Processamento(){}
Processamento::~Processamento(){}

void Processamento::processo(unordered_map<string, vector<int>> *data, unordered_map<int, vector<string>> *dataT, unordered_map<int, vector<string>> *combinacoes){
    unordered_map<string, vector<int>>::iterator it;
    unordered_map<int, vector<string>>::iterator itT;
    unordered_map<int, vector<string>> c;
    vector<string> const2;

      for(itT=dataT->begin();itT!=dataT->end();++itT){
       const2.clear();
        for(auto v : itT->second){
            it = data->find(v); 
            if(it != data->end()){
                const2.push_back(v);
            }
        }
        c.insert({itT->first, const2});
    }

    for(itT = c.begin(); itT != c.end(); ++itT){
        combinacao(itT->second, combinacoes, itT->first);
    }
}

void Processamento::combinacao(vector<string> pega, unordered_map<int, vector<string>> *salva, int chave){
    vector<string>::iterator itT;
    vector<string>::iterator auxi;
    vector<string>::iterator iteri;
    vector<string> aux;
    string s = "";

    for(auto n : pega){
        s.append(n).append(",");
        aux.push_back(n);
    }

    if(pega.size() == 4){
        s.erase(s.end()-1,s.end());
        aux.push_back(s);
    }

    for(itT = pega.begin(); itT != pega.end(); ++itT){
        auxi = itT;
        ++auxi;
        for(auxi; auxi != pega.end(); ++auxi){
            s.assign(*itT).append(",").append(*auxi);
            aux.push_back(s);
        }
    }

    for(itT = pega.begin(); itT != pega.end(); ++itT){
        auxi = itT;
        ++auxi;
        for(auxi; auxi != pega.end(); ++auxi){
            iteri = auxi;
            ++iteri;
            for(iteri; iteri != pega.end(); ++iteri){
                s.assign(*itT).append(",").append(*auxi).append(",").append(*iteri);
                aux.push_back(s);
            }
        }
    }

    salva->insert({chave, aux});
}