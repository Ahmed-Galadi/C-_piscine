#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "includes.h"

class Bureaucrat {
	private:
		const	std::string name;
		int		grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		// functions
		const std::string	&getName() const;
		int					getGrade() const;
		void				incBGrade();
		void				decBGrade();
		// exceptions
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		void	signForm(Form &toSignForm);
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &other);

#endif
