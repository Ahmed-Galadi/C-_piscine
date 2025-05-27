#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string &param) {
	if (param.empty())
		std::cout << std::endl;
	/*else if (isCharacter(param))*/
	/*	printCharacter(param);*/
	/*else if (isInteger(param))*/
	/*	printInteger(param);*/
	/*else if (isFloat(param))*/
	/*	printFloat(param);*/
	/*else if (isDouble(param))*/
	/*	printDouble(param);*/
}

// helpers
bool isRepeated(const std::string &str, char c) {
	int repeatCount = 0;
	for (std::size_t i = 0; i < str.length(); i++) {
		if (str[i] == c)
			repeatCount++;
	}
	return (repeatCount > 1);
}

bool isCharsValid(const std::string &str, const std::string &validChars) {
	bool isValid = false;

	if (str.find('+') != std::string::npos && str.find('+') != 0)
		return false;
	if (str.find('-') != std::string::npos && str.find('-') != 0)
		return false;
	for (std::size_t i = 0; i < str.length(); i++) {
		isValid = false;
		for (std::size_t j = 0; j < validChars.length(); j++) {
			if (str[i] == validChars[j] || std::isdigit(str[i])) {
				isValid = true;
				break;
			}
		}
		if (!isValid)
			return false;
	}
	return true;
}


// checks
bool	isCharacter(const std::string &param) {
	return (param.length() == 1 && std::isprint(param[0]));
}

bool	isInteger(const std::string &param) {
	std::size_t i = 0;
	if ( (param[i] == '+' || param[i] == '-')) {
		if (param.length() == 1)
			return (false);
		i++;
	}
	for (; i < param.length(); i++)
		if (!std::isdigit(param[i]))
			return (false);
	return (true);
}


bool isFloat(const std::string &param) {

	std::size_t dotPos = param.find('.');

	if (param.find('.') == std::string::npos || param.find('f') == std::string::npos)
		return false;
	if (!isCharsValid(param, "-+f."))
		return false;
	if (isRepeated(param, '.') || isRepeated(param, 'f'))
		return false;
	if (param[param.size() - 1] != 'f')
		return false;
	if (dotPos == 0 || dotPos >= param.length() - 2)
		return false;
	if (!std::isdigit(param[dotPos - 1]) || !std::isdigit(param[dotPos + 1]))
		return false;
	return true;
}

bool isDouble(const std::string &param) {
	std::size_t dotPos = param.find('.');

	if (param.find('.') == std::string::npos)
		return false;
	if (!isCharsValid(param, "-+."))
		return false;
	if (isRepeated(param, '.'))
		return false;
	if (dotPos == 0 || dotPos >= param.length() - 1)
		return false;
	if (!std::isdigit(param[dotPos - 1]) || !std::isdigit(param[dotPos + 1]))
		return false;
	return true;
}

// printers
void	printCharacter(const std::string &param) {
	std::cout << "char: ";
	if (isCharacter(param))
		std::cout << static_cast<char>(param[0]) << std::endl;
	else
		 std::cout << "not printable!" << std::endl;
}

void	printInteger(const std::string &param) {
	std::cout << "int: ";
	if (isCharacter(param))
		std::cout << static_cast<char>(param[0]) + 0 << std::endl;
}
