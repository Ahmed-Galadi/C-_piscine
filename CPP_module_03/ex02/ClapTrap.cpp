#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) {
	std::cout << "ClapTap copy constructor of " << this->name << " has been called!" << std::endl;
   *this = source; 
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
};

ClapTrap	&ClapTrap::operator=(const ClapTrap& other) {
	std::cout << this->name << " called the assignment operator overload!" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " attacked " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > 0) {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " got " << amount << " points of damage!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " repaired " << amount << " health points!" << std::endl; 
	}
}

int ClapTrap::getHitPoints() const {
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints() const {
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage() const {
	return (this->attackDamage);
}

std::string ClapTrap::getName() const {
	return (this->name);
}
