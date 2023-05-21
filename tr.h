#include "lib.h"

class NoTR {
public:
	NoTR* esq; NoTR* dir; NoTR* pai;
	int prioridade;
    std::string key;
    Item* value;

    NoTR(std::string key) {
        this->esq = this->dir = this->pai = nullptr;
        this->prioridade = rand()%MAXKEYS;
        this->key = key;
        this->value = new Item(key);
    }
};

class TR {
private:
    NoTR* raiz;
    void rotacionaEsquerda(NoTR* &r);
    void rotacionaDireita(NoTR* &r);
    NoTR* novoNoTR(std::string key);
    void addHelper(NoTR* &r, std::string key);
public:
    TR() { raiz = nullptr; };

    void add(std::string key);
    Item* value(std::string key);
    void inordem(NoTR* raiz);
    void printTR();
    void printHelper(NoTR* r, std::string indent, bool last);
    void printValue(Item* r);
};