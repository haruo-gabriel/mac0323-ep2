#include "vo.h"

// usando busca binária
int VO::search(std::string key) {
    int esq = 0, meio, dir = vo.size()-1;
    while (esq <= dir){
        meio = esq + (dir - esq) / 2;
        if (key == vo[meio]->key){
            return meio;
        } else if (key < vo[meio]->key){
            dir = meio - 1;
        } else {
            esq = meio + 1;
        }
    }
    return esq;
}

Palavra* VO::value(std::string key) {
    int lugarCerto = VO::search(key);
    if (vo[lugarCerto]->key == key)
        return vo[lugarCerto];
    return nullptr;
}

void VO::add(std::string key) {
    int lugarCerto = VO::search(key);

    if (vo.empty()) {
        Palavra* p = new Palavra(key);
        vo.push_back(p);
        return;
    }
    // quando a palavra é maior que todas as outras,
    // lugarCerto é maior que o índice do último elemento.
    if (lugarCerto > (int)vo.size() - 1) {
        Palavra* p = new Palavra(key);
        vo.insert(vo.end(), p);
        return;
    }
    if (vo[lugarCerto]->key == key) {
        vo[lugarCerto]->numOcorrencias++;
        return;
    }
    if (vo[lugarCerto]->key != key) {
        Palavra* p = new Palavra(key);
        vo.insert(vo.begin() + lugarCerto, p);
        return;
    }
}

void VO::printVO() {
    for (unsigned long int i = 0; i < vo.size(); i++) {
		std::cout << std::left << std::setw(40) << vo[i]->key;
		std::cout << " | Ocorrências: " << std::left << std::setw(4) << vo[i]->numOcorrencias;
		std::cout << " | Letras: " << std::left << std::setw(2) << vo[i]->numLetras;
		std::cout << " | Vogais: " << std::left << std::setw(1) << vo[i]->numVogais << std::endl;
    }
}


// Consultas
void VO::palavrasMaisFrequentes() {
	std::vector<std::string> palavrasMaiorFrequencia;
	int maiorFrequencia = 0;
	for (unsigned long int i = 0; i < vo.size(); i++) {
		if (vo[i]->numOcorrencias >= maiorFrequencia) {
			if (vo[i]->numOcorrencias > maiorFrequencia) {
				maiorFrequencia = vo[i]->numOcorrencias;
				palavrasMaiorFrequencia.clear();
			}
			palavrasMaiorFrequencia.push_back(vo[i]->key);
		}
	}
	for (auto it : palavrasMaiorFrequencia) std::cout << it << " ";
	std::cout << std::endl;
}

int VO::frequenciaPalavra(std::string key) {
	return value(key)->numOcorrencias;
}

void VO::palavrasMaisLongas() {
	std::vector<std::string> palavrasMaisLongas;
	int maiorTamanho = 0;
	for (unsigned long int i = 0; i < vo.size(); i++) {
		if (vo[i]->numLetras >= maiorTamanho) {
			if (vo[i]->numLetras > maiorTamanho) {
				maiorTamanho = vo[i]->numLetras;
				palavrasMaisLongas.clear();
			}
			palavrasMaisLongas.push_back(vo[i]->key);
		}
	}
	for (auto it : palavrasMaisLongas) std::cout << it << " ";
	std::cout << std::endl;
}

bool VO::repeteLetras(std::string key) {
	std::vector<char> letras;
	for (auto it : key) {
		for (auto it2 : letras) {
			if (it == it2) return true;
		}
		letras.push_back(it);
	}
	return false;
}
void VO::maioresPalavrasSemRepeticaoLetras() {
	std::vector<std::string> maioresPalavrasSemRepeticaoLetras;
	int maiorTamanho = 0;
	for (unsigned long int i = 0; i < vo.size(); i++) {
		if (vo[i]->numLetras >= maiorTamanho && !repeteLetras(vo[i]->key)) {
			if (vo[i]->numLetras > maiorTamanho) {
				maiorTamanho = vo[i]->numLetras;
				maioresPalavrasSemRepeticaoLetras.clear();
			}
			maioresPalavrasSemRepeticaoLetras.push_back(vo[i]->key);
		}
	}
	for (auto it : maioresPalavrasSemRepeticaoLetras) std::cout << it << " ";
	std::cout << std::endl;
}

bool VO::repeteVogais(std::string key) {
	std::vector<char> vogais;
	for (auto it : key) {
		if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u'
		 || it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U') {
			for (auto it2 : vogais) {
				if (it == it2) return true;
			}
			vogais.push_back(it);
		}
	}
	return false;
}
void VO::menoresPalavrasSemRepeticaoVogais() {
	std::vector<std::string> menoresPalavrasSemRepeticaoVogais;
	int menorTamanho = 100;
	for (unsigned long int i = 0; i < vo.size(); i++) {
		if (vo[i]->numLetras <= menorTamanho && !repeteVogais(vo[i]->key)) {
			if (vo[i]->numLetras < menorTamanho) {
				menorTamanho = vo[i]->numLetras;
				menoresPalavrasSemRepeticaoVogais.clear();
			}
			menoresPalavrasSemRepeticaoVogais.push_back(vo[i]->key);
		}
	}
	for (auto it : menoresPalavrasSemRepeticaoVogais) std::cout << it << " ";
	std::cout << std::endl;
}