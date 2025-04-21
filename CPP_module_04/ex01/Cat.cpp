#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) 
        this->type = other.type;
    std::cout << "Cat copy assignment operator is Called!" << std::endl;
    return (*this);
}



Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy construtor is Called!" << std::endl;
}


Cat::~Cat() {
	std::cout << "Cat is destroyed!" << std::endl;
}


void Cat::makeSound() const {
	std::cout << "Miaw-miaw" << std::endl;
}
