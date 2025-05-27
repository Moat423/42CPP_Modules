#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "Debug.hpp"
#include <iostream>
#include <ostream>

FragTrap::FragTrap( void ): ClapTrap(), _hitPoints(FRAG_MAX_HP), _attackDamage(30)
{
	_hitPoints = FRAG_MAX_HP;
	_energyPoints = 100;
	_attackDamage = 30;
	debug("< FragTrap > constructed");
}


FragTrap::FragTrap(const std::string& name): ClapTrap(name), _hitPoints(FRAG_MAX_HP), _attackDamage(30)
{
	_hitPoints = FRAG_MAX_HP;
	_energyPoints = 100;
	_attackDamage = 30;
	debug("< FragTrap > constructed with name");
}

FragTrap::FragTrap( const FragTrap &rhs ): ClapTrap(rhs)
{
	debug("< FragTrap > copy constructed");
}

FragTrap::~FragTrap()
{
	debug("< FragTrap > destroyed");
}

FragTrap &FragTrap::operator=( const FragTrap &rhs )
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

void	FragTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
	{
		std::cout << BLUE <<
		"< FragTrap > " << _name << " is dead and can't attack anymore!" <<
		RESET << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << BRED <<
		"< FragTrap > " << _name << " is dead and can't attack anymore!" <<
		RESET << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << RED <<
		"< FragTrap > " << _name <<
		" attacks " << target <<
		", causing " << _attackDamage  <<
		" points of damage!" <<
		RESET << std::endl;
}

void	FragTrap::highFivesGuys(void) const
{
	if (_hitPoints == 0)
	{
		std::cout << BRED <<
		"< FragTrap > " << _name << " is dead and can't high-five anymore!" <<
		RESET << std::endl;
		return ;
	}
	std::cout << CYN <<
		"< FragTrap > " << _name  <<
		" is cheerfully requesting a high-five!" <<
		RESET << std::endl;
}
