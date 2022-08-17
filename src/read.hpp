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
	void readFile();
    void token(string linha, int cont, unordered_map<string, vector<int>> *data);
};

#endif