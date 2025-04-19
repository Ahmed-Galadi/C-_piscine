
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	
	if (N <= 0)
		return (NULL);
	Zombie *output_zombie = new Zombie[N];
	for (int i = 0; i < N ; i++)
		output_zombie[i].setName(name);
	return (output_zombie);
}
