#include "read.hpp"

Read::Read(){}
Read::~Read(){}

// um vector que vai receber uma liha do arquivo e organizar os dados, como {coluna, dado}, string texto
void Read::readFile(string arq, bool b, 
                        unordered_map<string, vector<int>> *data, 
                        unordered_map<int, vector<string>> *dataT, 
                        unordered_map<string, vector<int>> *classes){
    string path;
    path.assign("Arquivos/").append(arq).append(".csv");
    ifstream myfile(path);
    string line;
    int cont = 1;
    Token t;

    if (myfile.is_open())
        while (getline(myfile, line)) {
            if(b)
                t.tokenizar(line, cont++, data, classes);
            else
                t.tokenizarT(line, cont++, dataT, classes);
        }
    else
        cout << "nao foi possivel abrir o arquivo" << endl;

    unordered_map<string, vector<int>>::iterator itr;
    unordered_map<int, vector<string>>::iterator itrT;
}

