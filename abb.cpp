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

// Consultas
void ABB::palavrasMaisFrequentes() {
	int maiorFreq = 0;
	std::vector<NoABB*> maiores;
	maiores = palavrasMaisFrequentesHelper(raiz, maiorFreq, maiores);
	for (const auto& p : maiores) std::cout << p->key << " ";
	std::cout << std::endl;
}
std::vector<NoABB*> ABB::palavrasMaisFrequentesHelper(NoABB* r, int &maiorFreq, std::vector<NoABB*> maiores) {
	if (r == nullptr) return maiores;

	maiores = palavrasMaisFrequentesHelper(r->esq, maiorFreq, maiores);
	
	if (r->value->numOcorrencias > maiorFreq) {
		maiores.clear();
		maiores.push_back(r);
		maiorFreq = r->value->numOcorrencias;
	}
	else if (r->value->numOcorrencias == maiorFreq) {
		maiores.push_back(r);
	}

	maiores = palavrasMaisFrequentesHelper(r->dir, maiorFreq, maiores);

	return maiores;	
}

int ABB::frequenciaPalavra(std::string key) {
	Item* aux = value(key);
	if (aux == nullptr) return 0;
	else return aux->numOcorrencias;
}

void ABB::palavrasMaisLongas() {
	int maiorTam = 0;
	std::vector<NoABB*> maiores;
	maiores = palavrasMaisLongasHelper(raiz, maiorTam, maiores);
	for (const auto& p : maiores) std::cout << p->key << " ";
	std::cout << std::endl;
}
std::vector<NoABB*> ABB::palavrasMaisLongasHelper(NoABB* r, int &maiorTam, std::vector<NoABB*> maiores) {
	if (r == nullptr) return maiores;

	maiores = palavrasMaisLongasHelper(r->esq, maiorTam, maiores);

	if (r->value->numLetras > maiorTam) {
		maiores.clear();
		maiores.push_back(r);
		maiorTam = r->value->numLetras;
	}
	else if (r->value->numLetras == maiorTam) maiores.push_back(r);

	maiores = palavrasMaisLongasHelper(r->dir, maiorTam, maiores);

	return maiores;	
}

void ABB::maioresPalavrasSemRepeticaoLetras() {
	int maiorTam = 0;
	std::vector<NoABB*> maiores;
	maiores = maioresPalavrasSemRepeticaoLetrasHelper(raiz, maiorTam, maiores);
	for (const auto& p : maiores) std::cout << p->key << " ";
	std::cout << std::endl;
}

std::vector<NoABB*> ABB::maioresPalavrasSemRepeticaoLetrasHelper(NoABB* r, int &maiorTam, std::vector<NoABB*> maiores) {
	if (r == nullptr) return maiores;

	maiores = maioresPalavrasSemRepeticaoLetrasHelper(r->esq, maiorTam, maiores);

	if (r->value->numLetras >= maiorTam && !repeteLetras(r->key)) {
		if (r->value->numLetras > maiorTam) {
			maiores.clear();
			maiorTam = r->value->numLetras;
		}
		maiores.push_back(r);
	}

	maiores = maioresPalavrasSemRepeticaoLetrasHelper(r->dir, maiorTam, maiores);

	return maiores;	
}

void ABB::menoresPalavrasSemRepeticaoVogais() {
	int maiorTam = 100;
	std::vector<NoABB*> menores;
	menores = menoresPalavrasSemRepeticaoVogaisHelper(raiz, maiorTam, menores);
	for (const auto& p : menores) std::cout << p->key << " ";
	std::cout << std::endl;
}

std::vector<NoABB*> ABB::menoresPalavrasSemRepeticaoVogaisHelper(NoABB* r, int &menorTam, std::vector<NoABB*> menores) {
	if (r == nullptr) return menores;

	menores = menoresPalavrasSemRepeticaoVogaisHelper(r->esq, menorTam, menores);

	if (r->value->numLetras <= menorTam && !repeteVogais(r->key)) {
		if (r->value->numLetras < menorTam) {
			menores.clear();
			menorTam = r->value->numLetras;
		}
		menores.push_back(r);
	}

	menores = menoresPalavrasSemRepeticaoVogaisHelper(r->dir, menorTam, menores);

	return menores;	
}