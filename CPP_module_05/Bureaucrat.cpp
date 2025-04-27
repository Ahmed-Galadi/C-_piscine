
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("no_name"), grade(150) {
}

Bureaucrat::Bureaucrat(const std::string &initName,	int initGrade) : name(initName) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = initGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) {
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) 
		this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

const std::string &Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too Low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too Hight!");
}


