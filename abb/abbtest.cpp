#include "abb.h"

// tests for the ABB class

int main() {
    ABB abb;

    // testing the add method
    // adding the word "A"
    abb.add("A", new Item(numLetras("A"), numVogaisUnicas("A")));
    abb.printABB(abb.raiz);
    std::cout << std::endl;

    // adding the word "B"
    abb.add("B", new Item(numLetras("B"), numVogaisUnicas("B")));
    abb.printABB(abb.raiz);
    std::cout << std::endl;

    // adding the word "AB"
    abb.add("AB", new Item(numLetras("AB"), numVogaisUnicas("AB")));
    abb.printABB(abb.raiz);
    std::cout << std::endl;

    // adding the word "A" again
    abb.add("A", new Item(numLetras("A"), numVogaisUnicas("A")));
    abb.printABB(abb.raiz);
    std::cout << std::endl;

    // adding the word "a"
    abb.add("a", new Item(numLetras("a"), numVogaisUnicas("a")));
    abb.printABB(abb.raiz);
    std::cout << std::endl;

    // adding the word "AB" again
    abb.add("AB", new Item(numLetras("AB"), numVogaisUnicas("AB")));
    abb.printABB(abb.raiz);
    std::cout << std::endl;

    // testing the value method
    std::cout << abb.value("A")->numOcorrencias << abb.value("A")->numLetras << abb.value("A")->numVogais << std::endl;
    std::cout << abb.value("B")->numOcorrencias << abb.value("B")->numLetras << abb.value("B")->numVogais << std::endl;
    std::cout << abb.value("AB")->numOcorrencias << abb.value("AB")->numLetras << abb.value("AB")->numVogais << std::endl;
    std::cout << abb.value("a")->numOcorrencias << abb.value("a")->numLetras << abb.value("a")->numVogais << std::endl;

    return 0;
}