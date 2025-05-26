#include "AMateria.hpp"
#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &copy): AMateria(copy)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice  &Ice::operator=(const Ice &assign)
{
	if (this != &assign)
		std::cout << "Ice assignment operator called" << std::endl;
	return (*this);
}

Ice* Ice::clone() const
{
	std::cout << "Ice cloned" << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
