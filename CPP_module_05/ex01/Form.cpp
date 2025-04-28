
#include "Form.hpp"

std::ostream &operator<<(std::ostream &o, const Form &other) {
	o << "Form Named " << other.getName() << " Require Grade " << other.getSignGrade() << " to be Signed and Grade " << other.getExecuteGrade() << " to be Executed!!\n";
	return (o);
}
