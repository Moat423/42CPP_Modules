#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "Debug.hpp"
#include <iostream>
#include <ostream>

ScavTrap::ScavTrap( void ): ClapTrap()
{
	_hitPoints = SCAV_MAX_HP;
	_energyPoints = 50;
	_attackDamage = 20;
	debug("[ ScavTrap ] constructed");
}

ScavTrap::ScavTrap( const std::string &name ): ClapTrap(name)
{
	_hitPoints = SCAV_MAX_HP;
	_energyPoints = 50;
	_attackDamage = 20;
	debug("[ ScavTrap ] constructed with name");
}

ScavTrap::ScavTrap( const ScavTrap &rhs ): ClapTrap(rhs)
{
	/*_hitPoints = rhs._hitPoints;*/
	/*_energyPoints = rhs._energyPoints;*/
	/*_attackDamage = rhs._attackDamage;*/
	debug("[ ScavTrap ] copy constructed");
}

ScavTrap::~ScavTrap()
{
	debug("[ ScavTrap ] destroyed");
}

ScavTrap &ScavTrap::operator=( const ScavTrap &rhs )
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

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
	{
		std::cout << BLUE <<
		"[ ScavTrap ] " << _name << " is exhausted and can't attack anymore!" <<
		RESET << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << BRED <<
		"[ ScavTrap ] " << _name << " is dead and can't attack anymore!" <<
		RESET << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << RED <<
		"[ ScavTrap ] " << _name <<
		" attacks " << target <<
		", causing " << _attackDamage  <<
		" points of damage!" <<
		RESET << std::endl;
}

void	ScavTrap::guardGate(void) const
{
	if (_energyPoints == 0)
	{
		std::cout << BLUE <<
		"[ ScavTrap ] " << _name << " is exhausted and can't guard anymore!" <<
		RESET << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << BRED <<
		"[ ScavTrap ] " << _name << " is dead and can't guard anymore!" <<
		RESET << std::endl;
		return ;
	}
	std::cout << MAG <<
		"[ ScavTrap ] " << _name  <<
		" is now in GATE KEEPER MODE!" <<
		RESET << std::endl;
}
