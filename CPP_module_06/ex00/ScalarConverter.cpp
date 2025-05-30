#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

void ScalarConverter::convert(const std::string &param) {
	double value;
	bool isValid = (isCharacter(param) || isInteger(param) || isFloat(param) || isDouble(param) || isSpecialLiteral(param));

	if (!isValid) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	if (isCharacter(param))
		value = static_cast<double>(param[0]);
	else
		value = std::strtod(param.c_str(), NULL);

	printCharacter(value);
	printInteger(value);
	printFloat(value);
	printDouble(value);
}

void	printCharacter(double &value) {

	std::cout << "char: ";
	if (value < 0 || value > 127 || std::isnan(value))
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void printInteger(double &value) {
	std::cout << "int: ";
	if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX) || std::isnan(value))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void printFloat(double &value) {
	
	std::cout << "float: ";
	if (isinff(value) && value > 0)
		std::cout << "+";
	std::cout << static_cast<float>(value);
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void printDouble(double &value) {
	std::cout << "double: ";
	if (std::isinf(value) && value > 0)
		std::cout << "+";
	std::cout << static_cast<double>(value);
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
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

std::string removeChar(const std::string &str, const std::string &toRemove) {
    std::string output;
    for (std::size_t i = 0; i < str.length(); ++i) {
        bool skip = false;
        for (std::size_t j = 0; j < toRemove.length(); ++j) {
            if (str[i] == toRemove[j]) {
                skip = true;
                break;
            }
        }
        if (!skip)
            output += str[i];
    }
    return output;
}

// checks
bool isCharacter(const std::string &param) {
	return (param.length() == 1 && !std::isdigit(param[0]));
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

bool isSpecialLiteral(const std::string &param) {
	return param == "nan" || param == "nanf" ||
	       param == "+inf" || param == "+inff" ||
	       param == "-inf" || param == "-inff";
}
