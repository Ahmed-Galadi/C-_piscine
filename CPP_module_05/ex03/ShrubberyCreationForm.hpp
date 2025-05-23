#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		static const std::string ASCII_TREE;
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &initTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		
		void execForm(const Bureaucrat &executor) const;
		
		class ExecOpenException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
