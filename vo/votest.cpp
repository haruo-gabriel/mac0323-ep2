#include "vo.h"

int main() {
    // make tests to verify if the member functions are working
    // create a VO object
    VO vo;

    // add some words
    std::string key = "teste";
    Item item;
    item.numLetras = 5;
    item.numVogais = 1;
    item.numOcorrencias = 1;
    std::cout << vo.search(key) << std::endl;
    vo.add(key, item);
    std::cout << vo.value(key)->numOcorrencias << std::endl;
    vo.printVO();
    std::cout << std::endl;

    // test with another word
    std::string key2 = "abacate";
    Item item2;
    item2.numLetras = 7;
    item2.numVogais = 2;
    item2.numOcorrencias = 1;
    std::cout << vo.value(key2) << std::endl;
    vo.add(key2, item2);
    vo.printVO();
    std::cout << std::endl;

    // add an existing word
    std::string key3 = "abacate";
    Item item3;
    item3.numLetras = 7;
    item3.numVogais = 2;
    item3.numOcorrencias = 1;
    std::cout << vo.search(key3) << std::endl;
    vo.add(key3, item3);
    vo.printVO();
    std::cout << std::endl;

    // add a word that should be in the middle
    std::string key4 = "banana";
    Item item4;
    item4.numLetras = 6;
    item4.numVogais = 1;
    item4.numOcorrencias = 1;
    std::cout << vo.search(key4) << std::endl;
    vo.add(key4, item4);
    vo.printVO();
    std::cout << std::endl;

    // add a new word that should be in the end
    std::string key5 = "zebra";
    Item item5;
    item5.numLetras = 5;
    item5.numVogais = 2;
    item5.numOcorrencias = 1;
    std::cout << vo.search(key5) << std::endl;
    vo.add(key5, item5);
    vo.printVO();
    std::cout << std::endl;

    // add a word that should be in the beginning
    std::string key6 = "aba";
    Item item6;
    item6.numLetras = 3;
    item6.numVogais = 1;
    item6.numOcorrencias = 1;
    std::cout << vo.search(key6) << std::endl;
    vo.add(key6, item6);
    vo.printVO();
    std::cout << std::endl;

    // add zebra again
    std::cout << vo.search(key5) << std::endl;
    vo.add(key5, item5);
    vo.printVO();
    std::cout << std::endl;

    // add another word that should be in the beginning
    std::string key7 = "a";
    Item item7;
    item7.numLetras = 1;
    item7.numVogais = 1;
    item7.numOcorrencias = 1;
    std::cout << vo.search(key7) << std::endl;
    vo.add(key7, item7);
    vo.printVO();
    std::cout << std::endl;

    // free

    return 0;
}