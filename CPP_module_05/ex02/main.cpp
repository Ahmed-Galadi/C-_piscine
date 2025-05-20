
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
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
			std::cerr << employee->getName() << "Failed To Execute Form ==>"
						<< " " <<e.what() << std::endl;
		}

		delete boss;
		delete employee;
		delete bossTreeForm;
		delete employeeTreeForm;
	}

// RobotomyRequestForm Tests
{
	Bureaucrat *robot = new Bureaucrat("Robot", 12);
	Bureaucrat *human = new Bureaucrat("Human", 77);
	AForm *mrRobotForm = new RobotomyRequestForm("MR-Robot");
	AForm *mrHumanForm = new RobotomyRequestForm("MR-Human");

	std::cout << *mrRobotForm;
	std::cout << *mrHumanForm;

	try {
		mrRobotForm->beSigned(*robot);
		mrHumanForm->beSigned(*human);
	} catch (AForm::gradeTooLowException &e) {
		std::cerr << human->getName() << " Failed To Sign Form: "
				  << e.what() << std::endl;
	}

	try {
		mrRobotForm->execute(*robot);
		mrHumanForm->execute(*human);
	} catch (AForm::NotSignedExeption &e) {
		std::cerr << human->getName() << " Failed To Execute Form ==> "
				  << e.what() << std::endl;
	} catch (AForm::gradeTooLowException &e) {
		std::cerr << "Execution grade too low: " << e.what() << std::endl;
	} catch (RobotomyRequestForm::FailedRobotomyExeption &e) {
		std::cerr << "    \\_\\ \n\
   (_**)\n\
  __) #_\n\
 ( )...()\n\
 || | |I|\n\
 || | |()__/\n\
 /\\(___)\n\
_-\"\"\"\"\"\"\"-_\n\
-,,,,,,,,- # [" << e.what() << "] #" << std::endl;
	}

	delete robot;
	delete human;
	delete mrRobotForm;
	delete mrHumanForm;
}



	return (0);
}
