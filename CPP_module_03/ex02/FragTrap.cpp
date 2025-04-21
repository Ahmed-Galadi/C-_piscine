
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default Constructor is called!" << std::endl;
}


FragTrap::FragTrap(const std::string & name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor is called!" << std::endl;
}


FragTrap::FragTrap(const FragTrap & other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor is called!" << std::endl;
}


FragTrap & FragTrap::operator=(const FragTrap & other) {
    if (this != & other) 
        ClapTrap::operator=(other);
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return (*this);
}


FragTrap::~FragTrap() {
    std::cout << "FragTrap is destroyed!" << std::endl;
}


void FragTrap::attack(const std::string & target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "\e[33mFragtrap " << this->name << " attacked " << target << " causing " << this->attackDamage << " points of damage!\e[0m" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "\e[33mFragTrap " << this->name << " has not enough energy or is dead.\e[0m" << std::endl;
    }
}


void FragTrap::highFivesGuys(void) const {
    std::cout << "\e[35mFragtrap " << this->name << " wants to high-five you!\e[0m" << std::endl;
}
