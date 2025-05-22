#include "Dog.hpp"
#include <iostream>
#include "Debug.hpp"

Dog::Dog( void )
{
	type = "Dog";
	std::cout << CYN << "🐶 Default constructor called" << RESET << std::endl;
}

Dog::~Dog( void )
{
	std::cout << CYN << "🐶 Destructor called" << RESET << std::endl;
}

Dog::Dog( const Dog &copy): Animal( copy )
{
	std::cout << CYN << "🐶 Copy constructed" << RESET << std::endl;
}

Dog &Dog::operator=( const Dog &assign )
{
	std::cout << CYN << "🐶 Assignment Operator called" << RESET << std::endl;
	if (this != &assign)
		type = assign.getType();
	return (*this);
}

std::string Dog::getType() const
{
	return (type);
}

void Dog::makeSound( void ) const
{
	std::cout << CYN << "🐶 Wau wau ("<< getType() << " is barking)" << RESET << std::endl;
}
