
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
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
	std::cout << "\e[32m---------------------------------" << std::endl;
	std::cout << "-     DOG AND CAT CREATION      -" << std::endl;
	std::cout << "---------------------------------\e[0m" << std::endl;
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "Dog Type => " << dog->getType() << std::endl;
	std::cout << "Cat Type => " << cat->getType() << std::endl;
	cat->makeSound(); // cat sound!
	dog->makeSound(); // dog sound!
	animal->makeSound(); //animal sound!

	std::cout << std::endl;
	const WrongAnimal *wrong_animal = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();

	std::cout << std::endl;
	wrong_cat->makeSound(); // worng animal sound!
	wrong_animal->makeSound(); // wrong animal sound!

	std::cout << std::endl;
	std::cout << "\e[31m---------------------------------" << std::endl;
	std::cout << "-   DOG AND CAT DESTRUCTION     -" << std::endl;
	std::cout << "---------------------------------\e[0m" << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrong_cat;
	delete wrong_animal;
	std::cout << std::endl;
	std::cout << "\e[34m---------------------------------" << std::endl;
	if (std::getenv("ZOO_VALGRIND") == NULL)
	{
		system("ZOO_VALGRIND=1 valgrind ./Zoo");
		std::cout << "---------------------------------\e[0m" << std::endl;
		return 0;
	}
}
