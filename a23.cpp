#include "a23.h"

void printValue(NoA23* node, std::string key) {
	if (node == nullptr) {
		std::cout << "Key not found." << std::endl;
		return;
	}
	if (node->nKeys == 1) { // é 2no
		std::cout << "Key: " << node->key1 << std::endl;
		std::cout << "Value: " << node->value1->numOcorrencias << " ocorrências, ";
		std::cout << node->value1->numLetras << " letras, ";
		std::cout << node->value1->numVogais << " vogais únicas." << std::endl;
	}
	else { // é 3no
		if (key == node->key1) {
			std::cout << "Key: " << node->key1 << std::endl;
			std::cout << "Value: " << node->value1->numOcorrencias << " ocorrências, ";
			std::cout << node->value1->numLetras << " letras, ";
			std::cout << node->value1->numVogais << " vogais únicas." << std::endl;
		}
		else {
			std::cout << "Key: " << node->key2 << std::endl;
			std::cout << "Value: " << node->value2->numOcorrencias << " ocorrências, ";
			std::cout << node->value2->numLetras << " letras, ";
			std::cout << node->value2->numVogais << " vogais únicas." << std::endl;
		}
	}
}

bool ehFolha(NoA23* r) {
	return (r->nKeys >= 1 && r->esq == nullptr && r->mid == nullptr && r->dir == nullptr);
}

void A23::add(std::string key) {
	bool* cresceu = new bool(false);
	this->raiz = addHelper(this->raiz, key, cresceu);
	delete cresceu;
	return;
}
NoA23* A23::addHelper(NoA23* r, std::string key, bool* cresceu) {
	if (r == nullptr) {
		r = new NoA23(); r->key1 = key; r->nKeys = 1;
		r->value1 = new Item(key);
		*cresceu = true;
		return r;
	}
	if (ehFolha(r)) { // é folha
		if (r->nKeys == 1) { // é 2no - aqui, há apenas a key1
			if (key == r->key1) { // se key já está na árvore
				r->value1->numOcorrencias++;
				*cresceu = false;
				return r;
			}
			else if (key < r->key1) { // key é menor que a key1 da raiz
				r->key2 = r->key1; r->key1 = key;
				r->value2 = r->value1; r->value1 = new Item(key);
				r->nKeys = 2;
				*cresceu = false;
				return r;
			}
			else { // key é maior que a key1 da raiz
				r->key2 = key; r->value2 = new Item(key);
				r->nKeys = 2;
				*cresceu = false;
				return r;
			}
		} 
		else { // é 3no - aqui, há key1 e key2
			// se key já está na árvore
			if (key == r->key1) {
				r->value1->numOcorrencias++;
				*cresceu = false;
				return r;
			}
			else if (key == r->key2) {
				r->value2->numOcorrencias++;
				*cresceu = false;
				return r;
			} 
			// se key não está na árvore
			else if (key < r->key1) { // se key é menor que key1 da raiz
				// split
				NoA23* menor = new NoA23(); 
				menor->key1 = key; menor->value1 = new Item(key);
				menor->nKeys = 1;
				NoA23* maior = new NoA23();
				maior->key1 = r->key2; maior->value1 = r->value2;
				maior->nKeys = 1;

				// atualiza raiz
				r->key2 = ""; r->value2 = nullptr;
				r->nKeys = 1;
				r->esq = menor; r->mid = maior; r->dir = nullptr;
				*cresceu = true;
				return r;
			}
			else if (key > r->key1 && key < r->key2) { // se key está entre key1 e key2
				// split
				NoA23* menor = new NoA23();
				menor->key1 = r->key1; menor->value1 = r->value1;
				menor->nKeys = 1;
				NoA23* maior = new NoA23();
				maior->key1 = r->key2; maior->value1 = r->value2;
				maior->nKeys = 1;

				// atualiza raiz
				r->key1 = key; r->value1 = new Item(key);
				r->key2 = ""; r->value2 = nullptr;
				r->nKeys = 1;
				r->esq = menor; r->mid = maior; r->dir = nullptr;
				*cresceu = true;
				return r;
			}
			else { // se key é maior que key2
				// split
				NoA23* menor = new NoA23();
				menor->key1 = r->key1; menor->value1 = r->value1;
				menor->nKeys = 1;
				NoA23* maior = new NoA23();
				maior->key1 = key; maior->value1 = new Item(key);
				maior->nKeys = 1;

				// atualiza raiz
				r->key1 = r->key2; r->value1 = r->value2;
				r->key2 = ""; r->value2 = nullptr;	
				r->nKeys = 1;
				r->esq = menor; r->mid = maior; r->dir = nullptr;
				*cresceu = true;
				return r;
			}
		}
	}
	else { // não é folha
		if (key == r->key1) {
			r->value1->numOcorrencias++;
			*cresceu = false;
			return r;
		}
		else if (key < r->key1) { // key é menor que a key1 de r
			NoA23* aux = addHelper(r->esq, key, cresceu); // chama addHelper recursivo para a subarvore esquerda
			if (! *cresceu) {
				r->esq = aux;
				return r;
			}
			else {
				if (r->nKeys == 1) { // é 2no
					r->dir = r->mid;
					r->key2 = r->key1; r->key1 = aux->key1;
					r->value2 = r->value1; r->value1 = aux->value1;
					r->esq = aux->esq; r->mid = aux->mid;
					r->nKeys = 2;
					aux = nullptr;
					*cresceu = false;
					return r;
				}
				else { // é 3no
					// merge
					NoA23* menor = new NoA23();
					menor->key1 = aux->key1; menor->value1 = aux->value1;
					menor->nKeys = 1;
					menor->esq = aux->esq; menor->mid = aux->mid;
					NoA23* maior = new NoA23();
					maior->key1 = r->key2; maior->value1 = r->value2;
					maior->nKeys = 1;
					maior->esq = r->mid; maior->mid = r->dir;

					// atualiza raiz
					r->key2 = ""; r->value2 = nullptr; r->nKeys = 1;
					r->esq = menor; r->mid = maior; r->dir = nullptr;
					*cresceu = true;
					return r;
				}
			}
		}
		else { // key é maior que a key1 de r
			if (r->nKeys == 1) { // é 2no
				NoA23* aux = addHelper(r->mid, key, cresceu); // chama addHelper recursivo para a subarvore do meio
				if (! *cresceu) {
					r->mid = aux;
					return r;
				}
				else {
					r->key2 = aux->key1; r->value2 = aux->value1;
					r->nKeys = 2;
					r->mid = aux->esq; r->dir = aux->mid;
					// delete aux;
					aux = nullptr;
					*cresceu = false;
					return r; 
				}
			}
			else { // é 3no
				if (key == r->key2) {
					r->value2->numOcorrencias++;
					*cresceu = false;
					return r;
				}
				else if (key > r->key2) { // se key é maior que a maior key de r
					NoA23* aux = addHelper(r->dir, key, cresceu); // chama addHelper recursivo para a subarvore direita
					if (! *cresceu) {
						r->dir = aux;
						return r;
					}
					else {
						// split
						NoA23* menor = new NoA23();
						menor->key1 = r->key1; menor->value1 = r->value1;
						menor->nKeys = 1;
						menor->esq = r->esq; menor->mid = r->mid; menor->dir = nullptr;
						NoA23* maior = new NoA23();
						// maior->key1 = r->key2; maior->value1 = r->value2; maior->nKeys = 1;
						maior->key1 = aux->key1; maior->value1 = aux->value1;
						maior->nKeys = 1;
						maior->esq = aux->esq; maior->mid = aux->mid; maior->dir = nullptr;

						// atualiza raiz
						r->key1 = r->key2; r->value1 = r->value2;
						r->key2 = ""; r->value2 = nullptr;
						r->nKeys = 1;
						r->esq = menor; r->mid = maior; r->dir = nullptr;
						*cresceu = true;
						return r;
					}
				}
				else { // se key está entre as duas keys de r
					NoA23* aux = addHelper(r->mid, key, cresceu); // chama addHelper recursivo para a subarvore do meio
					if (! *cresceu){
						r->mid = aux;
						return r;
					}
					else {
						// merge
						NoA23* menor = new NoA23();
						menor->key1 = r->key1; menor->value1 = r->value1;
						menor->nKeys = 1;
						menor->esq = r->esq; menor->mid = aux->esq; menor->dir = nullptr;
						NoA23* maior = new NoA23();
						maior->key1 = r->key2; maior->value1 = r->value2;
						maior->nKeys = 1;
						maior->esq = aux->mid; maior->mid = r->dir; maior->dir = nullptr;

						// atualiza raiz
						r->key1 = aux->key1; r->value1 = aux->value1;
						r->key2 = ""; r->value2 = nullptr;
						r->nKeys = 1;
						r->esq = menor; r->mid = maior; r->dir = nullptr;
						*cresceu = true;
						return r;
					}
				}
			}
		}
	} 
}


NoA23* A23::value(std::string key) {
	return valueHelper(raiz, key);
}
NoA23* A23::valueHelper(NoA23* r, std::string key) {
	if (r == nullptr) {
		return nullptr;
	}
	else {
		if (r->nKeys == 1) { // é 2no
			if (r->key1 == key) return r;
			else if (key < r->key1) return valueHelper(r->esq, key);
			else return valueHelper(r->mid, key);
		}
		else { // é 3no
			if (r->key1 == key || r->key2 == key) return r;
			else if (key < r->key1) return valueHelper(r->esq, key);
			else if (key > r->key1 && key < r->key2) return valueHelper(r->mid, key);
			else return valueHelper(r->dir, key);
		}
	}
}

#include <queue>
void A23::printA23() {
	if (raiz == nullptr) {
			std::cout << "2-3 Tree is empty." << std::endl;
			return;
	}

	std::cout << "2-3 Tree:" << std::endl;

	std::queue<NoA23*> nodeQueue;
	nodeQueue.push(raiz);

	while (!nodeQueue.empty()) {
		int levelSize = nodeQueue.size();

		for (int i = 0; i < levelSize; i++) {
			NoA23* node = nodeQueue.front();
			nodeQueue.pop();

			if (node->nKeys == 1) {
				std::cout << node->key1 << " ";
			} else if (node->nKeys == 2) {
				std::cout << node->key1 << "-" << node->key2 << " ";
			}

			if (node->esq != nullptr) {
				nodeQueue.push(node->esq);
			}
			if (node->mid != nullptr) {
				nodeQueue.push(node->mid);
			}
			if (node->dir != nullptr) {
				nodeQueue.push(node->dir);
			}
		}

		std::cout << std::endl;
	}
}

void A23::printInordem() { printInordemHelper(this->raiz); }
void A23::printInordemHelper(NoA23* r) {
	if (r == nullptr) return;
	else {
		printInordemHelper(r->esq);

		std::cout << std::left << std::setw(40) << r->key1;
		std::cout << " | Ocorrências: " << std::left << std::setw(4) << r->value1->numOcorrencias;
		std::cout << " | Letras: " << std::left << std::setw(2) << r->value1->numLetras;
		std::cout << " | Vogais: " << std::left << std::setw(1) << r->value1->numVogais << std::endl;

		printInordemHelper(r->mid);

		if (r->nKeys == 2) {
			std::cout << std::left << std::setw(40) << r->key2;
			std::cout << " | Ocorrências: " << std::left << std::setw(4) << r->value2->numOcorrencias;
			std::cout << " | Letras: " << std::left << std::setw(2) << r->value2->numLetras;
			std::cout << " | Vogais: " << std::left << std::setw(1) << r->value2->numVogais << std::endl;

			printInordemHelper(r->dir);
		}
	}
}

// Consultas
void A23::palavrasMaisFrequentes() {
	int maiorFreq = 0;
	std::vector<std::string> maiores;
	maiores = palavrasMaisFrequentesHelper(raiz, maiorFreq, maiores);
	for (const auto& p : maiores) std::cout << p << " ";
	std::cout << std::endl;
}
std::vector<std::string> A23::palavrasMaisFrequentesHelper(NoA23* r, int &maiorFreq, std::vector<std::string> maiores) {
	if (r == nullptr) return maiores;
	else {
		maiores = palavrasMaisFrequentesHelper(r->esq, maiorFreq, maiores);

		if (r->value1->numOcorrencias >= maiorFreq) {
			if (r->value1->numOcorrencias > maiorFreq) {
				maiores.clear();
				maiorFreq = r->value1->numOcorrencias;
			}
			maiores.push_back(r->key1);
		}

		maiores = palavrasMaisFrequentesHelper(r->mid, maiorFreq, maiores);

		if (r->nKeys == 2) {
			if (r->value2->numOcorrencias >= maiorFreq) {
				if (r->value2->numOcorrencias > maiorFreq) {
					maiores.clear();
					maiorFreq = r->value2->numOcorrencias;
				}
				maiores.push_back(r->key2);
			}

			maiores = palavrasMaisFrequentesHelper(r->dir, maiorFreq, maiores);
		}
	}
	return maiores;
}

int A23::frequenciaPalavra(std::string key) {
	NoA23* aux = value(key);
	if (aux == nullptr) return 0;
	else if (aux->key1 == key) return aux->value1->numOcorrencias;
	else return aux->value2->numOcorrencias;
}

void A23::palavrasMaisLongas() {
	int maiorTam = 0;
	std::vector<std::string> maiores;
	maiores = palavrasMaisLongasHelper(raiz, maiorTam, maiores);
	for (const auto& p : maiores) std::cout << p << " ";
	std::cout << std::endl;
}
std::vector<std::string> A23::palavrasMaisLongasHelper(NoA23* r, int &maiorTam, std::vector<std::string> maiores) {
	if (r == nullptr) return maiores;
	else {
		maiores = palavrasMaisLongasHelper(r->esq, maiorTam, maiores);

		if (r->value1->numLetras >= maiorTam) {
			if (r->value1->numLetras > maiorTam) {
				maiores.clear();
				maiorTam = r->value1->numLetras;
			}
			maiores.push_back(r->key1);
		}

		maiores = palavrasMaisLongasHelper(r->mid, maiorTam, maiores);

		if (r->nKeys == 2) {
			if (r->value2->numLetras >= maiorTam) {
				if (r->value2->numLetras > maiorTam) {
					maiores.clear();
					maiorTam = r->value2->numLetras;
				}
				maiores.push_back(r->key2);
			}

			maiores = palavrasMaisLongasHelper(r->dir, maiorTam, maiores);
		}
	}
	
	return maiores;	
}

void A23::maioresPalavrasSemRepeticaoLetras() {
	int maiorTam = 0;
	std::vector<std::string> maiores;
	maiores = maioresPalavrasSemRepeticaoLetrasHelper(this->raiz, maiorTam, maiores);
	for (const auto& p : maiores) std::cout << p << " ";
	std::cout << std::endl;
}
std::vector<std::string> A23::maioresPalavrasSemRepeticaoLetrasHelper(NoA23* r, int &maiorTam, std::vector<std::string> maiores) {
	if (r == nullptr) return maiores;
	else {
		maiores = maioresPalavrasSemRepeticaoLetrasHelper(r->esq, maiorTam, maiores);

		if (r->value1->numLetras >= maiorTam && !repeteLetras(r->key1)) {
			if (r->value1->numLetras > maiorTam) {
				maiores.clear();
				maiorTam = r->value1->numLetras;
			}
			maiores.push_back(r->key1);
		}

		maiores = maioresPalavrasSemRepeticaoLetrasHelper(r->mid, maiorTam, maiores);

		if (r->nKeys == 2) {
			if (r->value2->numLetras >= maiorTam && !repeteLetras(r->key2)) {
				if (r->value2->numLetras > maiorTam) {
					maiores.clear();
					maiorTam = r->value2->numLetras;
				}
				maiores.push_back(r->key2);
			}

			maiores = maioresPalavrasSemRepeticaoLetrasHelper(r->dir, maiorTam, maiores);
		}
	}
	
	return maiores;	
}


void A23::menoresPalavrasSemRepeticaoVogais() {
	int menorTam = 100;
	std::vector<std::string> menores;
	menores = menoresPalavrasSemRepeticaoVogaisHelper(raiz, menorTam, menores);
	for (const auto& p : menores) std::cout << p << " ";
	std::cout << std::endl;
}
std::vector<std::string> A23::menoresPalavrasSemRepeticaoVogaisHelper(NoA23* r, int &menorTam, std::vector<std::string> menores) {
	if (r == nullptr) return menores;
	else {
		menores = menoresPalavrasSemRepeticaoVogaisHelper(r->esq, menorTam, menores);

		if (r->value1->numLetras <= menorTam && !repeteVogais(r->key1)) {
			if (r->value1->numLetras < menorTam) {
				menores.clear();
				menorTam = r->value1->numLetras;
			}
			menores.push_back(r->key1);
		}

		menores = menoresPalavrasSemRepeticaoVogaisHelper(r->mid, menorTam, menores);

		if (r->nKeys == 2) {
			if (r->value2->numLetras <= menorTam && !repeteVogais(r->key2)) {
				if (r->value2->numLetras < menorTam) {
					menores.clear();
					menorTam = r->value2->numLetras;
				}
				menores.push_back(r->key2);
			}

			menores = menoresPalavrasSemRepeticaoVogaisHelper(r->dir, menorTam, menores);
		}
	}
	
	return menores;	
}