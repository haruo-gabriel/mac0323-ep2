#include "../lib.h"

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

class VO {
public:
    std::vector<Palavra*> vo; // vetor ordenado por ordem alfabética

    Palavra* value(std::string key);
    void add(std::string key);
    void printVO();
// private:
    int search(std::string key);
};