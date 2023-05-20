#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#define MAXKEYS 100000

int contaNumLetras(const std::string& s);
int contaNumVogaisUnicas(const std::string& s);
std::vector<std::string> separaPalavras(unsigned int n);
// void printValue(const Item& item);
// std::string palavrasMaisFrequentes(std::vector<Palavra*> palavras);
// int frequenciaPalavra(std::vector<Palavra*> palavras, std::string palavra);
// std::string palavraMaisLonga(std::vector<Palavra*> palavras);
// std::string palavraMaisLongaSemRepeticao(std::vector<Palavra*> palavras);
// std::string palavraMaisCurtaMaisVogaisSemRepeticao(std::vector<Palavra*> palavras);

// struct Key {
//     std::string key;
// };

struct Item {
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