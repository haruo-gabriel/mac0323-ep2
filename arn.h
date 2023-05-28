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
	void printInordemHelper(NoARN* r);

	// initializes the nodes with appropriate values
	// all the pointers are set to point to the null pointer
	void initializeNULLNode(NoARN* node, NoARN* pai) {
		node->key = "";
		node->pai = pai;
		node->esq = nullptr;
		node->dir = nullptr;
		node->cor = 0;
	}

	std::vector<NoARN*> palavrasMaisFrequentesHelper(NoARN* r, int &maiorFreq, std::vector<NoARN*> maiores);
	std::vector<NoARN*> palavrasMaisLongasHelper(NoARN* r, int &maiorTam, std::vector<NoARN*> maiores);
	std::vector<NoARN*> maioresPalavrasSemRepeticaoLetrasHelper(NoARN* r, int &maiorTam, std::vector<NoARN*> maiores);
	std::vector<NoARN*> menoresPalavrasSemRepeticaoVogaisHelper(NoARN* r, int &menorTam, std::vector<NoARN*> menores);

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
	void printARN();
	void printInordem();
	void printValue(NoARN* node) {
		std::cout << "Key: " << node->key << std::endl;
		std::cout << "Ocorrências: " << node->numOcorrencias << std::endl;
		std::cout << "Número de letras: " << node->numLetras << std::endl;
		std::cout << "Número de vogais não-repetidas: " << node->numVogaisUnicas << std::endl;
	}
	
	// Consultas
	void palavrasMaisFrequentes();
	int frequenciaPalavra(std::string key);
	void palavrasMaisLongas();
	void maioresPalavrasSemRepeticaoLetras();
	void menoresPalavrasSemRepeticaoVogais();

};