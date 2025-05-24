#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ): type("Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal( std::string type ): type(type)
{
	std::cout << "Animal: named constructor called" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal( const Animal &copy):
	type(copy.type)
{
	std::cout << "Animal: Copy constructed" << std::endl;
}

Animal &Animal::operator=( const Animal &assign )
{
	std::cout << "Animal: Assignment Operator called" << std::endl;
	if (this != &assign)
		type = assign.getType();
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound( void ) const
{
	std::cout << "a wild "<< getType() << " makes an unrecognized sound" << std::endl;
}
