#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "Debug.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ): ClapTrap()
{
	_hitPoints = FRAG_MAX_HP;
	_energyPoints = 50;
	_attackDamage = 30;
	debug("# DiamondTrap # constructed");
}

DiamondTrap::DiamondTrap( const char *name ): ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	// TODO strcpy name and append _clap_name to initialize ClapTrap
	_hitPoints = FRAG_MAX_HP;
	_energyPoints = 50;
	_attackDamage = 30;
	debug("# DiamondTrap # constructed with name");
}

DiamondTrap::DiamondTrap( const DiamondTrap &rhs ): ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	debug("# DiamondTrap # copy constructed");
}

DiamondTrap::~DiamondTrap()
{
	debug("# DiamondTrap # destroyed");
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

void DiamondTrap::whoAmI() const
{
	std::cout << CYN << "I am a # DiamondTrap # named " << BOLD << _name << RESET << std::endl
		<< CYN << "ClapTrap-Name: " << BOLD << DiamondTrap::ClapTrap::_name << RESET << std::endl;
}
