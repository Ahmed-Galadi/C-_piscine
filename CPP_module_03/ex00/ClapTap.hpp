#ifndef CLAPTAP_HPP
# define CLAPTAP_HPP

#include <iostream>
#include <string>

class ClapTap {
	private:
		std::string name;
		int			hitPoints = 10;
		int			energyPoints = 10;
		int			attackDamage = 0;

	public:
		ClapTap(const std::string &name);
		ClapTap(const ClapTap &source);
		ClapTap &operator=(const ClapTap &other);
		~ClapTap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
