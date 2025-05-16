
#include "ShrubberyCreationForm.hpp"
#include <fstream>

const std::string ShrubberyCreationForm::ASCII_TREE = "               ,@@@@@@@, \n\
       ,,,.   ,@@@@@@/@@,  .oo8888o. \n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o \n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' \n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' \n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' \n\
   `&%\\ ` /%&'    |.|        \\ '|8' \n\
       |o|        | |         | | \n\
       |.|        | |         | | \n\
    \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";

const char *ShrubberyCreationForm::ExecException::what() const throw () {
	return ("Shruberry Form cannot be executed! ==> Can't open file");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubberry Destroyed!" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	std::string fileName = this->target + "_shrubbery";
	std::ofstream file(fileName);

	if (!file.is_open())
		throw ExecException();
	file << ASCII_TREE;
	file.close();
}

