#include "lib.h"

class NoTR {
public:
	NoTR* esq; NoTR* dir; NoTR* pai;
	int prioridade;
    std::string key;
    Item* value;

    NoTR(std::string key) {
        this->esq = this->dir = this->pai = nullptr;
        this->prioridade = rand()%MAXKEYS;
        this->key = key;
        this->value = new Item(key);
    }
};

class TR {
private:
    NoTR* raiz;
    void rotacionaEsquerda(NoTR* &r);
    void rotacionaDireita(NoTR* &r);
    NoTR* novoNoTR(std::string key);
    void addHelper(NoTR* &r, std::string key);
    void printHelper(NoTR* r, std::string indent, bool last);
    void printInordemHelper(NoTR* r);

	std::vector<NoTR*> palavrasMaisFrequentesHelper(NoTR* r, int &maiorFreq, std::vector<NoTR*> maiores);
	std::vector<NoTR*> palavrasMaisLongasHelper(NoTR* r, int &maiorTam, std::vector<NoTR*> maiores);
	std::vector<NoTR*> maioresPalavrasSemRepeticaoLetrasHelper(NoTR* r, int &maiorTam, std::vector<NoTR*> maiores);
	std::vector<NoTR*> menoresPalavrasSemRepeticaoVogaisHelper(NoTR* r, int &menorTam, std::vector<NoTR*> menores);
public:
    TR() { raiz = nullptr; };

    void separaPalavras(unsigned int n, TR& tr);

    void add(std::string key);
    Item* value(std::string key);
    void inordem(NoTR* raiz);
    void printTR();
    void printInordem();
    void printValue(Item* r);

    void palavrasMaisFrequentes();    
	int frequenciaPalavra(std::string key);
	void palavrasMaisLongas();
	void maioresPalavrasSemRepeticaoLetras();
	void menoresPalavrasSemRepeticaoVogais();
};