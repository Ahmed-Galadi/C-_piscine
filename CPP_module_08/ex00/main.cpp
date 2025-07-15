#include "easyfind.hpp"
#include <iostream>

int main() {
	std::vector<int> numbers;

	for (unsigned int i = 0; i < 10; i++)
		numbers.push_back(i + i);
	
	for (int i = 0; i < 10; i++)
		std::cout << numbers[i] << ", ";
	std::cout << std::endl;
	return (0);
}