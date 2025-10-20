#include "easyfind.hpp"
#include <iostream>

int main() {
	std::vector<int> 	numbers;
	int 				position;
	int 				tofind = 16;

	for (unsigned int i = 0; i < 10; i++)
		numbers.push_back(i + i);
	
	std::cout << "[Int Vector] => ";
	for (int i = 0; i < 10; i++)
		std::cout << numbers[i] << ", ";
	std::cout << std::endl;

	position = easyfind(numbers, tofind);
	if (position == -1)
		std::cout << "Number Not Found!" << std::endl;
	else
		std::cout << "\tFound [" << tofind << "] at position => " << position << std::endl;
	return (0);
}