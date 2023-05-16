// Como compilar e executar (deve estar no diretório vo):
// g++ -Wall -g ../lib.cpp vo.cpp votest.cpp -o votest.out
// ./votest.out

#include "vo.h"

// usando busca binária
int VO::search(std::string key) {
    int esq = 0, meio, dir = vo.size()-1;
    while (esq <= dir){
        meio = esq + (dir - esq) / 2;
        if (key == vo[meio]->key){
            return meio;
        } else if (key < vo[meio]->key){
            dir = meio - 1;
        } else {
            esq = meio + 1;
        }
    }
    return esq;
}

Item* VO::value(std::string key) {
    int lugarCerto = VO::search(key);
    if (vo[lugarCerto]->key == key)
        return vo[lugarCerto]->value;
    return nullptr;
}

void VO::add(std::string key, Item value) {
    int lugarCerto = VO::search(key);

    if (vo.empty()) {
        Palavra* p = new Palavra;
        p->value = new Item;
        p->key = key;
        p->value->numOcorrencias = 1;
        p->value->numLetras = value.numLetras;
        p->value->numVogais = value.numVogais;
        vo.push_back(p);
        return;
    }
    // quando a palavra é maior que todas as outras,
    // lugarCerto é maior que o índice do último elemento.
    if (lugarCerto > (int)vo.size() - 1) {
        Palavra* p = new Palavra;
        p->value = new Item;
        p->key = key;
        p->value->numOcorrencias = 1;
        p->value->numLetras = value.numLetras;
        p->value->numVogais = value.numVogais;
        vo.insert(vo.end(), p);
        return;
    }
    if (vo[lugarCerto]->key == key) {
        vo[lugarCerto]->value->numOcorrencias++;
        return;
    }
    if (vo[lugarCerto]->key != key) {
        Palavra* p = new Palavra;
        p->value = new Item;
        p->key = key;
        p->value->numOcorrencias = 1;
        p->value->numLetras = value.numLetras;
        p->value->numVogais = value.numVogais;
        vo.insert(vo.begin() + lugarCerto, p);
        return;
    }
}

void VO::printVO() {
    for (unsigned int i = 0; i < vo.size(); i++) {
        std::cout << vo[i]->key << " " << vo[i]->value->numOcorrencias << " " << vo[i]->value->numLetras << " " << vo[i]->value->numVogais << std::endl;
    }
}