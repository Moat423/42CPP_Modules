#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ): type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &copy):
	type(copy.type)
{
	std::cout << "WrongAnimal: Copy constructed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &assign )
{
	std::cout << "WrongAnimal: Assignment Operator called" << std::endl;
	if (this != &assign)
		type = assign.getType();
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "a wild "<< getType() << " makes an unrecognized sound" << std::endl;
}
