#include "PhoneBook.hpp"
#include <iostream>
#include <string>

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

std::string	PhoneBook::_getInput()
{
	std::string	input;

	return (input);
}

void	PhoneBook::addContact()
{
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;
	static int	i = 0;
	int			index = i % 8;

	std::cout << "FIRST NAME:" << std::flush;
	std::getline(std::cin, firstName);
	std::cout << "LAST NAME:" << std::flush;
	std::getline(std::cin, lastName);
	std::cout << "NICKNAME:" << std::flush;
	std::getline(std::cin, nickname);
	std::cout << "PHONE NUMBER:" << std::flush;
	std::getline(std::cin, phoneNumber);
	std::cout << "darkest secret:" << std::flush;
	std::getline(std::cin, darkestSecret);

	_contacts[index].set(firstName, lastName, nickname, phoneNumber, darkestSecret);
	i++;
}

void	PhoneBook::searchContact() const
{
	
}
