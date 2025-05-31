#include <ostream>
#include "Data.hpp"
#include <string>

Data::Data() : id(-1), name("Default") {}

Data::Data(int initId, const std::string &initName) : id(initId), name(initName) {}

Data::Data(const Data &other) {
	*this = other;
}

Data &Data::operator=(const Data &other) {
	if (this != &other) {
		this->setId(other.id);
		this->setName(other.name);
	}
	return (*this);
}

int	Data::getId() const {
	return (this->id);
}

std::string Data::getName() const {
	return (this->name);
}

void Data::setId(int intToSet) {
	this->id = intToSet;
}

void Data::setName(const std::string &nameToSet) {
	this->name = nameToSet;
}

std::ostream &operator<<(std::ostream &o, const Data &obj) {
	o << "Id: " << obj.getId() << " ============> " << "name: " << obj.getName() << std::endl;
	return (o);
}
