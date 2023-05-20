#include "../lib.h"

class NoA23 {
public:
    std::string key1, key2;
    Item* value1; Item* value2;
    NoA23* esq; NoA23* mid; NoA23* dir;
    int nKeys;
    NoA23() {
        key1 = ""; key2 = "";
        value1 = value2 = nullptr;
        esq = mid = dir = nullptr;
        nKeys = 0;
    }
    ~NoA23() {
        value1 = value2 = nullptr; delete value1; delete value2;
        esq = mid = dir = nullptr; delete esq; delete mid; delete dir;
    }
};

bool ehFolha(NoA23* r);

class A23 {
private:
    // bool* cresceu;

    NoA23* addHelper(NoA23* raiz, std::string key, bool* cresceu);
    // void printHelper(NoA23* node, std::string indent, bool isLast);
public:
    NoA23* raiz;
    A23() {
        raiz = nullptr;
        // cresceu = new bool(false);
    }

    // inserção
    void add(std::string key);

    // busca
    NoA23* value(std::string key);

    // auxiliares
    void prettyPrint();
};

// void print_tree(NoA23* r, int level = 0);