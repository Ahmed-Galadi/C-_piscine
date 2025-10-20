#include <iostream>
#include <fstream>
#include <map>
#include <string>



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

std::map<std::string, double> createInFileMap(std::string &fileName) {
	std::ifstream	file(fileName);
	if (!file.is_open())
		throw ("Error: could not open file.");
	std::string		line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		if (line.length() < 14)
			throw ("Error: Bad input => " + line);
		std::string datePart;
		std::string valuePart;
		size_t		pos = line.find('|');
		if (pos == std::string::npos)
			throw ("Error: Bad input => + " + line);
		if (!std::isspace(line[pos + 1]) || !std::isspace(line[pos - 1]))
			throw ("Error: Bad input => * " + line);
		datePart = line.substr(0, 10);
		if (!isDateValid(datePart))
			throw ("Error: Bad input => / " + line);
		valuePart = line.substr(13);
		if (std::atod(valuePart.c_str()) < 0)
			throw ("Error: Not a Positive Number!");
		
	}
}

/*std::map<std::string, double> createDB(std::string &fileName) {*/
/**/
/*}*/


int main(int argc, char *argv[]) {
	std::string input = argv[1];
	try {
	createInFileMap(input);
	} catch (std::string s) {
		std::cout << s << std::endl;
	}
	return (0);
}
