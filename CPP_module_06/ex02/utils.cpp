
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "exception"

int randomIndex() {
	int randomNum;

	std::srand(std::time(NULL));
	randomNum = std::rand() % 3;
	return (randomNum);
}

Base *generate() {
	unsigned int random =  randomIndex();

	if (random == 1)
		return (new A());
	if (random == 2)
		return (new B());
	return (new C());
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type is \"A*\"\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is \"B*\"\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is \"C*\"\n";
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type is \"A&\"\n";
	} catch (const std::exception &) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "Type is \"B&\"\n";
		} catch (const std::exception &) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "Type is \"C&\"\n";
			} catch (const std::exception &) {}
		}
	}
}

