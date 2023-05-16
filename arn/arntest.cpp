// test for arn.h
#include "arn.h"

int main() {
    // test add function
    ARN arn = ARN();

    // add the word "b"
    arn.add("b");
    arn.prettyPrint();
    std::cout << std::endl;

    // add word "a"
    arn.add("a");
    arn.prettyPrint();
    std::cout << std::endl;

    // add word "e"
    arn.add("e");
    arn.prettyPrint();
    std::cout << std::endl;

    // add the word "d"
    arn.add("d");
    arn.prettyPrint();
    std::cout << std::endl;

    // add the word "c"
    arn.add("c");
    arn.prettyPrint();
    std::cout << std::endl;

    return 0;
}