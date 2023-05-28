#ifndef ABB_H
#define ABB_H

#include "lib.h"

class NoABB {
public:
	std::string key;
	Item* value;
	NoABB* esq;
	NoABB* dir;

	NoABB(std::string key) {
		this->key = key;
		this->value = new Item(key);
		this->esq = nullptr;
		this->dir = nullptr;
	}
};

class ABB {
private:
	NoABB* raiz;
	void printInordemHelper(NoABB* r);
	void printHelper(NoABB* r, std::string indent, bool last);
	std::vector<NoABB*> palavrasMaisFrequentesHelper(NoABB* r, int &maiorFreq, std::vector<NoABB*> maiores);
	std::vector<NoABB*> palavrasMaisLongasHelper(NoABB* r, int &maiorTam, std::vector<NoABB*> maiores);
	std::vector<NoABB*> maioresPalavrasSemRepeticaoLetrasHelper(NoABB* r, int &maiorTam, std::vector<NoABB*> maiores);
	std::vector<NoABB*> menoresPalavrasSemRepeticaoVogaisHelper(NoABB* r, int &menorTam, std::vector<NoABB*> menores);
public:
	ABB() {
		raiz = nullptr;
	};
	void separaPalavras(unsigned int n, ABB& abb);

	Item* value(std::string key);
	void add(std::string key);
	void printABB();
	void printInordem();

	void palavrasMaisFrequentes();
	int frequenciaPalavra(std::string key);
	void palavrasMaisLongas();
	void maioresPalavrasSemRepeticaoLetras();
	void menoresPalavrasSemRepeticaoVogais();
};

#endif // ABB_H