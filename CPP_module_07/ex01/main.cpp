

#include "Iter.hpp"

int main()
{
	int	arrInt[] = {1, 2, 3, 4};
	iter<int>(arrInt, 4, elementPlusTwo<int>);
	printArr<int>(arrInt);

	double arrDouble[] = {1.1, 1.2, 1.3, 1.4};
	iter<double>(arrDouble, 4, elementPlusTwo<double>);
	printArr<double>(arrDouble);

	char str[] = {'a', 'b', 'c', 'd'};
	iter<char>(str, 4, elementPlusTwo<char>);
	printArr(str);
	
	const char constStr[] = {'a', 'b', 'c', 'd'};
	iter<const char>(constStr, 4, elementPlusTwo<const char>);
	printArr(constStr);
	
	return (0);
}
