#include "Bureaucrat.hpp"
#include "Form.hpp"


Form::Form() : name("no_name"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "Constructing Form " << this->name << '\n';
}

Form::Form(const std::string &initName, const int initGradeSgn, const int initGradeExec) : name(initName), gradeToSign(initGradeSgn), gradeToExecute(initGradeExec) {
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw gradeTooHighException();
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw gradeTooLowException();
	std::cout << "Constructing Form " << this->name << '\n';
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	*this = other;
	std::cout << "Copy Constructor of Form " << this->name << " is Called!" << '\n';
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "Assignment Operator Copied Form" << this->name << '\n'; 
	return (*this);
}

Form::~Form() {
	std::cout << "Destructing Form " << this->name << '\n';
}

std::string Form::getName() const {
	return (this->name);
}

int Form::getSignGrade() const {
	return (this->gradeToExecute);
}

int Form::getExecuteGrade() const {
	return (this->gradeToExecute);
} 

bool Form::isFormSigned() const {
	return (this->isSigned);
}

const char *Form::gradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char *Form::gradeTooLowException::what() const throw() {
	return ("Grade is too Low!");
}
 
void Form::beSigned(Bureaucrat &whoSign) {
	if (whoSign.getGrade() > this->gradeToSign)
		throw gradeTooLowException();
	this->isSigned = true;
	std::cout << " Bureaucrat " << whoSign.getName() << " signed Form " << this->getName() << '\n'; 
}

std::ostream &operator<<(std::ostream &o, const Form &other) {
	o << " Form Named " << other.getName() << " Require Grade " << other.getSignGrade() << " to be Signed and Grade " << other.getExecuteGrade() << " to be Executed!!\n";
	return (o);
}
