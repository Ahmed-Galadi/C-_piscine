#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data *someData = new Data(1, "[some_Data]");

	std::cout << *someData << std::endl;

	std::cout << "Data Address ======> " << someData << std::endl;
	std::cout << "Serialized Data ======> " << Serializer::serialize(someData) << std::endl;
	std::cout << "Deserialized Data ======> " << Serializer::deserialize(Serializer::serialize(someData)) << std::endl;
	std::cout << *someData << std::endl;

	delete someData;
	return (0);
}
