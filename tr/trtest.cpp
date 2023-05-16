// Driver Program to test above functions
#include "tr.h"

int main() {
	srand(time(NULL));

	TR* tr = new TR();

	// test the add method
	// insert the word "b"
	tr->add(tr->raiz, "b", new Item("a"));
	tr->value("b");
	tr->inordem(tr->raiz);
	std::cout << std::endl;

	// insert the word "a"
	tr->add(tr->raiz, "a", new Item("a"));
	tr->value("a");
	tr->inordem(tr->raiz);
	std::cout << std::endl;

	// insert the word "c"
	tr->add(tr->raiz, "c", new Item("c"));
	tr->value("c");
	tr->inordem(tr->raiz);
	std::cout << std::endl;

	// insert the word "d"
	tr->add(tr->raiz, "d", new Item("d"));
	tr->value("d");
	tr->inordem(tr->raiz);
	std::cout << std::endl;

	// insert the word "e"
	tr->add(tr->raiz, "e", new Item("e"));
	tr->value("e");
	tr->inordem(tr->raiz);
	std::cout << std::endl;

	return 0;
}
