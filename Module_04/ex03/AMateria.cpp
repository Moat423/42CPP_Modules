#include "AMateria.hpp"
#include <iostream>
#include "ICharacter.hpp"
#include "Debug.hpp"

AMateria::AMateria(): _type("")
{
	debug("AMateria is created");
}

AMateria::AMateria(std::string const & type): _type(type)
{
	debug("AMateria of " << this->_type << " is created");
}

AMateria::~AMateria()
{
	debug("AMateria of " << this->_type << " destroyed");
}

AMateria::AMateria(const AMateria &copy): _type(copy._type)
{
	debug("AMateria copy constructor called");
}

AMateria  &AMateria::operator=(const AMateria &assign)
{
	debug("AMateria assignment operator called");
	if (this != &assign)
		this->_type = assign._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria " << this->_type << " used on " << target.getName() << " *" << std::endl;
}
