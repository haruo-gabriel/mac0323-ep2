#include "arn.h"

NoARN* ARN::valueHelper(NoARN* node, std::string key) {
    if (node == TNULL || key == node->key) {
        return node;
    }
    if (key < node->key) {
        return valueHelper(node->esq, key);
    } 
    return valueHelper(node->dir, key);
}

NoARN* ARN::value(std::string k) {
    return valueHelper(this->raiz, k);
}

void ARN::arruma(NoARN* k){
    NoARN* u;
    while (k->pai->cor == 1) {
        if (k->pai == k->pai->pai->dir) {
            u = k->pai->pai->esq; // uncle
            if (u->cor == 1) {
                // case 3.1
                u->cor = 0;
                k->pai->cor = 0;
                k->pai->pai->cor = 1;
                k = k->pai->pai;
            } else {
                if (k == k->pai->esq) {
                    // case 3.2.2
                    k = k->pai;
                    rotacionaDir(k);
                }
                // case 3.2.1
                k->pai->cor = 0;
                k->pai->pai->cor = 1;
                rotacionaEsq(k->pai->pai);
            }
        } else {
            u = k->pai->pai->dir; // uncle

            if (u->cor == 1) {
                // mirror case 3.1
                u->cor = 0;
                k->pai->cor = 0;
                k->pai->pai->cor = 1;
                k = k->pai->pai;	
            } else {
                if (k == k->pai->dir) {
                    // mirror case 3.2.2
                    k = k->pai;
                    rotacionaEsq(k);
                }
                // mirror case 3.2.1
                k->pai->cor = 0;
                k->pai->pai->cor = 1;
                rotacionaDir(k->pai->pai);
            }
        }
        if (k == raiz) {
            break;
        }
    }
    raiz->cor = 0;
}

void ARN::add(std::string key) {
    // Ordinary Binary Search addion
    NoARN* y = nullptr;
    NoARN* x = this->raiz;

    while (x != TNULL) {
        y = x;
        if (key < x->key)
            x = x->esq;
        else if (key > x->key)
            x = x->dir;
        else {
            x->numOcorrencias++;
            return;
        }
    }

    NoARN* node = new NoARN(key, true, nullptr, TNULL, TNULL);
    // NoARN* node = new NoARN();
    // node->pai = nullptr;
    // node->key = key;
    // node->esq = TNULL;
    // node->dir = TNULL;
    // node->cor = true; // must be red

    // y is pai of x
    node->pai = y;
    if (y == nullptr) {
        raiz = node;
    } else if (node->key < y->key) {
        y->esq = node;
    } else {
        y->dir = node;
    }

    // if new node is a raiz node, simply return
    if (node->pai == nullptr){
        node->cor = 0;
        return;
    }

    // if the grandpai is null, simply return
    if (node->pai->pai == nullptr) {
        return;
    }

    // Fix the tree
    arruma(node);
}

// rotaciona em x para esquerda
void ARN::rotacionaEsq(NoARN* x) {
    NoARN* y = x->dir;
    x->dir = y->esq;
    if (y->esq != TNULL) {
        y->esq->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == nullptr) {
        this->raiz = y;
    } else if (x == x->pai->esq) {
        x->pai->esq = y;
    } else {
        x->pai->dir = y;
    }
    y->esq = x;
    x->pai = y;
}

// rotaciona em x para direita
void ARN::rotacionaDir(NoARN* x) {
    NoARN* y = x->esq;
    x->esq = y->dir;
    if (y->dir != TNULL) {
        y->dir->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == nullptr) {
        this->raiz = y;
    } else if (x == x->pai->dir) {
        x->pai->dir = y;
    } else {
        x->pai->esq = y;
    }
    y->dir = x;
    x->pai = y;
}

void ARN::printHelper(NoARN* raiz, std::string indent, bool last) {
    // print the tree structure on the screen
    if (raiz != TNULL) {
        std::cout<<indent;
        if (last) {
            std::cout<<"R----";
            indent += "     ";
        } else {
            std::cout<<"L----";
            indent += "|    ";
        }
        
        std::string sColor = raiz->cor?"RED":"BLACK";
        std::cout<<raiz->key<<"("<<sColor<<")"<<std::endl;
        printHelper(raiz->esq, indent, false);
        printHelper(raiz->dir, indent, true);
    }
    // cout<<raiz->esq->key<<endl;
}