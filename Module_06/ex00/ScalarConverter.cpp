#include "ScalarConverter.hpp"
#include "Debug.hpp"
#include <string>
#include <iostream>

// Default Constructor
ScalarConverter::ScalarConverter( void )
{
	debug("Default Constructor called");
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	debug("Destructor called");
}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	debug("Copy Constructor called");
}

// Copy Assignment Operator
ScalarConverter& ScalarConverter::operator=( const ScalarConverter &assignment )
{
	debug("Copy Assignment called");
	if (this != &assignment){}
	return (*this);
}

static eType checkType( std::string number )
{
	char	*endptr;
	int		intnum;
	if (number.compare("nan") == 0 || number.compare("nanf") == 0)
		return (NAN);
	else if (number.compare("-inff") == 0
			|| number.compare("+inff") == 0
			|| number.compare("-inf") == 0
			|| number.compare("+inf") == 0)
		return (INF);
	else if (number.length() == 1
			&& (number[0] != '-' || number[0] != '+'
				|| number[0] != '.' || number[0] != 'f'))
		return (CHAR);
	return (ERROR);
}

static void	printNormalConversion(char *c, int nb, float fl, double db)
{
	std::cout << "char: ";
	if (c)
		//TODO: catch nondisplayable
		std::cout<< "'" << *c << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: "
	<< nb << std::endl;
	std::cout << "float: "
	<< fl << "f" << std::endl;
	std::cout << "double: "
	<< db << std::endl;
}

static void printNanInfConversion(std::string number, float fl, double db)
{
	std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	if (number.compare("nan") == 0 || number.compare("nanf") == 0)
		std::cout << "nanf" << std::endl;
	else
		// TODO: does this catch + and - inf?
		std::cout << fl << "f" << std::endl;
	std::cout << "double: ";
	if (number.compare("nan") == 0 || number.compare("nanf") == 0)
		//TODO: cant this print nan?
		std::cout << db << std::endl;
	else
		std::cout << db << std::endl;
}

static void printErrorConversion( void )
{
	std::cerr << "Error: Invalid input" << std::endl;
}

// static void	fromNanInf(std::string number)
// {
// 	printNanInfConversion(
// 			number, 
// 			static_cast<float>(number),
// 			static_cast<double>(number)
// 			);
// }

static void	fromChar( std::string number )
{
	printNormalConversion(
			 &number[0], 
			static_cast<int>(number[0]),
			static_cast<float>(number[0]),
			static_cast<double>(number[0])
			);
}

static void	fromInt( std::string number )
{
	char	c;
	int		nb;
	float	fl;
	double	db;
	char *endptr;
	nb = strtol(number.c_str(), &endptr, 10);
	if (*endptr != '\0')
	{
		printErrorConversion();
		return;
	}
	c = static_cast<char>(nb);
	fl = static_cast<float>(nb);
	db = static_cast<double>(nb);
	printNormalConversion(&c, nb, fl, db);

	// char	c = static_cast<char>(std::stoi(number));
	// printNormalConversion(
	// 		&c,
	// 		std::stoi(number),
	// 		static_cast<float>(std::stoi(number)),
	// 		static_cast<double>(std::stoi(number))
	// 		);
}

void ScalarConverter::convert( std::string number)
{
	bool	displayableChar;
	char	c;
	int		nb;
	float	fl;
	double	db;

	_type = checkType(number);
	switch ( _type ){
	case ERROR:
		std::cerr << "Error: Invalid input" << std::endl;
		break;
	// case NAN:
	// 	fromNan(number);
	// 	return;
	case CHAR:
		fromChar(number);
		break;
	case INT:
		fromInt(number);
		break;
	default:
		break;
	}
	return ;

}
