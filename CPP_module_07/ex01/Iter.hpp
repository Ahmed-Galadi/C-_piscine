
#pragma once

#include <iostream>

template<typename T>
void	iter(T *array, int length, void (*function)(T &)) {
for (int i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void iter(const T* array, int length, void (*function)(const T&)) {
	for (int i = 0; i < length; i++)
		function(array[i]);
}

template<typename T>
void	elementPlusTwo(T &elem) {
	elem += 2;
}

template<typename T>
void	printArr(T *arr) {
	for (int i = 0; i < 4; i++)
		std::cout << arr[i] << ", ";
	std::cout << std::endl;
}
