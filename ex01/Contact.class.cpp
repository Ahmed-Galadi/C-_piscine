

#include "Contact.class.hpp"
// setters
void	Contact::setIndex(int prevIndex) {
	index = prevIndex + 1;
}

void Contact::setName(const std::string &first, const std::string &last) {
	firstName = first;
	lastName = last;
}

void Contact::setPhoneNumber(const std::string &nick, const std::string &phone) {
	nickName = nick;
	number = phone;
}

void Contact::setSecret(const std::string &secret) {
	dark = secret;
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












