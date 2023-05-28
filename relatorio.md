# Relatório - EP2 de MAC0323
Nome: Gabriel Haruo Hanai Takeuchi
NUSP: 13671636

## Estruturas auxiliares
As classes auxiliares estão localizadas no arquivo `lib.c` e `lib.h`.
```c++
class Item {
public:
  int numOcorrencias;
  int numLetras;
  int numVogais; // número de vogais não-repetidas

  Item(std::string key) {
    this->numOcorrencias = 1;
    this->numLetras = contaNumLetras(key);
    this->numVogais = contaNumVogaisUnicas(key);
  }
};
```

## Vetor ordenado


## Árvore binária de busca


## Treap

## Árvore 2-3

## Árvore rubro-negra