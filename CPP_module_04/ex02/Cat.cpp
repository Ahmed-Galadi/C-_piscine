#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        this->type = other.type;
		this->brain = other.brain;
	} 
    std::cout << "Cat copy assignment operator is Called!" << std::endl;
    return (*this);
}



Cat::Cat(const Cat &other) : Animal(other) {
	this->brain = other.brain;
	std::cout << "Cat copy construtor is Called!" << std::endl;
}


Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat is destroyed!" << std::endl;
}


void Cat::makeSound() const {
	std::cout << "Miaw-miaw" << std::endl;
}
