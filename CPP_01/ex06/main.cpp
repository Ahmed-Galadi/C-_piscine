
#include "Harl.hpp"
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {
	Harl obj =  Harl();
	
	if (argc != 2) {
		std::cout << "ERROR: wrong args!" << std::endl;
		return (1);
	}
	if (std::strcmp(argv[1], "DEBUG") && std::strcmp(argv[1], "WARNING")
		&& std::strcmp(argv[1], "INFO") && std::strcmp(argv[1], "ERROR")) {
		obj.complain("GARBADGE");
		return (1);
	}
	switch (argv[1][0]) {
		case 'D':
			obj.complain("DEBUG");
			break;
		case 'I':
			obj.complain("INFO");
			break;
		case 'W':
			obj.complain("WARNING");
			break;
		case 'E':
			obj.complain("ERROR");
			break;
	}	
	return (0);
}
