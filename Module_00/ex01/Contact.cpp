#include "Contact.hpp"

// Constructor, called when object is created
// sets its own fields by accessing itself ( = this,  explicitly typed out here for clarity)
Contact::Contact() {}

Contact::~Contact() {}

void	Contact::set(std::string firstName, std::string lastName, std::string nickname, std::string phonenumber, std::string darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phonenumber = phonenumber;
	this->_darkestSecret = darkestSecret;
}
