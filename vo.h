#ifndef VO_H
#define VO_H

#include "lib.h"
class VO {
public:
    std::vector<Palavra*> vo; // vetor ordenado por ordem alfabética
    VO() { }

    Palavra* value(std::string key);
    void add(std::string key);
    void printVO();
    int search(std::string key);
};

#endif // VO_H