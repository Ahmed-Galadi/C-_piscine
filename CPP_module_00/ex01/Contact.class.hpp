

#ifndef CONTACT_CLASS_HPP
 # define CONTACT_CLASS_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <string>

class Contact {
	private:
	    static const char *input_msgs[5];
		int index;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string number;
		std::string dark;

		static bool str_trim_ws(const std::string &str);

	public:
		// setters
		void setData(int currentIndex);
		// getters
		int getIndex();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPoneNumber();
		std::string getDark();
		// function
		void print_info();
};

#endif
