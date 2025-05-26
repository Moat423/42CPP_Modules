#include "AMateria.hpp"
#include <iostream>
#include "ICharacter.hpp"

AMateria::AMateria(): _type("")
{
	std::cout << "AMateria is created" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "AMateria of " << this->_type << " is created" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria of " << this->_type << " destroyed" << std::endl;
}

AMateria::AMateria(const AMateria &copy): _type(copy._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria  &AMateria::operator=(const AMateria &assign)
{
	std::cout << "AMateria assignment operator called" << std::endl;
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
