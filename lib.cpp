#include "lib.h"

int contaNumLetras(std::string s) {
    int cont = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        if (isalpha(s[i]))
            cont++;
    }
    return cont;
}

int contaNumVogaisUnicas(std::string s) {
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