#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character(std::string const name): _name(name), _inventory()
{
	std::cout << "Character " << _name << " is created" << std::endl;
}

Character::~Character()
{
	std::cout << "Character " << _name << " destroyed" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character::Character(const Character &copy): _name(copy._name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}
}

Character  &Character::operator=(const Character &assign)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &assign)
	{
		this->_name = assign._name;
		for (size_t i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (assign._inventory[i])
				this->_inventory[i] = assign._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		std::cout << "Please give " << _name << " a valid index to one of her Materias" << std::endl;
	else if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
	 	std::cout << _name << "'s Materia at index " << idx << " does not exist yet!" << std::endl;
}

void Character::equip(AMateria* materia)
{
	int	i = 0;
	if (!materia)
	{
		std::cout << _name << " cannot equip empty materia" << std::endl;
		return ;
	}
	while (i < 4)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = materia;
			std::cout << "Materia "
				<< this->_inventory[i]->getType()
				<< " equipped to "
				<< this->_name
				<< "'s inventory at index "
				<< i << std::endl;
			return ;
		}
		i++;
	}
	if (i == 4)
		std::cout << _name << " cannot equip the materia, their inventory is full !!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		std::cout << "Unequipped "
			<< this->_inventory[idx]->getType() << " from "
			<< this->_name << "'s inventory at index "
			<< idx << std::endl;
		this->_inventory[idx] = NULL;
	}
	else if (idx < 0 || idx >= 4)
		std::cout << "Cannot unequip materia, invalid index " << idx << std::endl;
	else
		std::cout << "Cannot unequip materia, index " << idx << " is empty!" << std::endl;
}
