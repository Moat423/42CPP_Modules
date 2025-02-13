#include "PhoneBook.hpp"
#include <limits>
#include <string>
#include <iostream>
#include <iomanip>

// display startup
//str = get_iput
// call correct function
// display updated phonebook
int main (void)
{
	PhoneBook	book;
	std::string	input;

	while (input.compare("EXIT"))
	{
		std::cout << "Capacity of empty string: " << input.capacity() << std::endl;
		std::cout << "DO > " << std::flush;
		std::cin >> std::setw(7) >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH"))
			book.searchContact();
	}
	return 0;
}

