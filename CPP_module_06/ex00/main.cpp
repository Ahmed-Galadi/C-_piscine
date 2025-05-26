#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc == 2) {
		std::cout << isCharacter(argv[1]) << std::endl;
		std::cout << isInteger(argv[1]) << std::endl;
	}

}
