#include "arn.h"

// insert the key to the tree in its appropriate position
// and fix the tree
void ARN::add(std::string key) {
    // Ordinary Binary Search Insertion
    NoARN* y = nullptr;
    NoARN* x = this->raiz;

    while (x != nullptr) {
        y = x;
        if (key < x->key) x = x->esq;
        else if (key > x->key) x = x->dir;
        else { // if key == x->key
            x->numOcorrencias++;
            return;
        }
    }

    NoARN* node = new NoARN(key, nullptr);

    // y is pai of x
    node->pai = y;
    if (y == nullptr) raiz = node;
    else if (node->key < y->key) y->esq = node;
    else if (node->key > y->key) y->dir = node;

    // if new node is a raiz node, simply return
    if (node->pai == nullptr){
        node->cor = false;
        return;
    }

    // if the avo is null, simply return
    if (node->pai->pai == nullptr) return;

    // Fix the tree
    arruma(node);
}

void ARN::arruma(NoARN* k){
    NoARN* u;
    while (k->pai->cor) {
        if (k->pai == k->pai->pai->dir) {
            u = k->pai->pai->esq; // tio
            if (u->cor || u == nullptr) {
                // case 3.1
                if (u == nullptr)
                    u = new NoARN(" ", k->pai);
                u->cor = 0;
                k->pai->cor = false;
                k->pai->pai->cor = true;
                k = k->pai->pai;
            } else {
                if (k == k->pai->esq) {
                    // case 3.2.2
                    k = k->pai;
                    rotacionaDireita(k);
                }
                // case 3.2.1
                k->pai->cor = 0;
                k->pai->pai->cor = 1;
                rotacionaEsquerda(k->pai->pai);
            }
        } else {
            u = k->pai->pai->dir; // tio

            if (u->cor || u == nullptr) {
                // mirror case 3.1
                if (u == nullptr)
                    u = new NoARN(" ", k->pai->pai);
                u->cor = false;
                k->pai->cor = false;
                k->pai->pai->cor = true;
                k = k->pai->pai;	
            } else {
                if (k == k->pai->dir) {
                    // mirror case 3.2.2
                    k = k->pai;
                    rotacionaEsquerda(k);
                }
                // mirror case 3.2.1
                k->pai->cor = false;
                k->pai->pai->cor = true;
                rotacionaDireita(k->pai->pai);
            }
        }
        if (k == raiz) {
            break;
        }
    }
    raiz->cor = false;
}

// rotate esq at node x
void ARN::rotacionaEsquerda(NoARN* x) {
    NoARN* y = x->dir;
    x->dir = y->esq;
    if (y->esq != nullptr) {
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

// rotate dir at node x
void ARN::rotacionaDireita(NoARN* x) {
    NoARN* y = x->esq;
    x->esq = y->dir;
    if (y->dir != nullptr) {
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

NoARN* ARN::value(std::string k) {
    return searchTreeHelper(this->raiz, k);
}

NoARN* ARN::searchTreeHelper(NoARN* node, std::string key) {
    if (node == nullptr || key == node->key)
        return node;
    if (key < node->key)
        return searchTreeHelper(node->esq, key);
    return searchTreeHelper(node->dir, key);
}

void ARN::printHelper(NoARN* root, std::string indent, bool last) {
    // print the tree structure on the screen
    if (root != nullptr) {
        std::cout << indent;
        if (last) {
            std::cout << "R----";
            indent += "     ";
        } else {
            std::cout<<"L----";
            indent += "|    ";
        }
        
        std::string sColor = root->cor ? "RED":"BLACK";
        std::cout << root->key << "(" << sColor << ")" << std::endl;
        printHelper(root->esq, indent, false);
        printHelper(root->dir, indent, true);
    }
    // cout<<root->left->data<<endl;
}

void ARN::prettyPrint() {
    if (this->raiz) printHelper(this->raiz, "", true);
}