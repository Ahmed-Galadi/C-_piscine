#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		static const bool access;
		const std::string target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &initTarget);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
};


#endif
