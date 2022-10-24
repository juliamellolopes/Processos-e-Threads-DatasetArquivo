#ifndef READ_HPP
#define READ_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "token.hpp"

using namespace std;

class Read {
private:
public:
	Read();
	~Read();
	void readFile(string arq, bool b, 
		unordered_map<string, vector<int>> *data, 
		unordered_map<int, vector<string>> *dataT,
		unordered_map<string, vector<int>> *classes);
};

#endif