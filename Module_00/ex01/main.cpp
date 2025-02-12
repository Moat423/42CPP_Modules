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
	PhoneBook	phoneBook;
	std::string	input;

	while (input.compare("EXIT"))
	{
		std::cout << "DO > " << std::flush;
		std::cin >> std::setw(7) >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "You entered: " << input << std::endl;
	}
	return 0;
}

