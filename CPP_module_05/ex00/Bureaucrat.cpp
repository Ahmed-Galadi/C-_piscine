
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("no_name"), grade(150) {
}

Bureaucrat::Bureaucrat(const std::string &initName,	int initGrade) : name(initName) {
	if (initGrade > 150)
		throw GradeTooLowException();
	if (initGrade < 1)
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
	return ("\e[31mGrade is too Low!\e[0m");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("\e[33mGrade is too Hight!\e[0m");
}

void	Bureaucrat::incBGrade() {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void	Bureaucrat::decBGrade() {
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &other) {
	o << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (o);
}
