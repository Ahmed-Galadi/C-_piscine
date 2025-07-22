#include <iostream>
#include "Parsing.hpp"
#include <list>

int main(int argc, char *argv[]) {
	Parsing<std::list<int> > p(argv+1);

	try {
		std::list<int> l = p.inputParse(argc - 1);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl; 
	}
	std::cout << p;
	return (0);
}