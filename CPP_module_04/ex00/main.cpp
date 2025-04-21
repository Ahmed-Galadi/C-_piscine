
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
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
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << std::endl;
	wrong_cat->makeSound(); // worng cat sound!
	wrong_animal->makeSound(); // wrong animal sound!

	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrong_cat;
	delete wrong_animal;
}
