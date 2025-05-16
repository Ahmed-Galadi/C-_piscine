#include "Bureaucrat.hpp"
#include "AForm.hpp"


AForm::AForm() : name("no_name"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "Constructing Form " << this->name << '\n';
}

AForm::AForm(const std::string &initName, const int initGradeSgn, const int initGradeExec) : name(initName), gradeToSign(initGradeSgn), gradeToExecute(initGradeExec) {
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw gradeTooHighException();
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw gradeTooLowException();
	std::cout << "Constructing Form " << this->name << '\n';
}

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	*this = other;
	std::cout << "Copy Constructor of Form " << this->name << " is Called!" << '\n';
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "Assignment Operator Copied AForm" << this->name << '\n'; 
	return (*this);
}

AForm::~AForm() {
	std::cout << "Destructing Form " << this->name << '\n';
}

std::string AForm::getName() const {
	return (this->name);
}

int AForm::getSignGrade() const {
	return (this->gradeToExecute);
}

int AForm::getExecuteGrade() const {
	return (this->gradeToExecute);
} 

bool AForm::isFormSigned() const {
	return (this->isSigned);
}

const char *AForm::gradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char *AForm::gradeTooLowException::what() const throw() {
	return ("Grade is too Low!");
}
 
void AForm::beSigned(Bureaucrat &whoSign) {
	if (whoSign.getGrade() > this->gradeToSign)
		throw gradeTooLowException();
	this->isSigned = true;
	std::cout << " Bureaucrat " << whoSign.getName() << " signed Form " << this->getName() << '\n'; 
}

std::ostream &operator<<(std::ostream &o, const AForm &other) {
	o << " Form Named " << other.getName() << " Require Grade " << other.getSignGrade() << " to be Signed and Grade " << other.getExecuteGrade() << " to be Executed!!\n";
	return (o);
}
