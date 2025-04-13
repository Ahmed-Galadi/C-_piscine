

#include "Contact.class.hpp"

// contants
const char *Contact::input_msgs[5] = {
    "\e[0m\e[96mEnter First Name: \e[0m",
	"\e[0m\e[96mEnter Last Name: \e[0m",
	"\e[0m\e[96mEnter Nickname: \e[0m",
	"\e[0m\e[96mEnter Phone Number: \e[0m",
	"\e[0m\e[96mEnter Darkest Secret: \e[0m"
};

// helpers
bool Contact::str_trim_ws(const std::string& str) {
    std::string result;
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (true);
	}
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isspace(str[i])) {
            result += str[i];
        }
    }
	if (result.length() == 0)
		return (true);
	return (false);
}

// setters
void	Contact::setData(int currentIndex) {
	std::string input;

	index = currentIndex;
	for (int i = 0; i < 5; i++)
	{
		std::cout << input_msgs[i];
		std::getline(std::cin, input, '\n');
		if (std::cin.eof()) {
			std::cout << "\n    \e[93m𝙴𝙾𝙵 (𝙲𝚝𝚛𝚕 + 𝙳) 𝙳𝚎𝚝𝚎𝚌𝚝𝚎𝚍\n\e[95m◄ \e[91m░░░▒▒▓\e[31m 𝙴𝚇𝙸𝚃 𝙿𝚁𝙾𝙶𝚁𝙰𝙼𝙴 \e[91m▓▒▒░░░\e[95m ►\e[0m\n";
			exit(0);
		}
		if (str_trim_ws(input)) {
			std::cout << "\n \e[92m𝔽𝕚𝕖𝕝𝕕 𝕔𝕒𝕟'𝕥 𝕓𝕖 𝔼𝕞𝕡𝕥𝕪 ⚠️\n\n\e[95m◄ \e[91m░░░▒▒▓\e[31m 𝙴𝚇𝙸𝚃 𝙿𝚁𝙾𝙶𝚁𝙰𝙼𝙴 \e[91m▓▒▒░░░\e[95m ►\e[0m\n\n";
			exit(0);
		}
		switch (i) {
			case 0: firstName = input; break;
			case 1: lastName = input; break;
			case 2: nickName = input; break;
			case 3: number = input; break;
			case 4: dark = input; break;
		}
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











