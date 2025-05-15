#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "Debug.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ): ClapTrap()
{
	ClapTrap::_name = "default_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	debug("# DiamondTrap # constructed");
}

DiamondTrap::DiamondTrap( const std::string& name ): ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
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
		<< CYN << "My ClapTrap-Name is: " << BOLD << DiamondTrap::ClapTrap::_name << RESET << std::endl;
}
