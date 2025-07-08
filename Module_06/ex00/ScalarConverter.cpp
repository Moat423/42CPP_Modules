#include "ScalarConverter.hpp"
#include "Debug.hpp"
#include <cmath>
#include <iomanip>
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

eScalarType ScalarConverter::checkType( std::string literal )
{
	size_t	i = 0;
	bool	hasDot = false;
	bool	hasF = false;
	bool	hasDigit = false;
	int		scientific = 0;

	if (literal == ("nan") || literal == ("-inf") || literal == ("+inf"))
			return (DOUBLE);
	if (literal == ("nanf") || literal == ("-inff") || literal == ("+inff"))
		return (FLOAT);
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
		else if ((literal[i] == 'e' || literal[i] == 'E') && (literal[i + 1] == '-' || literal[i + 1] == '+'))
		{
			i++;
			scientific++;
		}
		else if (literal[i] == 'f' && !hasF && i == literal.length() - 1)
			hasF = true;
		else
		 	return (ERROR);
	}
	if (!hasDigit || scientific > 1)
		return (ERROR);
	if (hasF)
		return (FLOAT);
	if (hasDot || scientific == 1)
		return (DOUBLE);
	else
		return (INT);
}

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
	std::cout << "float: ";
	if (!(possibilityFlags & FLOAT))
		std::cout << "impossible";
	else if (std::fabs(f - std::floor(f)) < 1e-9)
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	else
		std::cout << f << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	if (!(possibilityFlags & DOUBLE))
		std::cout << "impossible";
	else
		std::cout << d;
	std::cout << std::endl;
}

static void printErrorConversion( void )
{
	std::cerr << "Error: Invalid input" << std::endl;
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
	int		i = 0;
	float	fl = 0;
	double	db = 0;
	char	*endptr;
	int		type = FLOAT | DOUBLE;

	nb = strtol(literal.c_str(), &endptr, 10);
	if (nb >= std::numeric_limits<int>::min()
		&& nb <= static_cast<float>(std::numeric_limits<int>::max()))
	{
		i = static_cast<int>(nb);
		type |= INT;
	}
	if (*endptr != '\0')
		return printErrorConversion();
	if (nb > 0 && nb <= 127)
	{
		c = static_cast<char>(nb);
		type |= CHAR;
	}
	fl = static_cast<float>(nb);
	db = static_cast<double>(nb);
	printConversions(c, i, fl, db, type);
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
	if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0'))
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
	if (!std::isnan(db) && !std::isinf(db)
		&& (db >= std::numeric_limits<int>::min()
		&& db <= std::numeric_limits<int>::max()))
	{
		i = static_cast<int>(db);
		type |= INT;
	}
	if (std::isnan(db) || std::isinf(db)
		|| (db >= -std::numeric_limits<float>::max()
		&& db <= std::numeric_limits<float>::max()))
	{
		fl = static_cast<float>(db);
		type |= FLOAT;
	}
	printConversions(c, i, fl, db, type);
}
void ScalarConverter::convert( std::string literal)
{
	eScalarType		type;

	type = checkType(literal);
	switch ( type ){
		case ERROR:
			std::cerr << "Error: Invalid input" << std::endl;
			break;
		case CHAR:
			convertFromChar(literal);
			break;
		case INT:
			convertFromInt(literal);
			break;
		case FLOAT:
			convertFromFloat(literal);
			break;
		case DOUBLE:
			convertFromDouble(literal);
			break;
		default:
			printErrorConversion();
			break;
	}
	return ;

}
