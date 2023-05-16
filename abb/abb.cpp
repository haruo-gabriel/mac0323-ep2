#include "abb.h"

void ABB::add(std::string key, Item* value) {
    if (ABB::raiz == nullptr) {
        ABB::raiz = new NoABB(key, value);
        return;
    }
    NoABB* p = ABB::raiz;
    while (p != nullptr) {
        if (key < p->palavra->key) {
            if (p->esq == nullptr) {
                p->esq = new NoABB(key, value);
                return;
            } else
                p = p->esq;
        } else if (key > p->palavra->key) {
            if (p->dir == nullptr) {
                p->dir = new NoABB(key, value);
                return;
            } else
                p = p->dir;
        } else {
            p->palavra->value->numOcorrencias++;
            return;
        }
    }
}

Item* ABB::value(std::string key) {
    NoABB* p = raiz;
    while (p != nullptr) {
        if (p->palavra->key == key)
            return p->palavra->value;
        else if (p->palavra->key > key)
            p = p->esq;
        else
            p = p->dir;
    }
    return nullptr;
}

void ABB::printABB(NoABB* p) {
    if (p != nullptr) {
        printABB(p->esq);
        std::cout << p->palavra->key << " ";
        std::cout << p->palavra->value->numOcorrencias << " ";
        printABB(p->dir);
    }
}