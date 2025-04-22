#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "|ClapTrap Parametrized Constructor called|" << std::endl;
	std::cout << "|ClapTrap " << this->name << " is created|" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) {
	std::cout << "ClapTrap copy constructor of " << this->name << " is called!" << std::endl;
   *this = source; 
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
};

ClapTrap	&ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap" << this->name << " the assignment operator overload is called!" << std::endl;
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
		std::cout << "\e[31mClapTrap " << this->name << " attacked " << target << " causing " << this->attackDamage << " points of damage!\e[0m" << std::endl;
	} else {
		std::cout << "\e[31mClapTrap " << this->name << " is low on points or dead!\e[0m" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > 0)
	{
		if (this->hitPoints <= amount)
			this->hitPoints = 0;
		else
			this->hitPoints -= amount;
		std::cout << "\e[31mClapTrap " << this->name << " got " << amount << " points of damage!\e[0m" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "\e[32mClapTrap " << this->name << " repaired " << amount << " health points!\e[0m" << std::endl; 
	} else {
		std::cout << "\e[31mClapTrap " << this->name << " is low on points or dead!\e[0m" << std::endl;
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
