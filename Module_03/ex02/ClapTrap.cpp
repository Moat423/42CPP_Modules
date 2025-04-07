#include "ClapTrap.hpp"
#include "Debug.hpp"
#include <iostream>
#include <ostream>

ClapTrap::ClapTrap( void ):
	_name("default"), _hitPoints(BASE_MAX_HP), _energyPoints(10), _attackDamage(0)
{
	debug("ClapTrap constructed");
}

ClapTrap::ClapTrap( const char *name ):
	_name(name), _hitPoints(BASE_MAX_HP), _energyPoints(10), _attackDamage(0)
{
	debug("ClapTrap constructed with name");
}

ClapTrap::ClapTrap( const ClapTrap &rhs ):
	_name(rhs._name), 
	_hitPoints(rhs._hitPoints),
	_energyPoints(rhs._energyPoints), 
	_attackDamage(rhs._attackDamage)
{
	debug("ClapTrap copy constructed");
}

ClapTrap::~ClapTrap()
{
	debug("ClapTrap destroyed");
}

ClapTrap &ClapTrap::operator=( const ClapTrap &rhs )
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

void	ClapTrap::exhaustMsg(const std::string action) const
{
	std::cout << BLUE <<
		"ClapTrap " << _name << " is exhausted and can't " << action << " anymore!" <<
		RESET << std::endl;
	return;
}

void	ClapTrap::deadMsg(const std::string action) const
{
	std::cout << BRED <<
	"ClapTrap " << _name << " is dead and can't " << action << " anymore!" <<
	RESET << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
	{
		exhaustMsg("attack");
		return ;
	}
	if (_hitPoints == 0)
	{
		deadMsg("attack");
		return ;
	}
	_energyPoints--;
	std::cout << RED <<
		"ClapTrap " << (_name ? _name : "null")  <<
		" attacks " << target <<
		", causing " << _attackDamage  <<
		" points of damage!" <<
		RESET << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	int	tmp_hp;

	if (_hitPoints == 0)
	{
		deadMsg("take damage");
		return ;
	}
	tmp_hp = _hitPoints - amount;
	_hitPoints = tmp_hp > 0 ? tmp_hp : 0;
	std::cout << YEL <<
		"ClapTrap " << (_name ? _name : "null") <<
		" got damaged for " << amount <<
		" and has " << _hitPoints <<
		" Hit Points left." <<
		RESET << std::endl;
	return ;
}

void ClapTrap::beRepaired( unsigned int amount )
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
	_hitPoints = tmp_hp >= 100 ? 100 : tmp_hp;
	std::cout << GREEN <<
		"ClapTrap " << (_name ? _name : "null") <<
		" got repaired for " << amount <<
		" and has " << _hitPoints <<
		" Hit Points left." << 
		RESET << std::endl;
	return ;
}
