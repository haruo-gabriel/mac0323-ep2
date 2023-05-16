#include "../lib.h"

// class Word {
// public:
//     std::string key;
//     int numOcorrencias;
//     int numLetras;
//     int numVogais; // número de vogais não-repetidas

//     Word(std::string key) {
//         this->key = key;
//         this->numOcorrencias = 1;
//         this->numLetras = contaNumLetras(key);
//         this->numVogais = contaNumVogaisUnicas(key);
//     }
// };

class NoARN {
public:
    NoARN* esq; NoARN* dir; NoARN* pai;
    bool cor; // true = vermelho, false = preto
    // Word* palavra;
    std::string key;
    int numOcorrencias;
    int numLetras;
    int numVogais; // número de vogais não-repetidas

    NoARN(std::string key, NoARN* pai) {
        this->esq = this->dir = nullptr;
        this->pai = pai;
        this->cor = true;
        this->key = key;
        this->numOcorrencias = 1;
        this->numLetras = contaNumLetras(key);
        this->numVogais = contaNumVogaisUnicas(key);
    }
};

class ARN {
public:
    NoARN* raiz;
    ARN() { raiz = nullptr; };
    void add(std::string key);
    NoARN* value(std::string k);
    void prettyPrint();

private:
    void arruma(NoARN* k);
    void rotacionaEsquerda(NoARN* x);
    void rotacionaDireita(NoARN* x);
    NoARN* searchTreeHelper(NoARN* node, std::string key);
    void printHelper(NoARN* root, std::string indent, bool last);
};