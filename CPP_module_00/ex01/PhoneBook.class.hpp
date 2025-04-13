

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <string>
#include "Contact.class.hpp"

class PhoneBook {
	private:
		static const	int MAX_CONTACTS = 8;
		Contact			contacts[MAX_CONTACTS];
		int				contactCount;
		
		void				printFirstColumn();
		static	std::string	formatStr(const std::string str);
		static	std::string	itoa(int nbr);
		static	bool		stoi(const std::string& str, int& out);
	public:
		PhoneBook();
		void addContact();
		void displayContacts();
		void searchContact();
};

#endif
