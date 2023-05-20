#include <iostream>
// #include "vo/vo.h"
#include "a23.h"
#include "vo.h"

// main - 
// vo - codado + testado - talvez tenha que fazer de novo
// abb - codado + testado
// tr - codado + testado
// a23 - codado + testado
// arn - codado + testado


int main() {
    std::string e, p;
    int n, q;
    std::vector<std::string> palavras;

    // Entradas
    std::cin >> e >> n;
    palavras = separaPalavras(n);
    for (const std::string& it : palavras)
        std::cout << it << " ";
    std::cout << std::endl << std::endl;

    // Estruturas
    if (e == "VO") {
        std::cout << "Construindo VO" << std::endl;
        VO vo = VO();
        for (const std::string &it : palavras)
            vo.add(it);
        vo.printVO();
    }
    else if (e == "ABB"){
        std::cout << "Construindo ABB" << std::endl;
    }
    else if (e == "TR"){
        std::cout << "Construindo TR" << std::endl;
    }
    else if (e == "A23"){
        std::cout << "Construindo A23" << std::endl;
        A23 a23 = A23();
        for (const std::string &it : palavras)
            a23.add(it);
        a23.printA23();
    }
    else if (e == "ARN"){
        std::cout << "Construindo ARN" << std::endl;
    }
    else {
        std::cout << "Estrutura invalida" << std::endl;
    }

    // Consultas
    std::cin >> q;
    for (int i=0; i<q; i++) {
        std::string consulta; std::cin >> consulta;
        if (consulta == "F") {

        }
        else if (consulta == "O") {
            std::string O_palavra; std::cin >> O_palavra;
        }
        else if (consulta == "L") {

        }
        else if (consulta == "SR") {

        }
        else if (consulta == "VD") {

        }
        else {
            std::cout << "Consulta inválida. Tente novamente." << std::endl;
            i--;
        }
    }

    return 0;
}