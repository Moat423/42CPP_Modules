#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class Data {
	public:
		Data( void );
		Data( std::string animal, unsigned int numberOfFeet );
		virtual ~Data();

		Data(const Data &copy);
		Data& operator=( const Data &assign );

		std::string getAnimal() const;
		unsigned int getNumberOfFeet() const;
	private:
		std::string		_animal;
		unsigned int	_numberOfFeet;
};

#endif // !DATA_HPP
