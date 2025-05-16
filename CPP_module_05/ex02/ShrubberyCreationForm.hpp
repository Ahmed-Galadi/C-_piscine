#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		static const std::string ASCII_TREE;
	public:
		~ShrubberyCreationForm();
		
		void execute(const Bureaucrat &executor) const;
		
		class ExecException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
