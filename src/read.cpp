#include "read.hpp"

Read::Read(){}
Read::~Read(){}

// quebra de linha depois coluna
void token(string linha, int cont, unordered_map<string, vector<int>> *data) {
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

// um vector que vai receber uma liha do arquivo e organizar os dados, como {coluna, dado}, string texto
void Read::readFile(){
    unordered_map<string, vector<int>> data;
    ifstream myfile("Arquivos/D.csv");
    string line;
    int cont = 1;

    if (myfile.is_open())
        while (getline(myfile, line)) {
            token(line, cont++, &data);
        }
    else
        cout << "nao foi possivel abrir o arquivo" << endl;

    unordered_map<string, vector<int>>::iterator itr;

    for (itr = data.begin(); itr != data.end(); ++itr) {

        cout << itr->first << " ";
        
        for (int str : itr->second) {
            cout << str << " ";
        }
        cout << endl;
    }
}