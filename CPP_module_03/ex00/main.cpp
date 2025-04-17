
#include "ClapTap.hpp"

int main() {
    ClapTap bot("Clappy");
    bot.attack("target dummy");
    bot.takeDamage(5);
    bot.beRepaired(3);
    return 0;
}
