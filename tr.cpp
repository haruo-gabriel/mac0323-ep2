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

void TR::printInordem() {
	printInordemHelper(this->raiz);
}

void TR::printInordemHelper(NoTR* r) {
	if (r != nullptr) {
		printInordemHelper(r->esq);

		std::cout << std::left << std::setw(40) << r->key;
		std::cout << " | Ocorrências: " << std::left << std::setw(4) << r->value->numOcorrencias;
		std::cout << " | Letras: " << std::left << std::setw(2) << r->value->numLetras;
		std::cout << " | Vogais: " << std::left << std::setw(1) << r->value->numVogais << std::endl;

		printInordemHelper(r->dir);
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


// Consultas
void TR::palavrasMaisFrequentes() {
	int maiorFreq = 0;
	std::vector<NoTR*> maiores;
	maiores = palavrasMaisFrequentesHelper(raiz, maiorFreq, maiores);
	for (const auto& p : maiores) std::cout << p->key << " ";
	std::cout << std::endl;
}
std::vector<NoTR*> TR::palavrasMaisFrequentesHelper(NoTR* r, int &maiorFreq, std::vector<NoTR*> maiores) {
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

int TR::frequenciaPalavra(std::string key) {
	Item* aux = value(key);
	if (aux == nullptr) return 0;
	else return aux->numOcorrencias;
}

void TR::palavrasMaisLongas() {
	int maiorTam = 0;
	std::vector<NoTR*> maiores;
	maiores = palavrasMaisLongasHelper(raiz, maiorTam, maiores);
	for (const auto& p : maiores) std::cout << p->key << " ";
	std::cout << std::endl;
}
std::vector<NoTR*> TR::palavrasMaisLongasHelper(NoTR* r, int &maiorTam, std::vector<NoTR*> maiores) {
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

void TR::maioresPalavrasSemRepeticaoLetras() {
	int maiorTam = 0;
	std::vector<NoTR*> maiores;
	maiores = maioresPalavrasSemRepeticaoLetrasHelper(raiz, maiorTam, maiores);
	for (const auto& p : maiores) std::cout << p->key << " ";
	std::cout << std::endl;
}

std::vector<NoTR*> TR::maioresPalavrasSemRepeticaoLetrasHelper(NoTR* r, int &maiorTam, std::vector<NoTR*> maiores) {
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

void TR::menoresPalavrasSemRepeticaoVogais() {
	int maiorTam = 100;
	std::vector<NoTR*> menores;
	menores = menoresPalavrasSemRepeticaoVogaisHelper(raiz, maiorTam, menores);
	for (const auto& p : menores) std::cout << p->key << " ";
	std::cout << std::endl;
}

std::vector<NoTR*> TR::menoresPalavrasSemRepeticaoVogaisHelper(NoTR* r, int &menorTam, std::vector<NoTR*> menores) {
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