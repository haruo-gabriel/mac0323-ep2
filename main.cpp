#include <iostream>
#include "lib.h"
#include "vo/vo.h"

// main - 
// vo - codado + testado
// abb - codado + testado
// tr - codado + testado
// a23
// arn - codado + testado


int main() {
    std::string e, p;
    int n, q;
    std::cin >> e >> n;

    if (e == "VO") {
        VO vo = VO();
        for (int i=0; i<n; i++) {
            std::cin >> p;
            // std::cout << p << std::endl;
            if ()
            vo.add(p);
        }
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