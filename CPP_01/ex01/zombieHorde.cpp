
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *output_zombie = newZombie(name);
	Zombie *zombies;
	
	if (N <= 0)
		return (NULL);
	else if (N == 1)
		return (output_zombie);
	for (int i = 0; i < N - 1; i++)
	{
		zombies = newZombie(name);
		delete(zombies);
	}
	return (output_zombie);
}
