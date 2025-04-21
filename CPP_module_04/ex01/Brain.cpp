#include "Brain.hpp"

Brain::Brain()
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "bright-idea";
	std::cout << "Brain Constructor is Called!" << std::endl;
}

Brain::~Brain()
{
	delete [] (this->ideas);
	std::cout << "Brain is Destroyed" << std::endl;
}

Brain::Brain(Brain &other)
{
	std::string *otherIdeas = other.getIdeas();
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = otherIdeas[i];
	std::cout << "Brain copy constructor is called!";
}

Brain &Brain::operator=(Brain const &other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

std::string *Brain::getIdeas()
{
	return (this->ideas);
}
