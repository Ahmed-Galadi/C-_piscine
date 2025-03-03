
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"
#include <cstring>
#include <sstream>
#include <readline/readline.h>
#include <readline/history.h>

PhoneBook::PhoneBook() : contactCount(0) {

}

void PhoneBook::addContact() {
	int current_index = contactCount % MAX_CONTACTS;

	contacts[current_index].setData(current_index);
	if (contacts[current_index].getFirstName() == "" 
		|| contacts[current_index].getLastName() == ""
		|| contacts[current_index].getNickName() == ""
		|| contacts[current_index].getPoneNumber() == ""
		|| contacts[current_index].getDark() == "")
		return ;
	contactCount++;
}

void PhoneBook::printFirstColumn() {
	std::cout << "\e[0m\n\n┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|   \e[33m  index|\e[32mfirst name| \e[31mlast name|  \e[35mnickname\e[0m|" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
}

std::string PhoneBook::formatStr(const std::string str)
{
	std::string output;

	if (str.length() >= 10)
		output = str.substr(0, 9) + '.';
	else
		output = std::string(10 - str.length(), ' ') + str ;
	return (output);
}

std::string PhoneBook::itoa(int nbr) {
	std::stringstream ss;
    
	ss << nbr;                     // Insert number into stream
    std::string str_nbr = ss.str();
	return (str_nbr);
}

void PhoneBook::searchContact()
{
	
	int contact_index = -1;
	char *input;

	if (!contactCount)
	{
	    std::cout << "\e[0m\n\n\033[1;36m┌──────────────────────────────────────────────┐\033[0m" << std::endl;
		std::cout << "\033[1;36m│                                              │\033[0m" << std::endl;
		std::cout << "\033[1;36m│\033[1;31m              No contacts found!              \033[1;36m│\033[0m" << std::endl;
		std::cout << "\033[1;36m│                                              │\033[0m" << std::endl;
		std::cout << "\033[1;36m│\033[1;33m                   (｡•́︿•̀｡)                   \033[1;36m│\033[0m" << std::endl;
		std::cout << "\033[1;36m│                                              │\033[0m" << std::endl;
		std::cout << "\033[1;36m└──────────────────────────────────────────────┘\033[0m\n\n" << std::endl;
		return ;
	}
	input = readline("\n\nEnter Index of the Wanted Contact: ");
	if (!input)
		return ;
	if (strlen(input) > 1)
	{
		std::cout << "\n\n\e[1;31m Contact Not Found !\e[1;0m\n\n" << std::endl;
		return ;
	}
	contact_index = atoi(input);
	if (contact_index <= contactCount-1)	
		contacts[contact_index].print_info();
	else
		std::cout << "\n\n\e[1;31m Contact Not Found !\e[1;0m\n\n" << std::endl;
	free(input);
}

void PhoneBook::displayContacts() {
	
	if (contactCount)
		printFirstColumn();
	for (int i = 0; i < contactCount; i++)
	{
		if (i == MAX_CONTACTS)
			break ;
		if (!contactCount)
			return ;
		std::cout << '|' + PhoneBook::formatStr(PhoneBook::itoa(contacts[i].getIndex()))
			<< '|' + PhoneBook::formatStr(contacts[i].getFirstName())
			<< '|' + PhoneBook::formatStr(contacts[i].getLastName())
			<< '|' + PhoneBook::formatStr(contacts[i].getNickName()) + '|'
			<< std::endl;
	}
	searchContact();
}
