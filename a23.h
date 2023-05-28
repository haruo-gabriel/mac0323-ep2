#ifndef A23_H
#define A23_H

#include "lib.h"

class NoA23 {
public:
    std::string key1, key2;
    Item* value1; Item* value2;
    NoA23* esq; NoA23* mid; NoA23* dir;
    int nKeys;
    NoA23() {
        key1 = ""; key2 = "";
        value1 = value2 = nullptr;
        esq = mid = dir = nullptr;
        nKeys = 0;
    }
};

void printValue(NoA23* node, std::string key);
bool ehFolha(NoA23* r);

class A23 {
private:
    NoA23* addHelper(NoA23* raiz, std::string key, bool* cresceu);
    NoA23* valueHelper(NoA23* r, std::string key);
    // void printHelper(NoA23* node, std::string indent, bool isLast);
    void printInordemHelper(NoA23* r);

	std::vector<std::string> palavrasMaisFrequentesHelper(NoA23* r, int &maiorFreq, std::vector<std::string> maiores);
	std::vector<std::string> palavrasMaisLongasHelper(NoA23* r, int &maiorTam, std::vector<std::string> maiores);
	std::vector<std::string> maioresPalavrasSemRepeticaoLetrasHelper(NoA23* r, int &maiorTam, std::vector<std::string> maiores);
	std::vector<std::string> menoresPalavrasSemRepeticaoVogaisHelper(NoA23* r, int &menorTam, std::vector<std::string> menores);
public:
    NoA23* raiz;
    A23() { raiz = nullptr; }

    void separaPalavras(unsigned int n, A23& a23);

    void add(std::string key);
    NoA23* value(std::string key);
    void printA23();
    void printInordem();
 
	void palavrasMaisFrequentes();
	int frequenciaPalavra(std::string key);
	void palavrasMaisLongas();
	void maioresPalavrasSemRepeticaoLetras();
	void menoresPalavrasSemRepeticaoVogais();
};

#endif // A23_H