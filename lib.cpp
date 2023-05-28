#include "lib.h"

int contaNumLetras(const std::string& s) {
    int cont = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        if (isalpha(s[i]))
            cont++;
    }
    return cont;
}

int contaNumVogaisUnicas(const std::string& s) {
    int cont = 0;
    int vogais[5] = {0, 0, 0, 0, 0};
    // vogais[0] para 'a', vogais[1] para 'e', vogais[2] para 'i'
    // vogais[3] para 'o', vogais[4] para 'u'
    for (unsigned int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            if ((s[i] == 'a' || s[i] == 'A') && vogais[0] == 0) {
                vogais[0] = 1;
                cont++;
            }
            else if ((s[i] == 'e' || s[i] == 'E') && vogais[1] == 0) {
                vogais[1] = 1;
                cont++;
            }
            else if ((s[i] == 'i' || s[i] == 'I') && vogais[2] == 0) {
                vogais[2] = 1;
                cont++;
            }
            else if ((s[i] == 'o' || s[i] == 'O') && vogais[3] == 0) {
                vogais[3] = 1;
                cont++;
            }
            else if ((s[i] == 'u' || s[i] == 'U') && vogais[4] == 0) {
                vogais[4] = 1;
                cont++;
            }
        }
    } 
    return cont;
}

std::vector<std::string> separaPalavras(unsigned int n) {
    std::vector<std::string> palavras;
    std::string input;

    unsigned int wordCount = 0;

    while (std::cin >> input && wordCount < n) {
        std::istringstream iss(input);
        std::string palavra;
        while (iss >> palavra) {
            std::string palavraFiltrada;

            auto it_beginWord = palavra.begin();
            while (!isalpha(*it_beginWord)){
                it_beginWord++;
                continue;
            }
            auto it_endWord = palavra.end();
            while (!isalpha(*it_endWord)) {
                it_endWord--;
                continue;
            }
            
            palavraFiltrada = std::string(it_beginWord, it_endWord+1);
            if (!palavraFiltrada.empty()) {
                palavras.push_back(palavraFiltrada);
                wordCount++;
            }
            if (wordCount >= n) break;
        }

        if (wordCount >= n) // Break out of the loop if the word count reaches or exceeds n
            break;
    }

    return palavras;
}

bool repeteVogais(std::string key) {
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
bool repeteLetras(std::string key) {
	std::vector<char> letras;
	for (auto it : key) {
		for (auto it2 : letras) {
			if (it == it2) return true;
		}
		letras.push_back(it);
	}
	return false;
}
// template <typename T>
// void printInordem(<T> r) {
// 	printInordemHelper(r);
// }

// template <typename T>
// void printInordemHelper(<T> r) {
// 	if (r != nullptr) {
// 		printInordemHelper(r->esq);

// 		std::cout << std::left << std::setw(40) << r->key;
// 		std::cout << " | Ocorrências: " << std::left << std::setw(4) << r->value->numOcorrencias;
// 		std::cout << " | Letras: " << std::left << std::setw(2) << r->value->numLetras;
// 		std::cout << " | Vogais: " << std::left << std::setw(1) << r->value->numVogais << std::endl;

// 		printInordemHelper(r->dir);
// 	}
// };