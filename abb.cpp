#include "abb.h"

void ABB::add(std::string key) {
	if (ABB::raiz == nullptr) {
			ABB::raiz = new NoABB(key);
			return;
	}
	NoABB* p = ABB::raiz;
	while (p != nullptr) {
		if (key < p->key) {
			if (p->esq == nullptr) {
				p->esq = new NoABB(key);
				return;
			}
			else p = p->esq;
		}
		else if (key > p->key) {
			if (p->dir == nullptr) {
				p->dir = new NoABB(key);
				return;
			}
			else p = p->dir;
		}
		else {
			p->value->numOcorrencias++;
			return;
		}
	}
}

Item* ABB::value(std::string key) {
	NoABB* p = raiz;
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

void ABB::printABB() {
	if (raiz) printHelper(this->raiz, "", true);
}

void ABB::printHelper(NoABB* r, std::string indent, bool last) {
	if (r != nullptr) {
		std::cout<<indent;
		if (last) {
			std::cout<<"R----";
			indent += "     ";
		} else {
			std::cout<<"L----";
			indent += "|    ";
		}
		
		std::cout << r->key << std::endl;
		printHelper(r->esq, indent, false);
		printHelper(r->dir, indent, true);
	}
	// cout<<raiz->esq->key<<endl;
}

void ABB::printInordem() { printInordemHelper(raiz); }

void ABB::printInordemHelper(NoABB* r) {
	if (r != nullptr) {
		printInordemHelper(r->esq);

		std::cout << std::left << std::setw(40) << r->key;
		std::cout << " | Ocorrências: " << std::left << std::setw(4) << r->value->numOcorrencias;
		std::cout << " | Letras: " << std::left << std::setw(2) << r->value->numLetras;
		std::cout << " | Vogais: " << std::left << std::setw(1) << r->value->numVogais << std::endl;

		printInordemHelper(r->dir);
	}
}