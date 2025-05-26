#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &copy): AMateria(copy)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure  &Cure::operator=(const Cure &assign)
{
	if (this != &assign)
		std::cout << "Cure assignment operator called" << std::endl;
	return (*this);
}
Cure* Cure::clone() const
{
	std::cout << "Cure cloned" << std::endl;
	return (new Cure(*this));
}
void Cure::use(ICharacter& target)
{

	std::cout <<  "* heals " << target.getName() << "’s wounds *" << " *" << std::endl;
}
