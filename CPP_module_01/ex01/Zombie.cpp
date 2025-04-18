
#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie() {}
Zombie::Zombie(const std::string &name) : name(name) {}
Zombie::~Zombie() {
	std::cout << name << " is destroyed!" << std::endl;
}

void Zombie::setName(std::string &name) {
	this->name = name;
}

void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


