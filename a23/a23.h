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
        free(value1); free(value2);
        free(esq); free(mid); free(dir);
    }
};
void printValue(NoA23* node, std::string key);

bool ehFolha(NoA23* r);

class A23 {
private:
    NoA23* addHelper(NoA23* raiz, std::string key, bool* cresceu);
    NoA23* valueHelper(NoA23* r, std::string key);
    // void printHelper(NoA23* node, std::string indent, bool isLast);
public:
    NoA23* raiz;
    A23() {
        raiz = nullptr;
    }

    void add(std::string key);
    NoA23* value(std::string key);
    void prettyPrint();
};
