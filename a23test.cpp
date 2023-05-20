// main function to test the A23 class
#include "a23.h"

int main() {
    // test the add method
    A23 a23;
    NoA23* aux;

    a23.add("d");
    a23.printA23();
    std::cout << std::endl;
    printValue(a23.value("d"), "d");
    std::cout << std::endl;

    a23.add("a");
    a23.printA23();
    std::cout << std::endl;
    printValue(a23.value("a"), "a");
    std::cout << std::endl;

    a23.add("f");
    a23.printA23();
    std::cout << std::endl;

    a23.add("c");
    a23.printA23();
    std::cout << std::endl;

    a23.add("b");
    a23.printA23();
    std::cout << std::endl;

    a23.add("e");
    a23.printA23();
    std::cout << std::endl;

    a23.add("g");
    a23.printA23();
    std::cout << std::endl;
    
    a23.add("h");
    a23.printA23();
    std::cout << std::endl;

    a23.add("i");
    a23.printA23();
    std::cout << std::endl;

    a23.add("j");
    a23.printA23();
    std::cout << std::endl;

    a23.add("k");
    a23.printA23();
    std::cout << std::endl;

    a23.add("l");
    a23.printA23();
    std::cout << std::endl;
    
    a23.add("m");
    a23.printA23();
    std::cout << std::endl;

    a23.add("n");
    a23.printA23();
    std::cout << std::endl;

    a23.add("o");
    a23.printA23();
    std::cout << std::endl;

    return 0;
}