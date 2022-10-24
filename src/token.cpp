#include "token.hpp"

Token::Token(){}
Token::~Token(){}

// quebra de linha depois coluna
void Token::tokenizar(string linha, int cont, unordered_map<string, vector<int>> *data,unordered_map<string, vector<int>> *classes) {
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

// token do arquivo T
void Token::tokenizarT(string linha, int cont, unordered_map<int, vector<string>> *data,unordered_map<string, vector<int>> *classes){
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

void Token::tokenizarLinha(string linha, vector<string> *resultado){
    char del = ',';
    stringstream sstream(linha);
    string token;

    while (getline(sstream, token, del)) {
        resultado->push_back(token);
    }

}