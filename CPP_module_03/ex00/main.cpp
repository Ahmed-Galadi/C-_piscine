
#include "ClapTrap.hpp"

int main() {
    ClapTrap bot("Clappy");
    bot.attack("target dummy");
    bot.takeDamage(5);
    bot.beRepaired(3);
    return 0;
}
