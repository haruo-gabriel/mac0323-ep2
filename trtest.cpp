// Driver Program to test above functions
#include "tr.h"

int main() {
	srand(time(NULL));

	TR tr = TR();

	// test the add method
	tr.add("d");
	tr.printTR();
	tr.printValue(tr.value("d"));
	std::cout << std::endl;

	tr.add("a");
	tr.printTR();
	tr.printValue(tr.value("a"));
	std::cout << std::endl;

	tr.add("f");
	tr.printTR();
	tr.printValue(tr.value("f"));
	std::cout << std::endl;

	tr.add("c");
	tr.printTR();
	tr.printValue(tr.value("c"));
	std::cout << std::endl;

	tr.add("b");
	tr.printTR();
	tr.printValue(tr.value("b"));
	std::cout << std::endl;

	tr.add("e");
	tr.printTR();
	tr.printValue(tr.value("e"));
	std::cout << std::endl;

	tr.add("g");
	tr.printTR();
	tr.printValue(tr.value("g"));
	std::cout << std::endl;

	tr.add("h");
	tr.printTR();
	tr.printValue(tr.value("h"));
	std::cout << std::endl;

	tr.add("i");
	tr.printTR();
	tr.printValue(tr.value("i"));
	std::cout << std::endl;

	tr.add("j");
	tr.printTR();
	tr.printValue(tr.value("j"));
	std::cout << std::endl;

	tr.add("k");
	tr.printTR();
	tr.printValue(tr.value("k"));
	std::cout << std::endl;

	tr.add("l");
	tr.printTR();
	tr.printValue(tr.value("l"));
	std::cout << std::endl;

	tr.add("m");
	tr.printTR();
	tr.printValue(tr.value("m"));
	std::cout << std::endl;

	tr.add("n");
	tr.printTR();
	tr.printValue(tr.value("n"));
	std::cout << std::endl;

	tr.add("o");
	tr.printTR();
	tr.printValue(tr.value("o"));
	std::cout << std::endl;

	return 0;
}
