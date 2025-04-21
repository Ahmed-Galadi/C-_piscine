#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "bright-idea";
	std::cout << "Brain Constructor is Called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain is Destroyed" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor is called!";
}

Brain &Brain::operator=(Brain const &other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

