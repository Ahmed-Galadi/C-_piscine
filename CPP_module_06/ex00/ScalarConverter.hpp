#pragma once

#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void		convert(const std::string &param);
};


// helpers
bool			isRepeated(const std::string &str, char c);

// checkers	
bool	isCharacter(const std::string &param);
bool	isInteger(const std::string &param);
bool	isFloat(const std::string &param);
bool	isDouble(const std::string &param);
bool	isSpecialLiteral(const std::string &param);
// printers
void	printCharacter(double &value);
void	printInteger(double &value);
void	printFloat(double &value);
void	printDouble(double &value);
