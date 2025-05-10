#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		Form();
		Form(const std::string &initName, const int initGradeSgn, const int initGradeExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		bool		isFormSigned() const;
		
		void		beSigned(Bureaucrat &whoSign);
		
		class gradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class gradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Form &other);

#endif
