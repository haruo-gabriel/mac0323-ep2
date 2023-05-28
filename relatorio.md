# Relatório - EP2 de MAC0323
Nome: Gabriel Haruo Hanai Takeuchi
NUSP: 13671636

## ``lib.cpp`` e ``lib.h``
Os arquivos `lib.cpp` e `lib.h` contêm estruturas de dados e funções auxiliares para o programa.

As estruturas auxiliares são:
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

As funções auxiliares são:
-  `std::vector<std::string> separaPalavras(unsigned int n);`
Lê a entrada e retorna um vetor de strings com as palavras filtradas; diferencia letras maiúsculas de minúsculas
- int contaNumLetras(const std::string& s);
- int contaNumVogaisUnicas(const std::string& s);
- bool repeteLetras(std::string key);
- bool repeteVogais(std::string key);


## Vetor ordenado
A implementação do vetor ordenado está localizada nos arquivos `vo.cpp` e `vo.h`.
A estrutura utilizada para armazenar os dados, localizada no arquivo `lib.h`, é a struct `Palavra` descrita abaixo:
```c++
struct Palavra {
  // Key
	std::string key;
  // Item
	int numOcorrencias;
	int numLetras;
	int numVogais; // número de vogais não-repetidas

	Palavra(std::string key) {
		this->key = key;
		this->numOcorrencias = 1;
		this->numLetras = contaNumLetras(key);
		this->numVogais = contaNumVogaisUnicas(key);
	}
};
```
Acima, note que `Key` e `Item` estão juntos em uma estrutura única chamada `Palavra`. Isso foi feito para facilitar a construção do VO.
O VO é um `std::vector<Palavras*>`, que é ordenado em ordem alfabética. A cada inserção, usa-se de uma busca binária para encontrar a posição correta da palavra. Caso a palavra já exista, o número de ocorrências é incrementado. Caso contrário, a palavra é inserida na posição correta.

## Árvore binária de busca

## Treap

### ``MAXKEYS``

## Árvore 2-3

## Árvore rubro-negra