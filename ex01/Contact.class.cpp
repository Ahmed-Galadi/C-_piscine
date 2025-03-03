

#include "Contact.class.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>



// contants
const char *Contact::input_msgs[5] = {
    "\e[0mEnter First Name: ",
	"\e[0mEnter Last Name: ",
	"\e[0mEnter Nickname: ",
	"\e[0mEnter Phone Number: ",
	"\e[0mEnter Darkest Secret: "
};

// setters
void	Contact::setData(int currentIndex) {
	char *input;

	index = currentIndex;
	for (int i = 0; i < 5; i++)
	{
		input = readline(input_msgs[i]);
		if (!input)
			return ;
		switch (i) {
			case 0: firstName = input; break;
			case 1: lastName = input; break;
			case 2: nickName = input; break;
			case 3: number = input; break;
			case 4: dark = input; break;
		}
		free(input);
	}
}

// getters

int Contact::getIndex() {
	return (index);
}

std::string Contact::getFirstName() {
	return (firstName);
}

std::string Contact::getLastName() {
	return (lastName);
}

std::string Contact::getPoneNumber() {
	return (number);
}

std::string Contact::getNickName() {
	return (nickName);
}

std::string Contact::getDark() {
	return (dark);
}

// function 
void	Contact::print_info()
{
	std::cout << "\e[0m\n\n\033[1;34m✦\tFirst Name\t✦ \033[1;38;5;226m• ───────────────── • \e[0m✦  " << getFirstName() + "\t✦ " << std::endl;
	std::cout << "\033[1;31m✦\tLast Name\t✦ \033[1;38;5;226m• ───────────────── • \e[0m✦  " << getLastName()  + "\t✦ " << std::endl;
	std::cout << "\033[1;35m✦\tNickname\t✦ \033[1;38;5;226m• ───────────────── • \e[0m✦  " << getNickName()  + "\t✦ " << std::endl;
	std::cout << "\033[1;32m✦\tPhone Number\t✦ \033[1;38;5;226m• ───────────────── • \e[0m✦  " << getPoneNumber()  + "\t✦ " << std::endl;
	std::cout << "\033[1;33m✦\tDark Secret\t✦ \033[1;38;5;226m• ───────────────── • \e[0m✦  " << getDark()  + "\t✦\n\n" << std::endl;
}











