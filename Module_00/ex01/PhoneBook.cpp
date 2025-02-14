#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

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
	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << std::endl << "ERROR: can not have empty fields" << std::endl << "........ RETURNING" << std::endl;
		return ;
	}
	_contacts[index].set(firstName, lastName, nickname, phoneNumber, darkestSecret);
	i++;
}

void	PhoneBook::_printBook() const
{
	int	i = 0;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|   INDEX  |FIRST NAME|LAST NAME | NICKNAME |" << std::endl;
	while (i < 8 && !_contacts[i].getFirstName().empty())
	{
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::string	firstName, lastName, nickname;
		firstName = _formatString(_contacts[i].getFirstName());
		lastName = _formatString(_contacts[i].getLastName());
		nickname = _formatString(_contacts[i].getNickname());
		std::cout << "|"  << i << std::setw(_WIDTH) <<"|";
		std::cout << std::setw(_WIDTH) << firstName << "|";
		std::cout << std::setw(_WIDTH) << lastName << "|";
		std::cout << std::setw(_WIDTH) << nickname << "|" << std::endl;
		i++;
	}
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << std::flush;
}

std::string	PhoneBook::_formatString(std::string str) const
{
	if (str.length() > _WIDTH)
	{
		str = str.substr(0, _WIDTH - 1);
		str.append(".");
		return (str);
	}
	return (str + std::string( _WIDTH - str.length(), ' '));
}

void	PhoneBook::searchContact() const
{
	int	i = 0;
	if (_contacts[0].getFirstName().empty())
	{
		std::cout << "no Contacts in your PHONEBOOK (╥﹏╥)" << std::endl;
		return ;
	}
	_printBook();
	std::cout << std::endl << "ENTER INDEX OF CONTACT TO DISPLAY: " << std::endl;
	std::cout << "> " << std::flush;
	std::cin >> i;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (i >= 0 && i < 8 && !_contacts[i].getFirstName().empty())
	{
	std::cout << std::endl;
	std::cout << "--------------> CONTACT #" << i << std::endl;
	std::cout << "FIRST NAME:     " << _contacts[i].getFirstName() << std::endl;
	std::cout << "LAST NAME:      " << _contacts[i].getLastName() << std::endl;
	std::cout << "NICKNAME:       " << _contacts[i].getNickname() << std::endl;
	std::cout << "PHONE NUMBER:   " << _contacts[i].getPhonenumber() << std::endl;
	std::cout << "DARKEST SECRET: " << _contacts[i].getDarkestSecret() << std::endl << std::endl;
	}
	else
		std::cout << "invalid input" << std::endl << std::endl;
}
