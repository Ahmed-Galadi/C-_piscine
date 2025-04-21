#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string	ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &ref);
		Brain &operator=(Brain const &rhs);
};

#endif
