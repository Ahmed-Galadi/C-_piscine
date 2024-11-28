

#ifndef PHONEBOOK_CLASS_HPP
# define  PHONEBOOK_CLASS_HPP

#include <string>
#include <iostream>
#include "Contact.class.hpp"
# define MAX_CONTACTS 8

class PhoneBook {
	private:
		Contact contacts[MAX_CONTACTS];
		int contactCount;
	public:
		void addContact(std::string firstName, std::string lastName, std::string nickName, std::string number, std::string secret);
};

#endif
