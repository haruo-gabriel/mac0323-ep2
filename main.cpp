#include <iostream>
// #include "vo/vo.h"
#include "a23/a23.h"
#include "lib.h"

// main - 
// vo - codado + testado - talvez tenha que fazer de novo
// abb - codado + testado
// tr - codado + testado
// a23 - codado + testado
// arn - codado + testado


int main() {
    std::string e, p;
    unsigned int n;
    std::vector<std::string> palavras;

    std::cin >> e >> n;
    palavras = separaPalavras(n);
    for (const std::string& it : palavras)
        std::cout << it << " ";
    std::cout << std::endl;

    if (e == "VO") {
        std::cout << "puta" << std::endl;
        // VO vo = VO();
    }
    else if (e == "ABB"){
    }
    else if (e == "TR"){
    }
    else if (e == "A23"){
        A23 a23 = A23();
        for (const std::string it : palavras)
            a23.add(it);
        a23.prettyPrint();
    }
    else if (e == "ARN"){

    } else {
        std::cout << "Estrutura invalida" << std::endl;
    }


    return 0;
}