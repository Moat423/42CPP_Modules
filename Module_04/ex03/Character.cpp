#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

//TODO: chacater inventory
Character::Character(std::string const name): _name(name)
{
	std::cout << "Character " << _name << " is created" << std::endl;
}

Character::~Character()
{
	std::cout << "Character " << _name << " destroyed" << std::endl;
}

Character::Character(const Character &copy): _name(copy._name)
{
	std::cout << "Character copy constructor called" << std::endl;
}

Character  &Character::operator=(const Character &assign)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &assign)
		this->_name = assign._name;
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::use(int idx, Character& target)
{
	this->_inventory[idx]->use(target);
}
