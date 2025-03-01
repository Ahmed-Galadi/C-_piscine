

#include "Contact.class.hpp"
#include <cstdlib>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>



// contants
const char *Contact::input_msgs[5] = {
    "Enter First Name: ",
	"Enter Last Name: ",
	"Enter Nickname: ",
	"Enter Phone Number: ",
	"Enter Darkest Secret: "
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

std::string Contact::getNickName() {
	return (nickName);
}

std::string Contact::getDark() {
	return (dark);
}












