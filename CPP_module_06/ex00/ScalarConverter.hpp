#pragma once

#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void		convert(std::string &param);
};

// checkers	
bool	isCharacter(const std::string &param);
bool	isInteger(const std::string &param);
/*bool	isFloat(const std::string &param);*/
/*bool	isDouble(const std::string &param);*/
/**/
/*// printers*/
/*void	printCharacter(const std::string &param);*/
/*void	printInteger(const std::string &param);*/
/*void	printFloat(const std::string &param);*/
/*void	printDouble(const std::string &param);*/
