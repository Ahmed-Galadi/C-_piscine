#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) {
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other) {
	return (*this);
}

Serializer::~Serializer() {}
