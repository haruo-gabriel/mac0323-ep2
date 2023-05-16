#include <iostream>
#include <string>
#include <vector>

// struct Key {
//     std::string key;
// };

#define MAXKEYS 100000

int contaNumLetras(std::string s);
int contaNumVogaisUnicas(std::string s);

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
    Item* value;

    Palavra(std::string key, Item* value) {
        this->key = key;
        this->value = new Item(key);
    }
};
