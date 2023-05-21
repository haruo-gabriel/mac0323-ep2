#include "tr.h"

Item* TR::value(std::string key) {
	NoTR* p = raiz;
	while (p != nullptr) {
		if (p->key == key)
			return p->value;
		else if (p->key > key)
			p = p->esq;
		else
			p = p->dir;
	}
	return nullptr;
}

void TR::printValue(Item* item) {
	if (item == nullptr) {
		std::cout << "Item não encontrado" << std::endl;
		return;
	}
	std::cout << "Ocorrências: " << item->numOcorrencias;
	std::cout << " | Letras: " << item->numLetras;
	std::cout << " | Vogais: " << item->numVogais << std::endl;
}

void TR::rotacionaEsquerda(NoTR* &r) {
	NoTR* R = r->dir;
	NoTR* X = r->dir->esq;
	R->esq = r;
	r->dir= X;
	r = R;
}
void TR::rotacionaDireita(NoTR* &r) {
	NoTR* L = r->esq;
	NoTR* Y = r->esq->dir;
	L->dir = r;
	r->esq = Y;
	r = L;
}

void TR::addHelper(NoTR* &r, std::string key) {
	if (r == nullptr) {
		r = new NoTR(key);
		return; 
	}
	if (r->key == key) {
		r->value->numOcorrencias++;
	}
	else if (key < r->key) {
		addHelper(r->esq, key);
		if (r->esq != nullptr && r->esq->prioridade > r->prioridade)
			TR::rotacionaDireita(r);
	}
	else { // if (key > r->key) {
		addHelper(r->dir, key);
		if (r->dir != nullptr && r->dir->prioridade > r->prioridade)
			TR::rotacionaEsquerda(r);
	}
}

void TR::add(std::string key) {
	TR::addHelper(this->raiz, key);
}

NoTR* TR::novoNoTR(std::string key) {
	NoTR* temp = new NoTR(key);
	return temp;
}

void TR::inordem(NoTR* r) {
	if (r) {
		inordem(r->esq);
		std::cout << "key: "<< r->key << " | prioridade: "
			<< r->prioridade;
		if (raiz->esq)
			std::cout << " | filho esq: " << raiz->esq->key;
		if (raiz->dir)
			std::cout << " | filho dir: " << raiz->dir->key;
		std::cout << std::endl;
		inordem(raiz->dir);
	}
}

void TR::printTR() {
	if (raiz) printHelper(this->raiz, "", true); 
}

void TR::printHelper(NoTR* r, std::string indent, bool last) {
	if (r != nullptr) {
		std::cout<<indent;
		if (last) {
			std::cout<<"R----";
			indent += "     ";
		}
		else {
			std::cout<<"L----";
			indent += "|    ";
		}
		std::cout << r->key << std::endl;
		printHelper(r->esq, indent, false);
		printHelper(r->dir, indent, true);
	}
	// cout<<raiz->esq->key<<endl;
}
