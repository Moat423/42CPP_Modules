#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB( void )
{}

// using a reference from the value that was passed in, so that
// getting the pointer can get the pointer from the calling function 
// and not this current function (else dangling pointers)
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) const
{
	if (_weapon)
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks " << "but it failed cause he has no weapon" << std::endl;
}
