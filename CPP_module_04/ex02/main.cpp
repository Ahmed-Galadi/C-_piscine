
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>

int leaksCheck()
{
	std::cout << "\e[34m---------------------------------" << std::endl;
	if (std::getenv("THINKINGZOO_VALGRIND") == NULL)
	{
		system("THINKINGZOO_VALGRIND=1 valgrind ./thinkingZoo");
		std::cout << "---------------------------------\e[0m" << std::endl;
		return (0);
	}
	return (0);
}

int main( void )
{
	std::cout << "\e[33m---------------------------------" << std::endl;
	std::cout << "-        EXERCICE EXAMPLE       -" << std::endl;	
	std::cout << "---------------------------------\e[0m" << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;
	delete dog;
	delete cat;

	const Animal	*animal_array[10];
	std::cout << std::endl;

	std::cout << "\e[32m---------------------------------" << std::endl;
	std::cout << "-          DOG CREATION         -" << std::endl;
	std::cout << "---------------------------------\e[0m" << std::endl;
	for (int i = 0; i < 5; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;
	std::cout << "\e[32m---------------------------------" << std::endl;
	std::cout << "-          CAT CREATION         -" << std::endl;
	std::cout << "---------------------------------\e[0m" << std::endl;
	for (int i = 5; i < 10; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;
	std::cout << "\e[31m---------------------------------" << std::endl;
	std::cout << "-       DESTRUCTION START       -" << std::endl;
	std::cout << "---------------------------------\e[0m" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animal_array[i];
	std::cout << std::endl;
	// return (leaksCheck());
}
