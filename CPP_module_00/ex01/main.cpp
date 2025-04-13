
#include "PhoneBook.class.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>


int main(void)
{
	PhoneBook phoneBook;
	std::string command;
	
	while (1)
	{	
		std::cout << "\n\n\e[1;35mEnter one of the 3 commands:\e[0m\
			\n\t\e[1;32mADD :\e[0m to add a contact.\
			\n\t\e[1;36mSEARCH :\e[0m to search in the contact list.\
			\n\t\e[1;93mEXIT :\e[0m to exit the programe.\n\033[38;5;46m▶\033[1;38;5;226m ";
		getline(std::cin, command, '\n');
		if (std::cin.eof())
			return (0);
		if (command.empty())
			return (EXIT_FAILURE);
		if (!command.compare("ADD"))
			phoneBook.addContact();
		else if (!command.compare("SEARCH"))
			phoneBook.displayContacts();
		else if (!command.compare("EXIT"))
			return (EXIT_SUCCESS);
		else {
			std::cout << "\e[0;31m" << std::endl;
			std::cout << "┓ ┏          ┏┓             ┓  ╻" << std::endl;
			std::cout << "┃┃┃┏┓┏┓┏┓┏┓  ┃ ┏┓┏┳┓┏┳┓┏┓┏┓┏┫  ┃" << std::endl;
			std::cout << "┗┻┛┛ ┗┛┛┗┗┫  ┗┛┗┛┛┗┗┛┗┗┗┻┛┗┗┻  •" << std::endl;
			std::cout << "          ┛                     " << std::endl;
			std::cout << "\e[0m" << std::endl;
		}
	}
	return (0);
}

