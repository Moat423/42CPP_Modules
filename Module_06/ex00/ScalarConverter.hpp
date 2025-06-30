#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

enum eType{
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NAN,
	INF
};

class ScalarConverter {
	public:
		~ScalarConverter();
		ScalarConverter( const ScalarConverter &copy );
		ScalarConverter& operator=( const ScalarConverter &assignment );
		static void convert( std::string );
	private:
		static eType	_type;
		static char		_char;
		static int		_int;
		static float	_float;
		static double	_double;
		ScalarConverter();
};

#endif // !SCALARCONVERTER_HPP

