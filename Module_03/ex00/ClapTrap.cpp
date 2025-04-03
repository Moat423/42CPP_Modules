#include "ClapTrap.hpp"
#include "Debug.hpp"
#include <iostream>
#include <ostream>

ClapTrap::ClapTrap( void ):
	_name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	debug("Default constructor called");
}

ClapTrap::ClapTrap( const char *name ):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	debug("Name constructor called");
}

ClapTrap::ClapTrap( const ClapTrap &rhs ):
	_name(rhs._name), 
	_hitPoints(rhs._hitPoints),
	_energyPoints(rhs._energyPoints), 
	_attackDamage(rhs._attackDamage)
{
	debug("Copy constructor called");
}

ClapTrap::~ClapTrap()
{
	debug("Destructor called");
}

ClapTrap &ClapTrap::operator=( const ClapTrap &rhs ){
	this->_name = rhs._name;
	this->_attackDamage = rhs._attackDamage;
	this->_energyPoints = rhs._energyPoints;
	this->_hitPoints = rhs._hitPoints;
	return (*this);
}

const char	*ClapTrap::getName( void )
{
	return (this->_name);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << (this->_name ? _name : "null") << " is exhausted and can't attack anymore" << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << (this->_name ? _name : "null") << " is dead and can't attack anymore" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << (this->_name ? _name : "null")  <<
		" attacks " << target <<
		", causing " << this->_attackDamage  <<
		" points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	int	tmp_hp;

	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << (this->_name ? _name : "null") << " is dead and can't take Damage anymore" << std::endl;
		return ;
	}
	this->_energyPoints--;
	tmp_hp = this->_hitPoints - amount;
	this->_hitPoints = tmp_hp > 0 ? tmp_hp : 0;
	std::cout << "ClapTrap " << (this->_name ? _name : "null") <<
		" got damaged for " << amount <<
		" and has " << this->_hitPoints <<
		" Hit Points left." << std::endl;
	return ;
}

void ClapTrap::beRepaired( unsigned int amount )
{
	int	tmp_hp;

	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << (this->_name ? _name : "null") << " is dead and can't be revived through repair" << std::endl;
		return ;
	}
	this->_energyPoints--;
	tmp_hp = this->_hitPoints + amount;
	this->_hitPoints = tmp_hp >= 10 ? 10 : tmp_hp;
	std::cout << "ClapTrap " << (this->_name ? _name : "null") <<
		" got repaired for " << amount <<
		" and has " << this->_hitPoints <<
		" left." << std::endl;
}
