
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
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

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("[Shrubbery Creation Form]", 145, 137), target("[Default]") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &initTarget) : AForm(initTarget, 145, 137), target(initTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		target = other.target;
		this->setIsSigned(other.isFormSigned());
	}
	return (*this);
}

const char *ShrubberyCreationForm::ExecOpenException::what() const throw () {
	return ("Shruberry Form cannot be executed! ==> Can't open file");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubberry Destroyed!" << std::endl;
}

void	ShrubberyCreationForm::execForm(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::gradeTooLowException();
	std::string fileName = this->target + "_shrubbery";
	std::ofstream file(fileName.c_str());

	if (!file.is_open())
		throw ExecOpenException();
	file << ASCII_TREE;
	file.close();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

