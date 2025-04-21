#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongCat copy assignment operator is Called!" << std::endl;
    return (*this);
}



WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat copy construtor is Called!" << std::endl;
}


WrongCat::~WrongCat() {
	std::cout << "WrongCat is destroyed!" << std::endl;
}


void WrongCat::makeSound() const {
	std::cout << "wrong-miaw-miaw" << std::endl;
}
