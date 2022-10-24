#ifndef PROCESSAMENTO_HPP
#define PROCESSAMENTO_HPP

#include <iostream>  
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class Processamento {
private:
public:
    Processamento();
    ~Processamento();
    void processo(unordered_map<string, vector<int>> *data, unordered_map<int, vector<string>> *dataT,  unordered_map<int, vector<string>> *combinacoes);
	void combinacao(vector<string> pega, unordered_map<int, vector<string>> *salva, int chave);
};

#endif