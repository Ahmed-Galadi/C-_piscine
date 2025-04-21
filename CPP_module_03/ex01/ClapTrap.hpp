#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
	public:
		ClapTrap(); 
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &source);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int getHitPoints() const;
		int getEnergyPoints() const;
		int	getAttackDamage() const;
		std::string getName() const;
};

#endif
