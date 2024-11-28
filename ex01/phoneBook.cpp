
#include <iostream>
#include "PhoneBook.class.hpp"

void PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickName, std::string number, std::string secret) {

	contacts[contactCount].setIndex(contactCount);
	contacts[contactCount].setName(firstName, lastName);
	contacts[contactCount].setPhoneNumber(nickName, number);
	contacts[contactCount].setSecret(secret);
	contactCount++;
}

