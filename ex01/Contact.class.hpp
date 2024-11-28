

#ifndef CONTACT_CLASS_HPP
 # define CONTACT_CLASS_HPP

#include <string>

class Contact {
	private:
		int index;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string number;
		std::string dark;
	public:
		// setters
		void setIndex(int prevIndex);
		void setName(const std::string &first, const std::string &last);		
		void setPhoneNumber(const std::string &nick, const std::string &phone);
		void setSecret(const std::string &secret);
		// getters
		int getIndex();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getDark();
};

#endif
