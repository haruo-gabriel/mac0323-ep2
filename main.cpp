#include <iostream>
#include "vo/vo.h"

// main - 
// vo - codado + testado
// abb - codado + testado
// tr - codado + testado
// a23
// arn - codado + testado


int main() {
    std::string e, p;
    char c;
    unsigned int n, q;
    std::vector<std::string> palavras;

    std::cin >> e >> n;
    palavras = separaPalavras(n);
    for (const std::string& it : palavras)
        std::cout << it << " ";
    std::cout << std::endl;

    if (e == "VO") {
        // VO vo = VO();
        std::cout << "puta" << std::endl;
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