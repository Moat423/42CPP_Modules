#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	std::string welcome = "WELCOME to MY_AWESOME_80S_PHONEBOOK";
	std::cout << welcome << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::string bye = "GOODBYE";
	std::cout << bye << std::endl;
}
