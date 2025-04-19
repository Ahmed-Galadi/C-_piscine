#include <iostream>
#include <fstream>
#include <string>

void replace_words(std::string &original_str, const std::string &to_find, const std::string &to_replace) {
	size_t toFindPos = original_str.find(to_find);

	while (toFindPos != std::string::npos) {
		original_str.erase(toFindPos, to_find.length());
		original_str.insert(toFindPos, to_replace);
		toFindPos = original_str.find(to_find, toFindPos + to_replace.length());
	}
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Error: wrong args!" << std::endl;
		return (1);
	}

	if (!*argv[2])
		return (1);
	std::ifstream oldFile(argv[1], std::ios::in);
	if (!oldFile.is_open()) {
		std::cout << "Error: cannot open files!" << std::endl;
		oldFile.close();
		return (1);
	}
	std::ofstream newFile((std::string(argv[1]) + ".replace").c_str());
	if (!newFile.is_open()) {
		std::cout << "Error: cannot open files!" << std::endl;
		newFile.close();
		return (1);
	}

	std::string fileLine;
	while (std::getline(oldFile, fileLine)) {
		replace_words(fileLine, std::string(argv[2]), std::string(argv[3]));
		newFile << fileLine;
		if (!oldFile.eof())
			newFile << "\n";
	}
	oldFile.close();
	newFile.close();
	return (0);
}
