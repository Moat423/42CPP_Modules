#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "Debug.hpp"
#include <iostream>
#include <ostream>

DiamondTrap::DiamondTrap( void ): ClapTrap()
{
	_hitPoints = FRAG_MAX_HP;
	_energyPoints = 100;
	_attackDamage = 30;
	debug("< DiamondTrap > constructed");
}

DiamondTrap::DiamondTrap( const char *name ): ClapTrap(name)
{
	_hitPoints = FRAG_MAX_HP;
	_energyPoints = 100;
	_attackDamage = 30;
	debug("< DiamondTrap > constructed with name");
}

DiamondTrap::DiamondTrap( const DiamondTrap &rhs ): ClapTrap(rhs)
{
	debug("< DiamondTrap > copy constructed");
}

DiamondTrap::~DiamondTrap()
{
	debug("< DiamondTrap > destroyed");
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &rhs )
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_attackDamage = rhs._attackDamage;
		_energyPoints = rhs._energyPoints;
		_hitPoints = rhs._hitPoints;
	}
	return (*this);
}

void DiamondTrap::whoAmI() const;
