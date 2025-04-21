#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != & other)
        this->type = other.type;
    return (*this);
}



Dog::Dog(const Dog & other) : Animal(other) {
	std::cout << "Dog copy construtor is Called!" << std::endl;
}


Dog::~Dog() {
	std::cout << "Dog is destroyed!" << std::endl;
}


void Dog::makeSound() const {
	std::cout << "Wof-wof" << std::endl;
}
