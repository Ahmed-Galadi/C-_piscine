
#include "Zombie.hpp"

int main(void)
{
	Zombie *pointer = newZombie("zombie_man");

	pointer->announce();
	randomChump("zombie_woman");
	delete(pointer);
	return (0);
}
