#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> *array1 = new Array<int>(5);
	Array<float> *array2 = new Array<float>(5);
	std::string name = "ABCDE";
	Array<char> *array3 = new Array<char>(name.length());

	for (unsigned int i = 0; i < array1->size(); i++)
		array1->setElem((i + i), i);
	std::cout << "Array 1:\n\t";
	std::cout << *array1;
	
	for (unsigned int i = 0; i < array2->size(); i++)
		array2->setElem(i + 0.5, i);
	std::cout << "Array 2:\n\t";
	std::cout << *array2;
	
	for (unsigned int i = 0; i < array3->size(); i++)
		array3->setElem(name[i], i);
	std::cout << "Array 3:\n\t";
	std::cout << *array3;

	Array<char> *copyArray1 = new Array<char>();
	*copyArray1 = *array3;
	copyArray1->setElem('Q', 2);
	std::cout << "Copy Array 1:\n\t";
	std::cout << *copyArray1;
	std::cout << "Array 3:\n\t";
	std::cout << *array3;


	Array<float> *copyArray2 = new Array<float>(*array2);
	copyArray2->setElem(1337.42, 2);
	std::cout << "Copy Array 2:\n\t";
	std::cout << *copyArray2;
	std::cout << "Array 2:\n\t";
	std::cout << *array2;

	try {
		copyArray2->setElem(404, 666);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete array1;
	delete array2;
	delete array3;
	delete copyArray1;
	delete copyArray2;

	return (0);
}
