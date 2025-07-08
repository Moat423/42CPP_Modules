#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

enum eScalarType{
	ERROR,
	CHAR = 1,
	INT = 2,
	FLOAT = 4,
	DOUBLE = 8,
	SPECIAL = 32
};

class ScalarConverter {
	public:
		~ScalarConverter();
		ScalarConverter( const ScalarConverter &copy );
		ScalarConverter& operator=( const ScalarConverter &assignment );
		static void			convert( std::string );
	private:
		static eScalarType	checkType( std::string literal );
		// Conversion functions 
		static void			printConversions(char c, int i, float f, double d, unsigned char possibilityFlags);
		static void			convertFromChar(const std::string &literal);
		static void			convertFromInt(const std::string &literal);
		static void			convertFromFloat(const std::string &literal);
		static void			convertFromDouble(const std::string &literal);
		static void			handleSpecialCases(const std::string &literal);
		ScalarConverter();
};

#endif // !SCALARCONVERTER_HPP

