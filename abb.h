#ifndef ABB_H
#define ABB_H

#include "lib.h"

class NoABB {
public:
    std::string key;
    Item* value;
    NoABB* esq;
    NoABB* dir;

    NoABB(std::string key) {
        this->key = key;
        this->value = new Item(key);
        this->esq = nullptr;
        this->dir = nullptr;
    }
};

class ABB {
public:
    NoABB* raiz;
    ABB() {
        raiz = nullptr;
    };

    Item* value(std::string key);
    void add(std::string key);
    void printABB();
    void printHelper(NoABB* r, std::string indent, bool last);
};

#endif // ABB_H