#include "ScavTrap.hpp"
#include "Debug.hpp"
#include <iostream>
#include <ostream>

ScavTrap::ScavTrap( void ):
	_name("default"), _hitPoints(BASE_MAX_HP), _energyPoints(10), _attackDamage(0)
{
	debug("[ ScavTrap ] constructed");
}

ScavTrap::ScavTrap( const char *name ):
	_name(name), _hitPoints(BASE_MAX_HP), _energyPoints(10), _attackDamage(0)
{
	debug("[ ScavTrap ] constructed with name");
}

ScavTrap::ScavTrap( const ScavTrap &rhs ):
	_name(rhs._name), 
	_hitPoints(rhs._hitPoints),
	_energyPoints(rhs._energyPoints), 
	_attackDamage(rhs._attackDamage)
{
	debug("[ ScavTrap ] copy constructed");
}

ScavTrap::~ScavTrap()
{
	debug("[ ScavTrap ] destroyed");
}

ScavTrap &ScavTrap::operator=( const ScavTrap &rhs )
{
	_name = rhs._name;
	_attackDamage = rhs._attackDamage;
	_energyPoints = rhs._energyPoints;
	_hitPoints = rhs._hitPoints;
	return (*this);
}

const char	*ScavTrap::getName( void )
{
	return (_name);
}

void	ScavTrap::exhaustMsg(const std::string action) const
{
	std::cout << BLUE <<
		"[ ScavTrap ] " << _name << " is exhausted and can't " << action << " anymore!" <<
		RESET << std::endl;
	return;
}

void	ScavTrap::deadMsg(const std::string action) const
{
	std::cout << BRED <<
	"[ ScavTrap ] " << _name << " is dead and can't " << action << " anymore!" <<
	RESET << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
	{
		exhaustMsg("attack");
		return ;
	}
	if (_hitPoints == 0)
	{
		return ;
	}
	_energyPoints--;
	std::cout << RED <<
		"[ ScavTrap ] " << (_name ? _name : "null")  <<
		" attacks " << target <<
		", causing " << _attackDamage  <<
		" points of damage!" <<
		RESET << std::endl;
}

void ScavTrap::takeDamage( unsigned int amount )
{
	int	tmp_hp;

	if (_hitPoints == 0)
	{
		exhaustMsg("take damage");
		return ;
	}
	tmp_hp = _hitPoints - amount;
	_hitPoints = tmp_hp > 0 ? tmp_hp : 0;
	std::cout << YEL <<
		"[ ScavTrap ] " << (_name ? _name : "null") <<
		" got damaged for " << amount <<
		" and has " << _hitPoints <<
		" Hit Points left." <<
		RESET << std::endl;
	return ;
}

void ScavTrap::beRepaired( unsigned int amount )
{
	int	tmp_hp;

	if (_hitPoints == 0)
	{
		deadMsg("repair itself");
		return ;
	}
	if (_energyPoints == 0)
	{
		exhaustMsg("repair itself");
		return ;
	}
	--_energyPoints;
	tmp_hp = _hitPoints + amount;
	_hitPoints = tmp_hp >= BASE_MAX_HP ? BASE_MAX_HP : tmp_hp;
	std::cout << GREEN <<
		"[ ScavTrap ] " << (_name ? _name : "null") <<
		" got repaired for " << amount <<
		" and has " << _hitPoints <<
		" Hit Points left." << 
		RESET << std::endl;
	return ;
}
