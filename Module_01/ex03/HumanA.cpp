#ifndef _HUMANA_CPP
#define _HUMANA_CPP

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {}

HumanA::~HumanA( void )
{}

void	HumanA::attack( void ) const
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
#endif
