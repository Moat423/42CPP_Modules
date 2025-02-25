#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main (void)
{
	PhoneBook	book;
	std::string	input = "";

	while (input.compare("EXIT") != 0 && std::cin.eof() == 0)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input.empty())
			continue ;
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0)
			book.searchContact();
	}
	return 0;
}

