#include "arn.h"

// void ARN::add(std::string key) {
//     // árvore vazia
//     if (this->raiz == nullptr) {
//         this->raiz = new NoARN(key, nullptr);
//         return;
//     }
//     // árvore não-vazia
//     NoARN* p = raiz;
//     // busca em ABB
//     while (p != nullptr) {
//         if (key < p->key) {
//             if (p->esq == nullptr) {
//                 p->esq = new NoARN(key, p);
//                 p = p->esq;
//                 break;
//             } else
//                 p = p->esq;
//         } else if (key > p->key) {
//             if (p->dir == nullptr) {
//                 p->dir = new NoARN(key, p);
//                 p = p->dir;
//                 break;
//             } else
//                 p = p->dir;
//         } else {
//             p->numOcorrencias++;
//             return;
//         }
//     }
//     if (p->pai == nullptr) { // p é raíz
//         this->raiz = p;
//         return;
//     }
//     if (!p->pai->cor) // pai é preto
//         return;
//     else { // pai é vermelho
//         if (p->pai->pai == nullptr) // não tem avô
//             p->pai->cor = false;
//         else { // tem avô (o avô é preto)

//         }
//     }
    
// }

// insert the key to the tree in its appropriate position
// and fix the tree
void ARN::add(std::string key) {
    // Ordinary Binary Search Insertion
    NoARN* node = new NoARN(key, nullptr);
    NoARN* y = nullptr;
    NoARN* x = this->raiz;

    while (x != nullptr) {
        y = x;
        if (node->key < x->key) {
            x = x->esq;
        } else if (node->key > key) {
            x = x->dir;
        }
    }


    // y is pai of x
    node->pai = y;
    if (y == nullptr) raiz = node;
    else if (node->key < y->key) y->esq = node;
    else if (node->key > y->key) y->dir = node;

    // if new node is a raiz node, simply return
    if (node->pai == nullptr){
        node->cor = 0;
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
				u = k->pai->pai->esq; // uncle
				if (u->cor) {
					// case 3.1
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
				u = k->pai->pai->dir; // uncle

				if (u->cor) {
					// mirror case 3.1
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