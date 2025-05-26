#include "Character.hpp"
#include "ICharacter.hpp"
#include "Debug.hpp"

Character::Character(std::string const name): _name(name), _inventory()
{
	debug("Character " << _name << " is created");
}

Character::~Character()
{
	debug("Character " << _name << " destroyed");
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
	debug("Character assignment operator called");
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
	if (idx < 0 || idx >= 4){
		debug("Please give " << _name << " a valid index to one of her Materias");
	}
	else if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else{
		debug("" << _name << "'s Materia at index " << idx << " does not exist yet!");
	}
}

void Character::equip(AMateria* materia)
{
	int	i = 0;
	if (!materia)
	{
		debug(" cannot equip empty materia");
		return ;
	}
	while (i < 4)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = materia;
			debug("Materia "
				<< this->_inventory[i]->getType()
				<< " equipped to "
				<< this->_name
				<< "'s inventory at index "
				<< i);
			return ;
		}
		i++;
	}
	if (i == 4){
		debug(" cannot equip the materia, their inventory is full !!");
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		debug("Unequipped "
			<< this->_inventory[idx]->getType() << " from "
			<< this->_name << "'s inventory at index "
			<< idx);
		this->_inventory[idx] = NULL;
	}
	else if (idx < 0 || idx >= 4){
		debug("Cannot unequip materia, invalid index " << idx);
	}
	else{
		debug("Cannot unequip materia, index " << idx << " is empty!");
	}
}
