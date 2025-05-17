
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("no_name"), grade(150) {
	std::cout << "Constructing Bureaucrat " << this->name << '\n';
}

Bureaucrat::Bureaucrat(const std::string &initName,	int initGrade) : name(initName) {
	this->grade = initGrade;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Constructing Bureaucrat " << this->name << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) {
	*this = other;
	std::cout << "Constructer Copy Bureaucrat " << other.name << " to " << this->name << '\n';
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::string oldName = this->name;
	if (this != &other) 
		this->grade = other.grade;
	std::cout << "Assignement Operator Copied Bureaucrat " << other.name << " to " << oldName << '\n';
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructing Bureaucrat " << this->name << '\n';
}

const std::string &Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("\e[31mBureaucrat Grade is too Low!\e[0m");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("\e[33mBureaucrat Grade is too Hight!\e[0m");
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

void	Bureaucrat::signForm(AForm &toSignForm) {
	try {
		toSignForm.beSigned(*this);
	} catch (const AForm::gradeTooLowException &e) {
		std::cout << ' ' << this->name << " couldn't sign Form " << toSignForm.getName() << " Because, " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &other) {
	o << " " << other.getName() << ", bureaucrat grade " << other.getGrade() << '\n';
	return (o);
}
