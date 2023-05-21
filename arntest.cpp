// test for arn.h
#include "arn.h"

int main() {
    ARN arn = ARN();
    std::string s;
    NoARN* aux;

    while (true) {
        std::cout << "Insira uma palavra: ";
        std::cin >> s;
        std::cout << std::endl;
        arn.add(s);
        arn.printARN();
        std::cout << std::endl;
        aux = arn.value(s);
        arn.printValue(aux);
        std::cout << std::endl;
    }

    return 0;
}