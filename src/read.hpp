#ifndef READ_HPP
#define READ_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Read {
private:
public:
	Read();
	~Read();
	void readFile(string arq, bool b, 
		unordered_map<string, vector<int>> *data, 
		unordered_map<int, vector<string>> *dataT);
    void token(string linha, int cont, unordered_map<string, vector<int>> *data);
	void tokenT(string linha, int cont, unordered_map<int, vector<string>> *dataT);
	void processamento(unordered_map<string, vector<int>> *data, unordered_map<int, vector<string>> *dataT,  unordered_map<int, vector<string>> *combinacoes);
	void combinacao(vector<string> pega, unordered_map<int, vector<string>> *salva, int chave);
};

#endif