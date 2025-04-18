#include "Weapon.hpp"
#include <string>

Weapon::Weapon(const std::string &type) : type(type) {}

const std::string& Weapon::getType(void) const {
	return (type);
}

void	Weapon::setType(std::string weaponName) {
	this->type = weaponName;
}
