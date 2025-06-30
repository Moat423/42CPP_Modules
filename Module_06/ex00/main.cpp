#include "ScalarConverter.hpp"
#include <iostream>

void tests( void );

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Requires exactly one argument" << std::endl;
	}
	ScalarConverter::convert(argv[1]);
	tests();
	return 0;
}

void	charTests( void )
{
	std::cout << "Testing Chars" << std::endl;
	std::string all = "0a^ 	ü";
	for (unsigned int i = 0; i < all.length(); i++)
	{
		std::cout << "char: " << all[i] << std::endl;
		ScalarConverter::convert(std::string(1, all[i]));
	}
}

void	testIntNumber( std::string number )
{
	std::cout << "int: " << number << std::endl;
	ScalarConverter::convert(number);
}

void	intTests( void )
{
	std::cout << "Testing Ints" << std::endl;
	testIntNumber("0");
	testIntNumber("42");
	testIntNumber("-42");
	testIntNumber("2147483647");
	testIntNumber("-2147483648");
}


void tests( void )
{
	charTests();
	intTests();
}
