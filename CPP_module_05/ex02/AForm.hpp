#ifndef AFORM_HPP
#define AFORM_HPP


#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		AForm();
		AForm(const std::string &initName, const int initGradeSgn, const int initGradeExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

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

std::ostream &operator<<(std::ostream &o, const AForm &other);

#endif
