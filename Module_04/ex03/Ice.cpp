#include "AMateria.hpp"
#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Debug.hpp"

Ice::Ice(): AMateria("ice")
{
	debug("Ice constructor called");
}

Ice::~Ice()
{
	debug("Ice destructor called");
}

Ice::Ice(const Ice &copy): AMateria(copy)
{
	debug("Ice copy constructor called");
}

Ice  &Ice::operator=(const Ice &assign)
{
	if (this != &assign)
		debug("Ice assignment operator called");
	return (*this);
}

Ice* Ice::clone() const
{
	debug("Ice cloned");
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
