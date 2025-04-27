

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat x("Bereaucrat Number 1", 1);

	std::cout << x << '\n';
	x.decBGrade();
	std::cout << x << '\n';
	x.incBGrade();
	std::cout << x << '\n';
	try {
		x.incBGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &exp) {
		std::cout << exp.what() << std::endl;
	}
	Bureaucrat y("Bureaucrat Number 2", 150);
	std::cout << y << '\n';
	y.incBGrade();
	std::cout << y << '\n';
	y.decBGrade();
	std::cout << y << '\n';

	try {
		y.decBGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &exp) {
		std::cout << exp.what() << std::endl;
	}
	return (0);
}
