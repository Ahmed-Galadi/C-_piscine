
#include "PhoneBook.class.hpp"
#include <cstdlib>
#include <iostream>


int main(void)
{
	PhoneBook phoneBook;
	
	while (1)
	{
		std::string command;
		
		std::cout << "\e[5mEnter one of the 3 commands:\e[0m\
			\n\t\e[1;32mADD :\e[0m to add a contact.\
			\n\t\e[1;36mSEARCH :\e[0m to search in the contact list.\
			\n\t\e[1;93mEXIT :\e[0m to exit the programe." << std::endl;
		std::cin >> command;

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			return (EXIT_SUCCESS);
		else {
			std::cout << "\033[0;31m" << std::endl;
			std::cout << "┓ ┏          ┏┓             ┓  ╻" << std::endl;
			std::cout << "┃┃┃┏┓┏┓┏┓┏┓  ┃ ┏┓┏┳┓┏┳┓┏┓┏┓┏┫  ┃" << std::endl;
			std::cout << "┗┻┛┛ ┗┛┛┗┗┫  ┗┛┗┛┛┗┗┛┗┗┗┻┛┗┗┻  •" << std::endl;
			std::cout << "          ┛                     " << std::endl;
			std::cout << "\e[0m" << std::endl;
		}
	}
	return (0);
}

