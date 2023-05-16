#include "tr.h"
/* T1, T2 and T3 are subtrees of the tree raized with y
(on esq side) or x (on dir side)
				y							 x
			/ \	 Right Rotation		 / \
			x T3 – – – – – – – >	 T1 y
			/ \	 < - - - - - - -		 / \
			T1 T2	 Left Rotation		 T2 T3 */

// A utility function to dir rotate subtree raized with y
// See the diagram given above.

Item* TR::value(std::string key) {
    NoTR* p = raiz;
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

void TR::rotacionaEsquerda(NoTR* &root) { //left rotation
   NoTR* R = root->dir;
   NoTR* X = root->dir->esq;
   R->esq = root;
   root->dir= X;
   root = R;
}
void TR::rotacionaDireita(NoTR* &root) { //right rotation
   NoTR* L = root->esq;
   NoTR* Y = root->esq->dir;
   L->dir = root;
   root->esq = Y;
   root = L;
}

void TR::add(NoTR* &root, std::string key, Item* value) { //insertion
	if (root == nullptr) {
		root = new NoTR(key, value);
		return;
	}
	if (key < root->palavra->key) {
		add(root->esq, key, value);
		if (root->esq != nullptr && root->esq->prioridade > root->prioridade)
			TR::rotacionaDireita(root);
	} else {
		add(root->dir, key, value);
		if (root->dir != nullptr && root->dir->prioridade > root->prioridade)
			TR::rotacionaEsquerda(root);
	}
}

NoTR* TR::novoNoTR(std::string key, Item* value) {
	NoTR* temp = new NoTR(key, value);
	return temp;
}

void TR::inordem(NoTR* raiz) {
	if (raiz)
	{
		inordem(raiz->esq);
		std::cout << "key: "<< raiz->palavra->key << " | prioridade: "
			<< raiz->prioridade;
		if (raiz->esq)
			std::cout << " | filho esq: " << raiz->esq->palavra->key;
		if (raiz->dir)
			std::cout << " | filho dir: " << raiz->dir->palavra->key;
		std::cout << std::endl;
		inordem(raiz->dir);
	}
}

