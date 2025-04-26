
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("no_name"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &initName,	int initGrade) : name(initName) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = initGrade;
}


