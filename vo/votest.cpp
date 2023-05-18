#include "vo.h"

int main() {
    // make tests to verify if the member functions are working
    // create a VO object
    VO vo;

    // add some words
    std::string key = "teste";
    Item item(key);
    std::cout << vo.search(key) << std::endl;
    vo.add(key);
    std::cout << vo.value(key)->numOcorrencias << std::endl;
    vo.printVO();
    std::cout << std::endl;

    // test with another word
    std::string key2 = "abacate";
    Item item2 = Item(key2);
    std::cout << vo.value(key2) << std::endl;
    vo.add(key2);
    vo.printVO();
    std::cout << std::endl;

    // add an existing word
    std::string key3 = "abacate";
    Item item3 = Item(key3);
    std::cout << vo.search(key3) << std::endl;
    vo.add(key3);
    vo.printVO();
    std::cout << std::endl;

    // add a word that should be in the middle
    std::string key4 = "banana";
    Item item4 = Item(key4);
    std::cout << vo.search(key4) << std::endl;
    vo.add(key4);
    vo.printVO();
    std::cout << std::endl;

    // add a new word that should be in the end
    std::string key5 = "zebra";
    Item item5 = Item(key5);
    item5.numLetras = 5;
    item5.numVogais = 2;
    item5.numOcorrencias = 1;
    std::cout << vo.search(key5) << std::endl;
    vo.add(key5);
    vo.printVO();
    std::cout << std::endl;

    // add a word that should be in the beginning
    std::string key6 = "aba";
    Item item6 = Item(key6);
    item6.numLetras = 3;
    item6.numVogais = 1;
    item6.numOcorrencias = 1;
    std::cout << vo.search(key6) << std::endl;
    vo.add(key6);
    vo.printVO();
    std::cout << std::endl;

    // add zebra again
    std::cout << vo.search(key5) << std::endl;
    vo.add(key5);
    vo.printVO();
    std::cout << std::endl;

    // add another word that should be in the beginning
    std::string key7 = "a";
    Item item7 = Item(key7);
    std::cout << vo.search(key7) << std::endl;
    vo.add(key7);
    vo.printVO();
    std::cout << std::endl;

    // free

    return 0;
}