
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>


int main(void)
{
	// ShrumberryCreationForm Tests 
	{
		Bureaucrat	*boss = new Bureaucrat("boss", 15);
		Bureaucrat	*employee = new Bureaucrat("employee", 150);
		AForm		*bossTreeForm = new ShrubberyCreationForm("ASCII");
		AForm		*employeeTreeForm = new ShrubberyCreationForm("errorASCII");

		std::cout << *boss;
		std::cout << *employee;
		std::cout << *bossTreeForm;
		std::cout << *employeeTreeForm;
		
		try {
			bossTreeForm->beSigned(*boss);
			employeeTreeForm->beSigned(*employee);
		} catch (AForm::gradeTooLowException &e) {
			std::cerr << employee->getName() << " Failed To Sign Form : " << e.what() << std::endl;
		}
		
		try {
			bossTreeForm->execute(*boss);
			employeeTreeForm->execute(*employee);
		} catch (AForm::NotSignedExeption &e) {
			std::cerr << "Failed To Execute Form ==> " << e.what() << std::endl;
		}

		delete boss;
		delete employee;
		delete bossTreeForm;
		delete employeeTreeForm;
	}
	
	return (0);
}
