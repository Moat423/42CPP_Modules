#include "Data.hpp"
#include "Debug.hpp"

// Default Constructor
Data::Data( void ): animal("animal"), numberOfFeet(4)
{
	debug("Data Default Constructor called");
}

// Parameterized Constructor
Data::Data( std::string animal, unsigned int numberOfFeet ): animal(animal), numberOfFeet(numberOfFeet)
{
	debug("Data Parameterized Constructor called");
}

// Destructor
Data::~Data()
{
	debug("Data Destructor called");
}

// Copy Constructor
Data::Data(const Data &copy): _animal(copy.getAnimal()), _numberOfFeet(copy.getNumberOfFeet())
{
	debug("Data Copy Constructor called");
}

// Copy Assignment Operator
Data& Data::operator=( const Data &assign )
{
	if (this != &assign)
	{
		_animal = assign.getAnimal();
		_numberOfFeet = assign.getNumberOfFeet();
	}
	return *this;
}

std::string Data::getAnimal() const
{
	return _animal;
}

unsigned int Data::getNumberOfFeet() const 
{
	return _numberOfFeet;
}

