#include "lib.h"
class NoARN{
public:
	std::string key;
	int numOcorrencias, numLetras, numVogaisUnicas;
	NoARN* pai; NoARN* esq; NoARN* dir;
	bool cor; // true = vermelho, false = preto

	NoARN(std::string key, bool cor, NoARN* pai, NoARN* esq, NoARN* dir) {
		this->key = key;
		this->numOcorrencias = 1;
		this->numLetras = contaNumLetras(key);
		this->numVogaisUnicas = contaNumVogaisUnicas(key);
		this->pai = pai; this->esq = esq; this->dir = dir;
		this->cor = cor;
	}
};

class ARN {
private:
	NoARN* raiz;
	NoARN* TNULL;

	NoARN* valueHelper(NoARN* node, std::string key);
	void arruma(NoARN* k);
	void printHelper(NoARN* raiz, std::string indent, bool last);

	// initializes the nodes with appropriate values
	// all the pointers are set to point to the null pointer
	void initializeNULLNode(NoARN* node, NoARN* pai) {
		node->key = "";
		node->pai = pai;
		node->esq = nullptr;
		node->dir = nullptr;
		node->cor = 0;
	}

	// void preOrderHelper(NoARN* node) {
	// 	if (node != TNULL) {
	// 		std::cout<<node->key<<" ";
	// 		preOrderHelper(node->esq);
	// 		preOrderHelper(node->dir);
	// 	} 
	// }

	// void inOrderHelper(NoARN* node) {
	// 	if (node != TNULL) {
	// 		inOrderHelper(node->esq);
	// 		std::cout<<node->key<<" ";
	// 		inOrderHelper(node->dir);
	// 	} 
	// }

	// void postOrderHelper(NoARN* node) {
	// 	if (node != TNULL) {
	// 		postOrderHelper(node->esq);
	// 		postOrderHelper(node->dir);
	// 		std::cout<<node->key<<" ";
	// 	} 
	// }

	// // fix the rb tree modified by the delete operation
	// void fixDelete(NoARN* x) {
	// 	NoARN* s;
	// 	while (x != raiz && x->cor == 0) {
	// 		if (x == x->pai->esq) {
	// 			s = x->pai->dir;
	// 			if (s->cor == 1) {
	// 				// case 3.1
	// 				s->cor = 0;
	// 				x->pai->cor = 1;
	// 				rotacionaEsq(x->pai);
	// 				s = x->pai->dir;
	// 			}

	// 			if (s->esq->cor == 0 && s->dir->cor == 0) {
	// 				// case 3.2
	// 				s->cor = 1;
	// 				x = x->pai;
	// 			} else {
	// 				if (s->dir->cor == 0) {
	// 					// case 3.3
	// 					s->esq->cor = 0;
	// 					s->cor = 1;
	// 					rotacionaDir(s);
	// 					s = x->pai->dir;
	// 				} 

	// 				// case 3.4
	// 				s->cor = x->pai->cor;
	// 				x->pai->cor = 0;
	// 				s->dir->cor = 0;
	// 				rotacionaEsq(x->pai);
	// 				x = raiz;
	// 			}
	// 		} else {
	// 			s = x->pai->esq;
	// 			if (s->cor == 1) {
	// 				// case 3.1
	// 				s->cor = 0;
	// 				x->pai->cor = 1;
	// 				rotacionaDir(x->pai);
	// 				s = x->pai->esq;
	// 			}

	// 			if (s->dir->cor == 0 && s->dir->cor == 0) {
	// 				// case 3.2
	// 				s->cor = 1;
	// 				x = x->pai;
	// 			} else {
	// 				if (s->esq->cor == 0) {
	// 					// case 3.3
	// 					s->dir->cor = 0;
	// 					s->cor = 1;
	// 					rotacionaEsq(s);
	// 					s = x->pai->esq;
	// 				} 

	// 				// case 3.4
	// 				s->cor = x->pai->cor;
	// 				x->pai->cor = 0;
	// 				s->esq->cor = 0;
	// 				rotacionaDir(x->pai);
	// 				x = raiz;
	// 			}
	// 		} 
	// 	}
	// 	x->cor = 0;
	// }


	// void rbTransplant(NoARN* u, NoARN* v){
	// 	if (u->pai == nullptr) {
	// 		raiz = v;
	// 	} else if (u == u->pai->esq){
	// 		u->pai->esq = v;
	// 	} else {
	// 		u->pai->dir = v;
	// 	}
	// 	v->pai = u->pai;
	// }

	// void deleteNodeHelper(NoARN* node, std::string key) {
	// 	// find the node containing key
	// 	NoARN* z = TNULL;
	// 	NoARN* x; NoARN* y;
	// 	while (node != TNULL){
	// 		if (node->key == key) {
	// 			z = node;
	// 		}

	// 		if (node->key <= key) {
	// 			node = node->dir;
	// 		} else {
	// 			node = node->esq;
	// 		}
	// 	}

	// 	if (z == TNULL) {
	// 		std::cout<<"Couldn't find key in the tree"<<std::endl;
	// 		return;
	// 	} 

	// 	y = z;
	// 	int y_original_cor = y->cor;
	// 	if (z->esq == TNULL) {
	// 		x = z->dir;
	// 		rbTransplant(z, z->dir);
	// 	} else if (z->dir == TNULL) {
	// 		x = z->esq;
	// 		rbTransplant(z, z->esq);
	// 	} else {
	// 		y = minimum(z->dir);
	// 		y_original_cor = y->cor;
	// 		x = y->dir;
	// 		if (y->pai == z) {
	// 			x->pai = y;
	// 		} else {
	// 			rbTransplant(y, y->dir);
	// 			y->dir = z->dir;
	// 			y->dir->pai = y;
	// 		}

	// 		rbTransplant(z, y);
	// 		y->esq = z->esq;
	// 		y->esq->pai = y;
	// 		y->cor = z->cor;
	// 	}
	// 	delete z;
	// 	if (y_original_cor == 0){
	// 		fixDelete(x);
	// 	}
	// }
	

public:
	ARN() {
		TNULL = new NoARN("", false, nullptr, nullptr, nullptr);
		// TNULL = new NoARN();
		// TNULL->cor = false;
		// TNULL->esq = nullptr;
		// TNULL->dir = nullptr;
		raiz = TNULL;
	}

	NoARN* value(std::string k);
	void rotacionaEsq(NoARN* x);
	void rotacionaDir(NoARN* x);
    
	void add(std::string key);

	// print the tree structure on the screen
	void printARN();

	// imprime as values de uma key
	void printValue(NoARN* node) {
			std::cout << "Key: " << node->key << std::endl;
			std::cout << "Ocorrências: " << node->numOcorrencias << std::endl;
			std::cout << "Número de letras: " << node->numLetras << std::endl;
			std::cout << "Número de vogais não-repetidas: " << node->numVogaisUnicas << std::endl;
	}

	// // Pre-Order traversal
	// // Node->Left Subtree->Right Subtree
	// void preorder() {
	// 	preOrderHelper(this->raiz);
	// }

	// // In-Order traversal
	// // Left Subtree -> Node -> Right Subtree
	// void inorder() {
	// 	inOrderHelper(this->raiz);
	// }

	// // Post-Order traversal
	// // Left Subtree -> Right Subtree -> Node
	// void postorder() {
	// 	postOrderHelper(this->raiz);
	// }

	// // find the node with the minimum key
	// NoARN* minimum(NoARN* node) {
	// 	while (node->esq != TNULL) {
	// 		node = node->esq;
	// 	}
	// 	return node;
	// }

	// // find the node with the maximum key
	// NoARN* maximum(NoARN* node) {
	// 	while (node->dir != TNULL) {
	// 		node = node->dir;
	// 	}
	// 	return node;
	// }

	// // find the successor of a given node
	// NoARN* successor(NoARN* x) {
	// 	// if the dir subtree is not null,
	// 	// the successor is the esqmost node in the
	// 	// dir subtree
	// 	if (x->dir != TNULL) {
	// 		return minimum(x->dir);
	// 	}

	// 	// else it is the lowest ancestor of x whose
	// 	// esq child is also an ancestor of x.
	// 	NoARN* y = x->pai;
	// 	while (y != TNULL && x == y->dir) {
	// 		x = y;
	// 		y = y->pai;
	// 	}
	// 	return y;
	// }

	// // find the predecessor of a given node
	// NoARN* predecessor(NoARN* x) {
	// 	// if the esq subtree is not null,
	// 	// the predecessor is the dirmost node in the 
	// 	// esq subtree
	// 	if (x->esq != TNULL) {
	// 		return maximum(x->esq);
	// 	}

	// 	NoARN* y = x->pai;
	// 	while (y != TNULL && x == y->esq) {
	// 		x = y;
	// 		y = y->pai;
	// 	}

	// 	return y;
	// }

	// NoARN* getRoot(){
	// 	return this->raiz;
	// }

	// // delete the node from the tree
	// void deleteNode(std::string key) {
	// 	deleteNodeHelper(this->raiz, key);
	// }


};