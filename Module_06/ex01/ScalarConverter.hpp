#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

enum eType{
	NAN_INF,
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {
	public:
		~ScalarConverter();
		ScalarConverter( const ScalarConverter &copy );
		ScalarConverter& operator=( const ScalarConverter &assignment );
		static void convert( std::string );
	private:
		ScalarConverter();
};

#endif // !SCALARCONVERTER_HPP

