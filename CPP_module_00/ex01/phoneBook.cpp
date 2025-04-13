
#include <cctype>
#include <cstdlib>
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

bool PhoneBook::stoi(const std::string& str, int& out) {
    std::stringstream ss(str);
    ss >> out;
    return (!ss.fail() && ss.eof());
}

std::string PhoneBook::formatStr(const std::string str)
{
	std::string output;

	if (str.length() > 10)
		output = str.substr(0, 9) + '.';
	else
		output = std::string(10 - str.length(), ' ') + str ;
	return (output);
}

std::string PhoneBook::itoa(int nbr) {
	std::stringstream ss;
    
	
	// nsert number into stream
	ss << nbr;
    std::string str_nbr = ss.str();
	return (str_nbr);
}

void PhoneBook::searchContact()
{
	
	int contact_index = -1;
	std::string input;

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

	std::cout << "\n\nEnter Index of the Wanted Contact: ";
	std::getline(std::cin, input, '\n');
	if (std::cin.eof()) {
		std::cout << "\n    \e[93m𝙴𝙾𝙵 (𝙲𝚝𝚛𝚕 + 𝙳) 𝙳𝚎𝚝𝚎𝚌𝚝𝚎𝚍\n\e[95m◄ \e[91m░░░▒▒▓\e[31m 𝙴𝚇𝙸𝚃 𝙿𝚁𝙾𝙶𝚁𝙰𝙼𝙴 \e[91m▓▒▒░░░\e[95m ►\e[0m\n";
		exit(0);
	}
	if (input.length() > 1)
	{
		std::cout << "\n\n\e[1;31m Contact Not Found !\e[1;0m\n\n" << std::endl;
		return ;
	}
	if (!PhoneBook::stoi(input, contact_index))
		return ;
	if (contact_index <= contactCount-1)	
		contacts[contact_index].print_info();
	else
		std::cout << "\n\n\e[1;31m Contact Not Found !\e[1;0m\n\n" << std::endl;
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
