#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(const std::string &name) : name(name) {}

void	HumanB::setWeapon(Weapon &theWeapon) {
	weapon = &theWeapon;
}

void	HumanB::attack(void) const {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << '\n';	
}
