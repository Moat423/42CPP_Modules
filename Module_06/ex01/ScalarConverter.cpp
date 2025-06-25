#include "ScalarConverter.hpp"
#include "Debug.hpp"
#include <string>

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
	if (number.compare("nan") == 0
			|| number.compare("nanf") == 0
			|| number.compare("-inff") == 0
			|| number.compare("+inff") == 0
			|| number.compare("-inf") == 0
			|| number.compare("+inf") == 0)
		return (NAN_INF);
	else if (number.length() == 1
			&& (number[0] != '-' || '.' || '+' || 'f'))
	return (ERROR);
}

void ScalarConverter::convert( std::string number)
{
	bool	displayableChar;
	eType	nbType;
	char	c;
	int		nb;
	float	fl;
	double	db;

	nbType = checkType(number);
}
