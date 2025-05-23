#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern is Created !\n";
}

Intern::~Intern() {
	std::cout << "Intern is Destroyed !\n";
}

AForm	*Intern::makeShrubberyCreationForm(const std::string &formName) const {
	return (new ShrubberyCreationForm(formName));
}

AForm	*Intern::makeRobotomyRequestForm(const std::string &formName) const {
	return (new RobotomyRequestForm(formName));
}

AForm	*Intern::makePresidentialPardonForm(const std::string &formName) const {
	return (new PresidentialPardonForm(formName));
}

const char *Intern::InternCantCreate::what() const throw() {
	return ("Intern Can't Create Form !");
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formType) const {

	const std::string types[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(Intern::*formTypes[3])(const std::string&) const = {
				&Intern::makeShrubberyCreationForm,
					&Intern::makeRobotomyRequestForm,
						&Intern::makePresidentialPardonForm
	};

	for (unsigned int i = 0; i < 3; i++) {
		if (formType == types[i])
		{
			std::cout << "Intern Creates Form " << formName << std::endl;
			return (this->*formTypes[i])(formName);
		}
	}
	throw InternCantCreate();
}
