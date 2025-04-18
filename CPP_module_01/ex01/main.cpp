
#include "Zombie.hpp"

int main(void)
{
	int zombieNbr = 10;
	Zombie *pointer = zombieHorde(zombieNbr, "zombie");
	
	for(int i = 0; i < zombieNbr;i++)
		pointer[i].announce();
	delete[] (pointer);
	return (0);
}
