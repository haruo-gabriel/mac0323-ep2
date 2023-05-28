#include "arn.h"

void ARN::separaPalavras(unsigned int n, ARN& arn) {
	std::string input;
	unsigned int wordCount = 0;

	while (std::cin >> input && wordCount < n) {
		std::istringstream iss(input);
		std::string palavra;
		while (iss >> palavra) {
			std::string palavraFiltrada;

			auto it_beginWord = palavra.begin();
			while (it_beginWord != palavra.end() && !std::isalpha(*it_beginWord)){
				it_beginWord++;
				continue;
			}
			auto it_endWord = palavra.end();
			while (it_endWord != it_beginWord && !std::isalpha(*it_endWord)) {
				it_endWord--;
				continue;
			}

			if (it_beginWord == it_endWord) wordCount++;
			else {
				palavraFiltrada = std::string(it_beginWord, it_endWord+1);
				if (!palavraFiltrada.empty()) {
					arn.add(palavraFiltrada);
					wordCount++;
				}
			}
			
			if (wordCount >= n) break;
		}

		if (wordCount >= n) break;
	}
}

NoARN* ARN::value(std::string k) {
  return valueHelper(this->raiz, k);
}
NoARN* ARN::valueHelper(NoARN* node, std::string key) {
  if (node == TNULL || key == node->key) return node;
  if (key < node->key) return valueHelper(node->esq, key);
  return valueHelper(node->dir, key);
}

void ARN::add(std::string key) {
		NoARN* y = nullptr;
		NoARN* x = this->raiz;
		while (x != TNULL) {
      y = x;
      if (key < x->key)
        x = x->esq;
      else if (key > x->key)
        x = x->dir;
      else {
        x->numOcorrencias++;
        return;
      }
		}
		NoARN* node = new NoARN(key, true, nullptr, TNULL, TNULL);
		node->pai = y;
		if (y == nullptr) raiz = node;
    else if (node->key < y->key) y->esq = node;
		else y->dir = node;
		if (node->pai == nullptr){
      node->cor = 0;
      return;
		}
		if (node->pai->pai == nullptr) return;
		arruma(node);
}
void ARN::arruma(NoARN* k){
  NoARN* u;
  while (k->pai->cor == 1) {
    if (k->pai == k->pai->pai->dir) {
      u = k->pai->pai->esq;
      if (u->cor == 1) {
        u->cor = 0;
        k->pai->cor = 0;
        k->pai->pai->cor = 1;
        k = k->pai->pai;
      }
      else {
        if (k == k->pai->esq) {
          k = k->pai;
          rotacionaDir(k);
        }
        k->pai->cor = 0;
        k->pai->pai->cor = 1;
        rotacionaEsq(k->pai->pai);
      }
    }
    else {
      u = k->pai->pai->dir;

      if (u->cor == 1) {
        u->cor = 0;
        k->pai->cor = 0;
        k->pai->pai->cor = 1;
        k = k->pai->pai;	
      }
      else {
        if (k == k->pai->dir) {
          k = k->pai;
          rotacionaEsq(k);
        }
        k->pai->cor = 0;
        k->pai->pai->cor = 1;
        rotacionaDir(k->pai->pai);
      }
    }
    if (k == raiz) break;
  }
  raiz->cor = 0;
}

// rotaciona em x para esquerda
void ARN::rotacionaEsq(NoARN* x) {
  NoARN* y = x->dir;
  x->dir = y->esq;
  if (y->esq != TNULL) y->esq->pai = x;
  y->pai = x->pai;
  if (x->pai == nullptr) this->raiz = y;
  else if (x == x->pai->esq) x->pai->esq = y;
  else x->pai->dir = y;
  y->esq = x;
  x->pai = y;
}

// rotaciona em x para direita
void ARN::rotacionaDir(NoARN* x) {
  NoARN* y = x->esq;
  x->esq = y->dir;
  if (y->dir != TNULL) y->dir->pai = x;
  y->pai = x->pai;
  if (x->pai == nullptr)  this->raiz = y;
  else if (x == x->pai->dir) x->pai->dir = y;
  else x->pai->esq = y;
  y->dir = x;
  x->pai = y;
}

void ARN::printARN() { if (raiz) printHelper(this->raiz, "", true); }
void ARN::printHelper(NoARN* raiz, std::string indent, bool last) {
  if (raiz != TNULL) {
    std::cout<<indent;
    if (last) {
      std::cout<<"R----";
      indent += "     ";
    } else {
      std::cout<<"L----";
      indent += "|    ";
    }
    
    std::string sColor = raiz->cor?"RED":"BLACK";
    std::cout<<raiz->key<<"("<<sColor<<")"<<std::endl;
    printHelper(raiz->esq, indent, false);
    printHelper(raiz->dir, indent, true);
  }
  // cout<<raiz->esq->key<<endl;
}

void ARN::printInordem() { printInordemHelper(this->raiz); }
void ARN::printInordemHelper(NoARN* r) {
	if (r != TNULL) {
		printInordemHelper(r->esq);

		std::cout << std::left << std::setw(40) << r->key;
		std::cout << " | Ocorrências: " << std::left << std::setw(4) << r->numOcorrencias;
		std::cout << " | Letras: " << std::left << std::setw(2) << r->numLetras;
		std::cout << " | Vogais: " << std::left << std::setw(1) << r->numVogaisUnicas << std::endl;

		printInordemHelper(r->dir);
	}
}


// Consultas
void ARN::palavrasMaisFrequentes() {
	int maiorFreq = 0;
	std::vector<NoARN*> maiores;
	maiores = palavrasMaisFrequentesHelper(raiz, maiorFreq, maiores);
	for (const auto& p : maiores) std::cout << p->key << " ";
	std::cout << std::endl;
}
std::vector<NoARN*> ARN::palavrasMaisFrequentesHelper(NoARN* r, int &maiorFreq, std::vector<NoARN*> maiores) {
	if (r == TNULL ) return maiores;

	maiores = palavrasMaisFrequentesHelper(r->esq, maiorFreq, maiores);
	
	if (r->numOcorrencias > maiorFreq) {
		maiores.clear();
		maiores.push_back(r);
		maiorFreq = r->numOcorrencias;
	}
	else if (r->numOcorrencias == maiorFreq) {
		maiores.push_back(r);
	}

	maiores = palavrasMaisFrequentesHelper(r->dir, maiorFreq, maiores);

	return maiores;	
}

int ARN::frequenciaPalavra(std::string key) {
	NoARN* aux = value(key);
	if (aux == TNULL) return 0;
	else return aux->numOcorrencias;
}

void ARN::palavrasMaisLongas() {
	int maiorTam = 0;
	std::vector<NoARN*> maiores;
	maiores = palavrasMaisLongasHelper(raiz, maiorTam, maiores);
	for (const auto& p : maiores) std::cout << p->key << " ";
	std::cout << std::endl;
}
std::vector<NoARN*> ARN::palavrasMaisLongasHelper(NoARN* r, int &maiorTam, std::vector<NoARN*> maiores) {
	if (r == TNULL) return maiores;

	maiores = palavrasMaisLongasHelper(r->esq, maiorTam, maiores);

	if (r->numLetras > maiorTam) {
		maiores.clear();
		maiores.push_back(r);
		maiorTam = r->numLetras;
	}
	else if (r->numLetras == maiorTam) maiores.push_back(r);

	maiores = palavrasMaisLongasHelper(r->dir, maiorTam, maiores);

	return maiores;	
}

void ARN::maioresPalavrasSemRepeticaoLetras() {
	int maiorTam = 0;
	std::vector<NoARN*> maiores;
	maiores = maioresPalavrasSemRepeticaoLetrasHelper(raiz, maiorTam, maiores);
	for (const auto& p : maiores) std::cout << p->key << " ";
	std::cout << std::endl;
}

std::vector<NoARN*> ARN::maioresPalavrasSemRepeticaoLetrasHelper(NoARN* r, int &maiorTam, std::vector<NoARN*> maiores) {
	if (r == TNULL) return maiores;

	maiores = maioresPalavrasSemRepeticaoLetrasHelper(r->esq, maiorTam, maiores);

	if (r->numLetras >= maiorTam && !repeteLetras(r->key)) {
		if (r->numLetras > maiorTam) {
			maiores.clear();
			maiorTam = r->numLetras;
		}
		maiores.push_back(r);
	}

	maiores = maioresPalavrasSemRepeticaoLetrasHelper(r->dir, maiorTam, maiores);

	return maiores;	
}

void ARN::menoresPalavrasSemRepeticaoVogais() {
	int maiorTam = 100;
	std::vector<NoARN*> menores;
	menores = menoresPalavrasSemRepeticaoVogaisHelper(raiz, maiorTam, menores);
	for (const auto& p : menores) std::cout << p->key << " ";
	std::cout << std::endl;
}

std::vector<NoARN*> ARN::menoresPalavrasSemRepeticaoVogaisHelper(NoARN* r, int &menorTam, std::vector<NoARN*> menores) {
	if (r == TNULL) return menores;

	menores = menoresPalavrasSemRepeticaoVogaisHelper(r->esq, menorTam, menores);

	if (r->numLetras <= menorTam && !repeteVogais(r->key)) {
		if (r->numLetras < menorTam) {
			menores.clear();
			menorTam = r->numLetras;
		}
		menores.push_back(r);
	}

	menores = menoresPalavrasSemRepeticaoVogaisHelper(r->dir, menorTam, menores);

	return menores;	
}