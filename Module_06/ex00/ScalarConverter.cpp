#include "ScalarConverter.hpp"
#include "Debug.hpp"
#include <cmath>
#include <cstdlib>
#include <limits>
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
	static_cast<void>(copy);
	debug("Copy Constructor called");
}

// Copy Assignment Operator
ScalarConverter& ScalarConverter::operator=( const ScalarConverter &assignment )
{
	debug("Copy Assignment called");
	if (this != &assignment){}
	return (*this);
}

static eScalarType checkType( std::string literal )
{
	size_t	i = 0;
	bool	hasDot = false;
	bool	hasF = false;
	bool	hasDigit = false;
	if ((literal.compare("nan") == 0 || literal.compare("nanf") == 0)
			||literal.compare("-inff") == 0
			|| literal.compare("+inff") == 0
			|| literal.compare("-inf") == 0
			|| literal.compare("+inf") == 0)
		return (SPECIAL);
	if (literal.length() == 1 && !(isdigit(literal[0])))
		return (CHAR);
	if (literal[i] == '-' || literal[i] == '+')
		++i;
	for (; i < literal.length(); i++)
	{
		if (isdigit(literal[i]))
			hasDigit = true;
		else if (literal[i] == '.' && !hasDot && !hasF)
			hasDot = true;
		else if (literal[i] == 'f' && !hasF && i == literal.length() - 1)
			hasF = true;
		else
		 	return (ERROR);
		if (!hasDigit)
			return (ERROR);
		if (hasF)
			return (FLOAT);
		if (hasDot)
			return (DOUBLE);
		else
			return (INT);
	}
	return (ERROR);
}

// static void	printNormalConversion(char *c, int *nb, float *fl, double db)
// {
// 	std::cout << "char: ";
// 	if (!c)
// 		std::cout << "impossible" << std::endl;
// 	else if (std::isprint((*c)))
// 			std::cout<< "'" << *c << "'";
// 	else
// 			std::cout << "Non displayable";
// 	std::cout << std::endl;
// 	std::cout << "int: "
// 	<< nb << std::endl;
// 	std::cout << "float: "
// 	<< fl << "f" << std::endl;
// 	std::cout << "double: "
// 	<< db << std::endl;
// }

void ScalarConverter::printConversions(char c, int i, float f, double d, unsigned char possibilityFlags)
{
	std::cout << "char: ";
	if (!(possibilityFlags & CHAR))
		std::cout << "impossible";
	else if (!std::isprint(c))
		std::cout << "Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
	std::cout << "int: ";
	if (!(possibilityFlags & INT))
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << std::endl;
	if (!(possibilityFlags & FLOAT))
		std::cout << "impossible";
	else
		std::cout << f << "f";
	std::cout << std::endl;
	if (!(possibilityFlags & DOUBLE))
		std::cout << "impossible";
	else
		std::cout << d;
	std::cout << std::endl;
}

static void printNanInfConversion(std::string literal, float fl, double db)
{
	std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
		std::cout << "nanf" << std::endl;
	else
		// TODO: does this catch + and - inf?
		std::cout << fl << "f" << std::endl;
	std::cout << "double: ";
	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
		//TODO: cant this print nan?
		std::cout << db << std::endl;
	else
		std::cout << db << std::endl;
}

static void printErrorConversion( void )
{
	std::cerr << "Error: Invalid input" << std::endl;
}

static void	convertSpecial(std::string literal)
{
	char *endptr;
	float	fl = strtof(literal.c_str(), &endptr);
	if (*endptr != '\0')
		return (printErrorConversion());
	double	db = strtod(literal.c_str(), &endptr);
	if (*endptr != '\0')
		return (printErrorConversion());
	printNanInfConversion(
			literal, 
			fl,
			db
			);
}

void	ScalarConverter::convertFromChar( const std::string &literal )
{
	char	c = literal[0];
	printConversions(
		c,
		static_cast<int>(c + 48),
		static_cast<float>(c + 48),
		static_cast<double>(c + 48),
		CHAR | INT | FLOAT | DOUBLE
	);
}

void	ScalarConverter::convertFromInt( const std::string &literal )
{
	char	c = 0;
	long	nb = 0;
	float	fl = 0;
	double	db = 0;
	char	*endptr;
	int		type = FLOAT | DOUBLE;

	nb = strtol(literal.c_str(), &endptr, 10);
	if (nb >= std::numeric_limits<int>::min()
		&& nb <= static_cast<float>(std::numeric_limits<int>::max()))
		type |= INT;
	if (*endptr != '\0')
		return printErrorConversion();
	if (nb > 0 && nb <= 127)
	{
		c = static_cast<char>(nb);
		type |= CHAR;
	}
	fl = static_cast<float>(nb);
	db = static_cast<double>(nb);
	printConversions(c, nb, fl, db, type);
}

void	ScalarConverter::convertFromFloat( const std::string &literal )
{
	char	c = 0;
	long	i = 0;
	float	fl = 0;
	double	db = 0;
	char *endptr;
	int		type = FLOAT | DOUBLE;

	fl = strtof(literal.c_str(), &endptr);
	if (*endptr != '\0' || (*endptr == 'f' && *(endptr + 1) == '\0'))
		return printErrorConversion();
	if (fl > 0 && fl <= 127)
	{
		c = static_cast<char>(fl);
		type |= CHAR;
	}
	if (!std::isnan(fl) && !std::isinf(fl)
			&& fl >= std::numeric_limits<int>::min()
			&& fl <= static_cast<float>(std::numeric_limits<int>::max()))
	{
		i = static_cast<int>(fl);
		type |= INT;
	}
	db = static_cast<double>(fl);
	printConversions(c, i, fl, db, type);
}

void	ScalarConverter::convertFromDouble( const std::string &literal )
{
	char	c = 0;
	long	i = 0;
	float	fl = 0;
	double	db = 0;
	char *endptr;
	int		type = DOUBLE;
	db = strtod(literal.c_str(), &endptr);
	if (*endptr != '\0')
		return printErrorConversion();
	if (db > 0 && db <= 127)
		{
			c = static_cast<char>(db);
			type |= CHAR;
		}
	if (!std::isnan(db) && !std::isinf(db))
	{
		if (db >= std::numeric_limits<int>::min()
			&& db <= static_cast<double>(std::numeric_limits<int>::max()))
		{
			i = static_cast<int>(db);
			type |= INT;
		}
		if (db >= std::numeric_limits<float>::min()
			&& db <= static_cast<double>(std::numeric_limits<float>::max()))
		{
			fl = static_cast<float>(db);
			type |= FLOAT;
		}
	}
	printConversions(c, i, fl, db, type);
}
void ScalarConverter::convert( std::string literal)
{
	// bool	displayableChar;
	// char	c;
	// int		nb;
	// float	fl;
	// double	db;
	eScalarType		type;

	type = checkType(literal);
	switch ( type ){
		case ERROR:
			std::cerr << "Error: Invalid input" << std::endl;
			break;
		case SPECIAL:
			convertSpecial(literal);
			return;
		case CHAR:
			convertFromChar(literal);
			break;
		case INT:
			convertFromInt(literal);
			break;
		default:
			printErrorConversion();
			break;
	}
	return ;

}
