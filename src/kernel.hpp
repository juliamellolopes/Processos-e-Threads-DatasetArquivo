#ifndef KERNEL_HPP
#define KERNEL_HPP

#include <iostream>  
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Kernel {
private:
public:
	Kernel();
    ~Kernel();
    void intersecao(vector<int>first, vector<int>second, vector<int> *resultado);
    void interesecoes(unordered_map<int, vector<string>> *salva);
};

#endif