#include "../lib.h"

class NoABB {
public:
    NoABB* esq;
    NoABB* dir;
    Palavra* palavra;

    NoABB(std::string key, Item* value) {
        esq = nullptr;
        dir = nullptr;
        palavra = new Palavra(key, value);
    }
};

class ABB {
public:
    NoABB* raiz;
    ABB() {
        raiz = nullptr;
    };

    Item* value(std::string key);
    void add(std::string key, Item* value);
    void printABB(NoABB* p);
};