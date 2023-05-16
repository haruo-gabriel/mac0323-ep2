#include "../lib.h"

class NoTR {
public:
	NoTR* esq; NoTR* dir; NoTR* pai;
	int prioridade;
    Palavra* palavra;

    NoTR(std::string key, Item* value) {
        esq = dir = pai = nullptr;
        prioridade = rand()%MAXKEYS;
        palavra = new Palavra(key, value);
    }
};

class TR {
public:
    NoTR* raiz;
    TR() {
        raiz = nullptr;
    };

    void rotacionaEsquerda(NoTR* &root);
    void rotacionaDireita(NoTR* &root);
    NoTR* novoNoTR(std::string key, Item* value);
    Item* value(std::string key);
    void add(NoTR* &root, std::string key, Item* value);
    void inordem(NoTR* raiz);
};