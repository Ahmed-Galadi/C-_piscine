#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string name;
		int			hitPoints = 10;
		int			energyPoints = 10;
		int			attackDamage = 0;

	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &source);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
