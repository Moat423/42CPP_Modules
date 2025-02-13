#include "PhoneBook.hpp"
#include <iostream>
#include <ostream>
#include <string>

PhoneBook::PhoneBook()
{
	/*std::string welcome = "WELCOME to MY_AWESOME_80S_PHONEBOOK";*/
	/*std::cout << welcome << std::endl;*/
	std::cout << 
" _____        _____                                   " << std::endl << \
"|     |_ _   |  _  |_ _ _ ___ ___ ___ _____ ___       " << std::endl << \
"| | | | | |  |     | | | | -_|_ -| . |     | -_|      " << std::endl << \
"|_|_|_|_  |  |__|__|_____|___|___|___|_|_|_|___|      " << std::endl << \
"      |___|                                           " << std::endl << \
"                                                      " << std::endl << \
" ___ ___        _____ _               _           _   " << std::endl << \
"| . |   |___   |  _  | |_ ___ ___ ___| |_ ___ ___| |_ " << std::endl << \
"| . | | |_ -|  |   __|   | . |   | -_| . | . | . | '_|" << std::endl << \
"|___|___|___|  |__|  |_|_|___|_|_|___|___|___|___|_,_|" << std::endl << std::endl ;

	std::cout << "type 'ADD' to add contacts, 'SEARCH' to search through your phonebook OR 'EXIT' " << std::endl << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::string bye = "GOODBYE";
	std::cout << bye << std::endl;
}

// technically, i am not guaranteeing a stack allocation here, but phonenumbers are at maximum 15 digits,
// SSO (small string optimisation) is 15 chars on this computer, so i would need 16 chars to comply with the standard,
// therefore there is no possiblitiy to comply with international standart for phone numbers and guarantee stack allocation
std::string	PhoneBook::_getInput(std::string prompt) const
{
	std::string	input;

	std::cout << prompt << std::flush;
	std::getline(std::cin, input);
	return (input);
}

void	PhoneBook::addContact()
{
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;
	static int	i = 0;
	int			index = i % 8;

	firstName = _getInput("FIRST NAME: ");
	lastName = _getInput("LAST NAME: ");
	nickname = _getInput("NICKNAME: ");
	phoneNumber = _getInput("PHONE NUMBER: ");
	darkestSecret = _getInput("darkest secret: ");
	_contacts[index].set(firstName, lastName, nickname, phoneNumber, darkestSecret);
	i++;
}

void	PhoneBook::searchContact() const
{
	
}
