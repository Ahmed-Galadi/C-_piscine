
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
    std::cout << "|ScavTrap Parametrized Constructor called|" << std::endl;
	std::cout << "|ScavTrap " << this->name << " is created|" << std::endl;
}

ScavTrap::~ScavTrap() {	
	std::cout << "ScavTrap " << this->name << " is destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap Copy assignment operator called!" << std::endl;
    return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		this->energyPoints--;
		std::cout << "\e[38;5;208mScavTrap " << this->name << " attacked " << target << " causing " << this->attackDamage << " points of damage!\e[0m" << std::endl;
	} else {
		std::cout << "\e[38;5;208mScavTrap " << this->name << " is low on points!\e[0m" << std::endl;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << "\e[36m\e[1mScavTrap " << this->name << " is now in Gate keeper mode.\e[0m" << std::endl;
}

