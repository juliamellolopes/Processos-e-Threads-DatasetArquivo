#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Token {
private:
public:
    Token();
    ~Token();
    void tokenizar(string linha, int cont, unordered_map<string, vector<int>> *data, 
                    unordered_map<string, vector<int>> *classes);
	void tokenizarT(string linha, int cont, unordered_map<int, vector<string>> *dataT,
                    unordered_map<string, vector<int>> *classes);
    void tokenizarLinha(string linha, vector<string> *resultado);
};

#endif