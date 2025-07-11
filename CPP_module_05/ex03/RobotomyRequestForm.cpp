#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("[Default]", 72, 45), target("[default]") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &initTarget) : AForm(initTarget, 72, 45), target(initTarget) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		this->target = other.target;
		this->setIsSigned(other.isFormSigned());
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm [" << this->target << "] is Destroyed!\n";
}

const char *RobotomyRequestForm::FailedRobotomyExeption::what() const throw() {
	return ("robotomy failed");
}

void RobotomyRequestForm::execForm(const Bureaucrat &executor) const {
	std::srand(std::time(0));
	
	std::cout << "* Driling noise *\n";
	if (!(std::rand() % 2))
		throw RobotomyRequestForm::FailedRobotomyExeption();
	std::cout << "    ·___·\n\
   |o   o|\n\
    \\ ' /\n\
     |¯| \n\
/¯|¯¯¯|¯ ¯|¯\\\n\
| |___|___| |\n\
| |\\__|__/| |\n\
|_| |_|_| |_|\n\
 ¥  |_|_|  ¥\n\
  /¯|···|¯\\\n\
  | |   | |\n\
  |_|   |_|\n\
  |¯|   |¯|\n\
  | |   | |\n\
  |_|   |_|\n\
  / \\   / \\\n\
 (>.<) (>.<)\n\
Robotomized Successfully By ==> " << executor.getName() << std::endl;
}
