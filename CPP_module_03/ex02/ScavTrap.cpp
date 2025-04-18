
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Scavtrap default constructor is called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor is called!" << std::endl;
}

ScavTrap::~ScavTrap() {	
	std::cout << "ScavTrap " << this->name << " is destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap Copy assignment operator called." << std::endl;
    return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		this->energyPoints--;
		std::cout << "ScavTrap " << this->name << " attacked " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << this->name << " is low on points!" << std::endl;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << " ScavTrap " << this->name << "is now in Gate keeper mode." << std::endl;
}

