#ifndef INTERN_HPP
# define INTERN_HPP

/*#pragma once*/

#include "AForm.hpp"

class Intern {
	private:
		AForm	*makeShrubberyCreationForm(const std::string &formName) const;
		AForm	*makeRobotomyRequestForm(const std::string &formName) const;
		AForm	*makePresidentialPardonForm(const std::string &formName) const;

	public:
		Intern();
		~Intern();

		AForm	*makeForm(const std::string &formName, const std::string &formType) const;
		
		class InternCantCreate : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
