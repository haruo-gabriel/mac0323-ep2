// test for arn.h
#include "arn.h"

int main() {
    // test add function
    ARN arn = ARN();

    // add the word "b"
    arn.insert("b");
    arn.prettyPrint();
    std::cout << std::endl;

    // add word "a"
    arn.insert("a");
    arn.prettyPrint();
    std::cout << std::endl;

    // add word "e"
    arn.insert("e");
    arn.prettyPrint();
    std::cout << std::endl;

    // add the word "d"
    arn.insert("d");
    arn.prettyPrint();
    std::cout << std::endl;

    // add the word "c"
    arn.insert("c");
    arn.prettyPrint();
    std::cout << std::endl;

    // add the word "c" again
    arn.insert("c");
    arn.prettyPrint();
    std::cout << std::endl;

    return 0;
}