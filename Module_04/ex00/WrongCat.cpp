#include "WrongCat.hpp"
#include <iostream>
#include "Debug.hpp"

WrongCat::WrongCat( void )
{
	type = "WrongCat";
	std::cout << RED << "Wrong🐱 Default constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << RED << "Wrong🐱 Destructor called" << RESET << std::endl;
}

WrongCat::WrongCat( const WrongCat &copy): WrongAnimal( copy )
{
	std::cout << RED << "Wrong🐱 Copy constructed" << RESET << std::endl;
}

WrongCat &WrongCat::operator=( const WrongCat &assign )
{
	std::cout << RED << "Wrong🐱 Assignment Operator called" << RESET << std::endl;
	if (this != &assign)
		type = assign.getType();
	return (*this);
}

std::string WrongCat::getType() const
{
	return (type);
}

void WrongCat::makeSound( void ) const
{
	std::cout << RED << "😺 MEOOOOW ("<< getType() << " is meowing)" << RESET << std::endl;
}
