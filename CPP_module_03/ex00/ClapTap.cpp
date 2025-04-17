#include "ClapTap.hpp"

ClapTap::ClapTap(const std::string &name) : name(name) {
	std::cout << "Claptap " << this->name << " is created!" << std::endl;
}

ClapTap::ClapTap(const ClapTap &source) {
	std::cout << "Copy constructor of " << this->name << " has been called!" << std::endl;
   *this = source; 
}

ClapTap::~ClapTap( void ) {
	std::cout << "Claptap " << this->name << " is destroyed!" << std::endl;
};

ClapTap	&ClapTap::operator=(const ClapTap& other) {
	std::cout << this->name << " called the assignment operator overload!" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

void	ClapTap::attack(const std::string &target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		this->energyPoints--;
		std::cout << "Claptap " << this->name << " attacked " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTap::takeDamage(unsigned int amount) {
	if (this->hitPoints > 0) {
		this->hitPoints -= amount;
		std::cout << "Claptap " << this->name << " got " << amount << " points of damage!" << std::endl;
	}
}

void	ClapTap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTap " << this->name << " repaired " << amount << " health points!" << std::endl; 
	}
}


