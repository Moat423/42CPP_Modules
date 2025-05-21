#include "Animal.hpp"
#include <iostream>

Animal::Animal( void )
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal: Destructor called" << std::endl;
}

Animal::
