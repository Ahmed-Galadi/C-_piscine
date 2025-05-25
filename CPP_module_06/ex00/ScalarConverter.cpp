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
	if (isCharacter(param))
		printCharacter(param);
	else if (isInteger(param))
		printInteger(param);
	else if (isFloat(param))
		printFloat(param);
	else if (isDouble(param))
		printDouble(param);
}

bool	isCharacter(const std::string &param) {
	if (param.length() == 1)
		return (true);
	return (false);
}
