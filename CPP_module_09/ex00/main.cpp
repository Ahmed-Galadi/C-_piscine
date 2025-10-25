#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <climits>

bool isLeap(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

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
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeap(year))
		daysInMonth[2] = 29;
	return (year <= 9999 && year >= 1000 && month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth[month]);
}



std::map<std::string, double> createFileMap(std::string &fileName, char del) {
	std::ifstream	file(fileName);
	std::map<std::string, double> output;
	if (!file.is_open())
		throw ("Error: could not open file.");
	std::string		line;
	std::getline(file, line);
	while (std::getline(file, line)) {

		std::string datePart;
		std::string valuePart;
		size_t		pos = line.find(del);

		
		datePart = line.substr(0, 10);

		valuePart = line.substr(pos+1);
		std::stringstream ss(valuePart);
		double	value;
		ss >> value;

		output[datePart] = value;
	}
	return (output);
}

void	rmWhiteSpace(std::string &str) {
	std::string output;
	for (int i = 0; i < str.length(); i++)
		if (!std::isspace(str[i]))
			output += str[i];
	str = output;
}
void decDate(std::string &date) {
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	if (day - 1 == 0) {
		day = 31;
		if (month - 1 > 0) month--;
		else month = 12, year--;
	} else day--;
	std::stringstream ss;
	ss << year << "-";
	if (month < 10) ss << '0';
	ss << month << "-";
	if (day < 10) ss << '0';
	ss << day;
	std::string output;
	ss >> output;
	date = output;
}

std::string getPrevDate(std::string &date, std::map<std::string, double> data) {
	if (data[date] != 0)
		return (date);
	int goBackCount = 10;
	while (goBackCount--) {
		decDate(date);
		if (!isDateValid(date)) continue;
		if (data[date] != 0) return (date);
	}
	return ("xx-xx-xx");
} 

void	calculateBTC(std::map<std::string, double> data, std::string &inFileName) {
	std::ifstream inFile(inFileName);
	std::string line;
	std::getline(inFile, line);
	while (std::getline(inFile, line)) {
		std::string datePart = line.substr(0,10);
		size_t pos = line.find('|');
		if (!isDateValid(datePart) || pos == std::string::npos) {
			std::cout << "\e[31mError: Bad Input => \e[35m" << line << "\e[0m" << std::endl;
			continue;
		}
		rmWhiteSpace(line);
		pos = line.find('|');
		std::stringstream ss(line.substr(pos+1));
		double valuePart;
		ss >> valuePart;
		if (ss.fail()) {
			std::cout << "\e[31mError: Bad Input => \e[35m" << line << "\e[0m" << std::endl;
			continue;
		}
		if (valuePart < 0) {
			std::cout << "\e[31mError: Not a Positive Number.\e[0m\n";
			continue;
		}
		if (valuePart > 1000) {
			std::cout << "\e[31mError: too large a number.\e[0m\n";
			continue;
		}
		std::string date = getPrevDate(datePart, data);
		std::cout << datePart << " " << valuePart << " => " << (valuePart * data[date]) << std::endl;
	}
}

int main(int argc, char *argv[]) {
	if (argc <= 1)
		return (1);
	std::string input = argv[1];
	std::string data = "data.csv";
	std::map<std::string, double> BTCdata = createFileMap(data, ',');
	calculateBTC(BTCdata, input); 
	return (0);
}
