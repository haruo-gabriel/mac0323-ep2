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
			} else if (key == r->key2) {
				r->value2->numOcorrencias++;
				*cresceu = false;
				return r;

			// se key não está na árvore
			} else if (key < r->key1) { // se key é menor que key1 da raiz
				// split
				NoA23* menor = new NoA23(); 
				menor->key1 = key; menor->value1 = new Item(key); menor->nKeys = 1;
				NoA23* maior = new NoA23();
				maior->key1 = r->key2; maior->value1 = r->value2; maior->nKeys = 1;

				// atualiza raiz
				r->key2 = ""; r->value2 = nullptr; r->nKeys = 1;
				r->esq = menor; r->mid = maior; r->dir = nullptr;
				*cresceu = true;
				return r;
			} else if (key > r->key1 && key < r->key2) { // se key está entre key1 e key2
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
				menor->key1 = r->key1; menor->value1 = r->value1; menor->nKeys = 1;
				NoA23* maior = new NoA23();
				maior->key1 = key; maior->value1 = new Item(key); maior->nKeys = 1;

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
		if (key < r->key1) { // key é menor que a menor key de r
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
					menor->key1 = aux->key1; menor->value1 = aux->value1; menor->nKeys = 1;
					NoA23* maior = new NoA23();
					maior->key1 = r->key2; maior->value1 = r->value2; maior->nKeys = 1;

					// atualiza raiz
					r->key2 = ""; r->value2 = nullptr; r->nKeys = 1;
					r->esq = menor; r->mid = maior; r->dir = nullptr;
					*cresceu = true;
					return r;
				}
			}
		}
		else { // key é maior que a menor key de r
			if (r->nKeys == 1) { // é 2no
				NoA23* aux = addHelper(r->mid, key, cresceu); // chama addHelper recursivo para a subarvore do meio
				if (! *cresceu) {
					r->mid = aux;
					return r;
				} else {
					r->key2 = aux->key1; r->value2 = aux->value1;
					r->mid = aux->esq; r->dir = aux->mid;
					r->nKeys = 2;
					// delete aux;
					aux = nullptr;
					*cresceu = false;
					return r; 
				}
			}
			else { // é 3no
				if (key > r->key2) { // se key é maior que a maior key de r
					NoA23* aux = addHelper(r->dir, key, cresceu); // chama addHelper recursivo para a subarvore direita
					if (! *cresceu) {
						r->dir = aux;
						return r;
					}
					else {
						// split
						NoA23* menor = new NoA23();
						menor->key1 = r->key1; menor->value1 = r->value1; menor->nKeys = 1;
						menor->esq = r->esq; menor->mid = r->mid; menor->dir = nullptr;
						NoA23* maior = new NoA23();
						// maior->key1 = r->key2; maior->value1 = r->value2; maior->nKeys = 1;
						maior->key1 = aux->key1; maior->value1 = aux->value1; maior->nKeys = 1;
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
				else { // se key é maior que a menor key de r e menor que a maior key de r
					NoA23* aux = addHelper(r->mid, key, cresceu); // chama addHelper recursivo para a subarvore do meio
					if (! *cresceu) {
						r->mid = aux;
						return r;
					} else {
						// split
						NoA23* menor = new NoA23();
						menor->key1 = r->key1; menor->value1 = r->value1; menor->nKeys = 1;
						NoA23* maior = new NoA23();
						maior->key1 = r->key2; maior->value1 = r->value2; maior->nKeys = 1;

						// atualiza raiz
						r->key1 = aux->key1; r->value1 = aux->value1; r->nKeys = 1;
						r->esq = menor; r->mid = maior; r->dir = nullptr;
						*cresceu = true;
						return r;
					}
				}
			}
		}
	} 
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

NoA23* A23::value(std::string key) {
	return valueHelper(raiz, key);
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
