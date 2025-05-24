#include "A_Animal.hpp"
#include <iostream>

A_Animal::A_Animal( void ): type("A_Animal")
{
	std::cout << "A_Animal: Default constructor called" << std::endl;
}

A_Animal::A_Animal( std::string type ): type(type)
{
	std::cout << "A_Animal: named constructor called" << std::endl;
}

A_Animal::~A_Animal( void )
{
	std::cout << "A_Animal: Destructor called" << std::endl;
}

A_Animal::A_Animal( const A_Animal &copy):
	type(copy.type)
{
	std::cout << "A_Animal: Copy constructed" << std::endl;
}

A_Animal &A_Animal::operator=( const A_Animal &assign )
{
	std::cout << "A_Animal: Assignment Operator called" << std::endl;
	if (this != &assign)
		type = assign.getType();
	return (*this);
}

std::string A_Animal::getType() const
{
	return (type);
}

void A_Animal::makeSound( void ) const
{
	std::cout << "a wild "<< getType() << " makes an unrecognized sound" << std::endl;
}
