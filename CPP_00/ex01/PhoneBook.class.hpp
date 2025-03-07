

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <string>
#include "Contact.class.hpp"
#include <readline/readline.h>
#include <readline/history.h>

class PhoneBook {
	private:
		static const int MAX_CONTACTS = 8;               // static constant
		Contact contacts[MAX_CONTACTS];          // static array of contacts
		int contactCount;                        // static count of contacts
		
		void printFirstColumn();
		static std::string formatStr(const std::string str);
		static std::string itoa(int nbr);
	public:
		PhoneBook();
		void addContact();
		void displayContacts();
		void searchContact();
};

#endif
