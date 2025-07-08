#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include "Debug.hpp"

void tests();

int main (int argc, char *argv[])
{
	//tests();
	if (argc != 2)
	{
		std::cerr << "Requires exactly one argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

void	charTests( void )
{
	std::cout << BLUE << "Testing Chars" << RESET << std::endl;
	std::string all = "0a^ 	ü+-.f";
	for (unsigned int i = 0; i < all.length(); i++)
	{
		std::cout << std::endl;
		std::cout << "inputChar: " << all[i] << std::endl;
		ScalarConverter::convert(std::string(1, all[i]));
	}
}

void	testIntNumber( std::string number )
{
	std::cout << std::endl;
	std::cout << "inputInt: " << number << std::endl;
	ScalarConverter::convert(number);
}

void	intTests( void )
{
	std::cout << "Testing Ints" << RESET << std::endl;
	testIntNumber("0");
	testIntNumber("42");
	testIntNumber("-42");
	testIntNumber("2147483647");
	testIntNumber("-2147483648");
	std::cout << "Int Max:" << std::numeric_limits<int>::max() << std::endl;
	std::cout << "Int min:" << std::numeric_limits<int>::min() << std::endl;
	std::cout << "should not be int, too big" << std::endl;
	testIntNumber("214748364800");
}

void	testFloatNumber( std::string number )
{
	std::cout << std::endl;
	std::cout << "inputFloat: " << number << std::endl;
	ScalarConverter::convert(number);
}

void	floatTests( void )
{
	std::cout << BLUE << "Testing Floats" << RESET << std::endl;
	testFloatNumber("0.0f");
	testFloatNumber("42.42f");
	testFloatNumber("-42.42f");
	testFloatNumber("3.402823466e+38f");
	testFloatNumber("-3.402823466e+38f");
	testFloatNumber("1.175494351e-38f");
	testFloatNumber("-1.175494351e-38f");
	std::cout << "float Max:" << std::numeric_limits<float>::max() << std::endl;
	std::cout << "float min:" << std::numeric_limits<float>::min() << std::endl;
	std::cout << "should not be float, too big" << std::endl;
	testFloatNumber("3.402823466e+39f");
}

void	testDoubleNumber( std::string number )
{
	std::cout << std::endl;
	std::cout << "inputDouble: " << number << std::endl;
	ScalarConverter::convert(number);
}

void	doubleTests( void )
{
	std::cout << BLUE  << "Testing Doubles" << RESET << std::endl;
	testDoubleNumber("0.0");
	testDoubleNumber("42.42");
	testDoubleNumber("-42.42");
	testDoubleNumber("1.7976931348623157e+308");
	testDoubleNumber("-1.7976931348623157e+308");
	testDoubleNumber("2.2250738585072014e-308");
	testDoubleNumber("-2.2250738585072014e-308");
	std::cout << "double Max:" << std::numeric_limits<double>::max() << std::endl;
	std::cout << "double min:" << std::numeric_limits<double>::min() << std::endl;
	std::cout << "should not be double, too big" << std::endl;
	testDoubleNumber("-1.7976931348623157e+309");
}

void	testSpecialNumber( std::string number )
{
	std::cout << std::endl;
	std::cout << "inputSpecial: " << number << std::endl;
	ScalarConverter::convert(number);
}

void	specialTests( void )
{
	std::cout << BLUE << "Testing Special Cases" << RESET << std::endl;
	testSpecialNumber("nanf");
	testSpecialNumber("+inff");
	testSpecialNumber("-inff");
	testSpecialNumber("nan");
	testSpecialNumber("+inf");
	testSpecialNumber("-inf");
	testSpecialNumber("34f4.0d");
	testSpecialNumber("..");
}

void tests( void )
{
	charTests();
	intTests();
	floatTests();
	doubleTests();
	specialTests();
}
