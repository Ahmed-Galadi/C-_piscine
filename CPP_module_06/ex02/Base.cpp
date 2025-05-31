
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
	std::srand(std::time(NULL));
	unsigned int random = std::rand() % 3;

	if (random == 1)
		return (new A());
	if (random == 2)
		return (new B());
	return (new C());
}

void	identify(Base *p) {

}
