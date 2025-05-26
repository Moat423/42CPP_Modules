#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include "Cure.hpp"
#include "Debug.hpp"

Cure::Cure(): AMateria("cure")
{
	debug("Cure constructor called");
}

Cure::~Cure()
{
	debug("Cure destructor called");
}

Cure::Cure(const Cure &copy): AMateria(copy)
{
	debug("Cure copy constructor called");
}

Cure  &Cure::operator=(const Cure &assign)
{
	if (this != &assign)
		debug("Cure assignment operator called");
	return (*this);
}
Cure* Cure::clone() const
{
	debug("Cure cloned");
	return (new Cure(*this));
}
void Cure::use(ICharacter& target)
{

	std::cout <<  "* heals " << target.getName() << "’s wounds *" << std::endl;
}
