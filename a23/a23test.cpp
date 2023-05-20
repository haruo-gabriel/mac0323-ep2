// main function to test the A23 class
#include "a23.h"

int main() {
    // test the add method
    A23 a23;
    NoA23* aux;

    a23.add("d");
    a23.prettyPrint();
    std::cout << std::endl;
    printValue(a23.value("d"), "d");

    a23.add("a");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("f");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("c");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("b");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("e");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("g");
    a23.prettyPrint();
    std::cout << std::endl;
    
    a23.add("h");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("i");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("j");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("k");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("l");
    a23.prettyPrint();
    std::cout << std::endl;
    
    a23.add("m");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("n");
    a23.prettyPrint();
    std::cout << std::endl;

    a23.add("o");
    a23.prettyPrint();
    std::cout << std::endl;

    return 0;
}