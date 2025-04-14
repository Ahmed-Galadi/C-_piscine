#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string &name);
		
		void attack(void) const;
		void setWeapon(Weapon &theWeapon);
	private:
		std::string name;
		Weapon		*weapon;
};

#endif
