#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &initTarget);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void execForm(const Bureaucrat &executor) const;
		
		class FailedRobotomyExeption : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};


#endif
