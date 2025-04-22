
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor is called!" << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    *this = other;
    std::cout << "WrongAnimal copy constructor is called!" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != & other) {
        this->type = other.type;
    }
	std::cout << "WrongAnimal copy assignement operator is called!" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal is destroyed!" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "# This is WrongAnimal sound! #" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (type);
}