#include "../lib.h"

class VO {
public:
    std::vector<Palavra*> vo;

    Item* value(std::string key);
    void add(std::string key, Item value);
    void printVO();
private:
    int search(std::string key);
};