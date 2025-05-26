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

bool	isRepeated(const std::string &str, char c) {
	int	repeatCount = 0;
	for (std::size_t i = 0; i < str.length(); i++) {
		if (str[i] == c)
			repeatCount++;
		if (repeatCount > 1)
			return (false);
	}
	return (true);
}

bool isFloat(const std::string &param) {
	const std::string &validChars = "-+f.";
	std::size_t i = 0;
	for (; i < validChars.length(); i++)
		if (isRepeated(param, validChars[i]))
			return (false);
	return (true);
}
