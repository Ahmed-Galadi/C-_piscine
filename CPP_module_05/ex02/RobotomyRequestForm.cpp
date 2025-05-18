#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("[Default]", 72, 45), target("[default]") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &initTarget) : AForm(initTarget, 72, 45), target(initTarget) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		this->target = other.target;
		this->setIsSigned(other.isFormSigned());
	}
	return (*this);
}
