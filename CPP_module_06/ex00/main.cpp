#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc == 2) {
		std::cout << "is character ==> " << isCharacter(argv[1]) << std::endl;
		std::cout << "is integer ==> " << isInteger(argv[1]) << std::endl;
		std::cout << "is Float ==> " << isFloat(argv[1]) << std::endl;
		std::cout << "is Double ==> " << isDouble(argv[1]) << std::endl;
	}
	return (0);
}
