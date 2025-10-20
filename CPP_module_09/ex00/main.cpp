#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <climits>

bool isDateValid(std::string date) {
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7) continue;
		if (!std::isdigit(date[i]))
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	return (year <= 9999 && year >= 1000 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
}



std::map<std::string, double> createFileMap(std::string &fileName) {
	std::ifstream	file(fileName);
	std::map<std::string, double> output;
	if (!file.is_open())
		throw ("Error: could not open file.");
	std::string		line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		if (line.length() < 14) {
			std::cout << "Error: Bad input => " << line << std::endl;
			continue;
		}
		std::string datePart;
		std::string valuePart;
		size_t		pos = line.find('|');
		if (pos == std::string::npos) {
			std::cout << "Error: Bad input => + " << line << std::endl;
			continue;
		}
		if (!std::isspace(line[pos + 1]) || !std::isspace(line[pos - 1])) {
			std::cout << "Error: Bad input => * " << line << std::endl;
			continue;
		}
		datePart = line.substr(0, 10);
		if (!isDateValid(datePart)) {
			std::cout << "Error: Bad input => / " << line << std::endl;
		}
		valuePart = line.substr(13);
		std::stringstream ss(valuePart);
		double	value;
		ss >> value;
		if (ss.fail()) {
			std::cout << "Error: Bad Input => & " << line << std::endl;
			continue;
		}
		if (value < 0){
			std::cout << "Error: not a positive number.\n";
			continue;
		}
		if (value >= INT_MAX) {

			std::cout << "Error: too large number.\n";
			continue;
		}
		output.insert(std::make_pair(datePart, value));
		std::cout << datePart << " => " << value << std::endl;
	}
	return (output);
}

int main(int argc, char *argv[]) {
	if (argc <= 1)
		return (1);
	std::string input = argv[1];
	try {
	createFileMap(input);
	} catch (const char *s) {
		std::cout << s << std::endl;
	} catch (...) {
		std::cout << "Error: something went wrong!" << std::endl;
	}
	return (0);
}
