
#include "includes.h"

Bureaucrat::Bureaucrat() : name("no_name"), grade(150) {
}

Bureaucrat::Bureaucrat(const std::string &initName,	int initGrade) : name(initName) {
	this->grade = initGrade;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
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
	return ("\e[31mGrade is too Low!\e[0m");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("\e[33mGrade is too Hight!\e[0m");
}

void	Bureaucrat::incBGrade() {
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decBGrade() {
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &toSignForm) {
	
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &other) {
	o << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (o);
}
