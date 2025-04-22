#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
        std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "|ClapTrap Parametrized Constructor called|" << std::endl;
	std::cout << "|ClapTrap " << this->name << " is created|" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) {
	std::cout << "ClapTrap Copy constructor of " << this->name << " has been called!" << std::endl;
   *this = source; 
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
};

ClapTrap	&ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap" << this->name << " called the assignment operator overload!" << std::endl;
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
	else
		std::cout << "ClapTrap is out of energy or already dead\n";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > 0)
	{
		if (this->hitPoints <= amount)
			this->hitPoints = 0;
		else
			this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " got " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap is out of energy or already dead\n";
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " repaired " << amount << " health points!" << std::endl; 
	}
	else
		std::cout << "ClapTrap is out of energy or already dead\n";
}
