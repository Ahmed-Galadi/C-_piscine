
#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor is called!" << std::endl;
}



Animal::Animal(const Animal &other) {
	this->type = other.type;
	std::cerr << this->type <<" copy constructor called!" << std::endl;
}


Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal assignment operator is called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal is destroyed" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "* Some generic animal sound *" << std::endl;
}


std::string Animal::getType() const { 
	return (type);
}
