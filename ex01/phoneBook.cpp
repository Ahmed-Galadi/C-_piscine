
#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"
#include <cstring>
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0) {

}

void PhoneBook::addContact() {
	int current_index = contactCount % MAX_CONTACTS;

	contacts[current_index].setData(current_index);
	contactCount++;
}

void PhoneBook::printFirstColumn() {
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
}

std::string PhoneBook::formatStr(const std::string str)
{
	std::string output;

	if (str.length() >= 10)
		output = str.substr(0, 9) + '.' + '|';
	else
		output = std::string(10 - str.length(), ' ') + str + '|';
	return (output);
}

std::string PhoneBook::itoa(int nbr) {
	std::stringstream ss;
    
	ss << nbr;                     // Insert number into stream
    std::string str_nbr = ss.str();
	return (str_nbr);
}

void PhoneBook::searchContact() {
	printFirstColumn();
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << PhoneBook::formatStr(PhoneBook::itoa(contacts[i].getIndex()))
			<< PhoneBook::formatStr(contacts[i].getFirstName())
			<< PhoneBook::formatStr(contacts[i].getLastName())
			<< PhoneBook::formatStr(contacts[i].getNickName())
			<< std::endl;
	}
}

