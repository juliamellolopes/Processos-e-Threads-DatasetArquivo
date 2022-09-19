#include "read.hpp"

Read::Read(){}
Read::~Read(){}

// quebra de linha depois coluna
void Read::token(string linha, int cont, unordered_map<string, vector<int>> *data) {
    char del = ',';
    stringstream sstream(linha);
    string next;
    int coluna = 1;
    unordered_map<string, vector<int>>::iterator itr;
    vector<int> vec;


    while (getline(sstream, next, del)) {
        next.append("-").append(to_string(coluna++));
        itr = data->find(next);

        if (itr != data->end()) {
            itr->second.push_back(cont);
        } else {
            vec.clear();
            vec.push_back(cont);
            data->insert({next, vec});
        }
    }
}

void Read::tokenT(string linha, int cont, unordered_map<int, vector<string>> *data){
    char del = ',';
    stringstream sstream(linha);
    string next;
    int coluna = 1;
    vector<string> vec;


    while (getline(sstream, next, del)) {
        if(coluna < 5){
            next.append("-").append(to_string(coluna++));

            vec.push_back(next);
        }
    }
    data->insert({cont, vec});
}

// um vector que vai receber uma liha do arquivo e organizar os dados, como {coluna, dado}, string texto
void Read::readFile(string arq, bool b, unordered_map<string, vector<int>> *data, unordered_map<int, vector<string>> *dataT){
    string path;
    path.assign("Arquivos/").append(arq).append(".csv");
    ifstream myfile(path);
    string line;
    int cont = 1;

    if (myfile.is_open())
        while (getline(myfile, line)) {
            if(b)
                token(line, cont++, data);
            else
                tokenT(line, cont++, dataT);
        }
    else
        cout << "nao foi possivel abrir o arquivo" << endl;

    unordered_map<string, vector<int>>::iterator itr;
    unordered_map<int, vector<string>>::iterator itrT;
}

void Read::processamento(unordered_map<string, vector<int>> *data, unordered_map<int, vector<string>> *dataT, unordered_map<int, vector<string>> *combinacoes){
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

    // for(itT=c.begin();itT!=c.end();++itT){
    //     cout << itT->first << "\n";
    //     for(auto v : itT->second)
    //         cout << v << " ";
    //     cout << endl;
    // }

    for(itT = c.begin(); itT != c.end(); ++itT){
        combinacao(itT->second, combinacoes, itT->first);
    }
}

void Read::combinacao(vector<string> pega, unordered_map<int, vector<string>> *salva, int chave){
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