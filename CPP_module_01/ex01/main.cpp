
#include "Zombie.hpp"

int main(void)
{
	Zombie *pointer = zombieHorde(10, "zombie");
	
	pointer->announce();
	delete(pointer);
	return (0);
}
