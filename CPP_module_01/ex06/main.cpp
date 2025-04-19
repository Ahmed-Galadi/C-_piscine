
#include "Harl.hpp"
#include <cstring>
#include <iostream>

int get_level_index(const std::string& level) {
	if (level == "DEBUG") return 0;
	if (level == "INFO") return 1;
	if (level == "WARNING") return 2;
	if (level == "ERROR") return 3;
	return (-1);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
		return (1);
	}

	Harl obj;
	int level = get_level_index(argv[1]);

	switch (level) {
		case 0:
			obj.complain("DEBUG");
			break;
		case 1:
			obj.complain("INFO");
			break;
		case 2:
			obj.complain("WARNING");
			break;
		case 3:
			obj.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
