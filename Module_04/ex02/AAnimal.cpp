#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal( void ): type("AAnimal")
{
	std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ): type(type)
{
	std::cout << "AAnimal: named constructor called" << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &copy):
	type(copy.type)
{
	std::cout << "AAnimal: Copy constructed" << std::endl;
}

AAnimal &AAnimal::operator=( const AAnimal &assign )
{
	std::cout << "AAnimal: Assignment Operator called" << std::endl;
	if (this != &assign)
		type = assign.getType();
	return (*this);
}

std::string AAnimal::getType() const
{
	return (type);
}

void AAnimal::makeSound( void ) const
{
	std::cout << "a wild "<< getType() << " makes an unrecognized sound" << std::endl;
}
