#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(const std::string &name,  Weapon &weapon) 
	: name(name), weapon(weapon) {}

void	HumanA::attack(void) const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;	
}
