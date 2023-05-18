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

    int wordCount = 0; // Counter variable for tracking the number of words read

    while (std::cin >> input && wordCount < n) {
        std::istringstream iss(input);
        std::string palavra;
        while (iss >> palavra) {
            std::string palavraFiltrada;
            for (char c : palavra)
                if (isalpha(c)) palavraFiltrada += c;
            if (!palavraFiltrada.empty())
                palavras.push_back(palavraFiltrada);

            ++wordCount; // Increment the word count after each word is processed

            if (wordCount >= n) // Break out of the loop if the word count reaches or exceeds n
                break;
        }

        if (wordCount >= n) // Break out of the loop if the word count reaches or exceeds n
            break;
    }

    return palavras;
}