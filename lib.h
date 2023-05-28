#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#define MAXKEYS 1000000

std::vector<std::string> separaPalavras(unsigned int n);
int contaNumLetras(const std::string& s);
int contaNumVogaisUnicas(const std::string& s);
bool repeteLetras(std::string key);
bool repeteVogais(std::string key);

// struct Key {
// 	std::string key;
// };

class Item {
public:
	int numOcorrencias;
	int numLetras;
	int numVogais; // número de vogais não-repetidas

	Item(std::string key) {
		this->numOcorrencias = 1;
		this->numLetras = contaNumLetras(key);
		this->numVogais = contaNumVogaisUnicas(key);
	}
};

struct Palavra {
	std::string key;
	// Item* value;
	int numOcorrencias;
	int numLetras;
	int numVogais; // número de vogais não-repetidas

	Palavra(std::string key) {
		this->key = key;
		this->numOcorrencias = 1;
		this->numLetras = contaNumLetras(key);
		this->numVogais = contaNumVogaisUnicas(key);
	}
};

#endif // LIB_H