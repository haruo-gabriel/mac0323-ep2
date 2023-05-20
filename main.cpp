#include <iostream>
// #include "vo/vo.h"
#include "lib.h"

// main - 
// vo - codado + testado
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
    }
    else if (e == "ARN"){

    }


    return 0;
}