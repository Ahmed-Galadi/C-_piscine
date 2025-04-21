
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <ostream>

void	displayStatus(const ClapTrap &character) {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Name          || " << character.getName() << std::endl;
	std::cout << "Hit Points    || " << character.getHitPoints() << std::endl;
	std::cout << "Energy Points || " << character.getEnergyPoints() << std::endl;
	std::cout << "-----------------------------" << std::endl;
}
int main() {
	std::string	playerName	  = "*Hero*";
	std::string	enemyName	  = "<Bad Guy>";
	std::string	sideCharacter = "(side character)";

    ClapTrap	player(playerName);
    ScavTrap	enemy(enemyName);
	FragTrap	sideChar(sideCharacter);


	displayStatus(enemy);
	displayStatus(player);
	displayStatus(sideCharacter);

    player.attack(enemyName);
	enemy.takeDamage(player.getAttackDamage());
    
	displayStatus(enemy);
	displayStatus(player);

    player.beRepaired(5);
    displayStatus(player);

    enemy.attack(playerName);
    player.takeDamage(enemy.getAttackDamage());
    
	displayStatus(player);
	displayStatus(enemy);

    enemy.beRepaired(10);
	displayStatus(enemy);

    enemy.guardGate();
	sideChar.attack(enemyName);
	enemy.takeDamage(sideChar.getAttackDamage());
	displayStatus(enemy);
	displayStatus(sideChar);
	sideChar.highFivesGuys();

    return 0;
}
