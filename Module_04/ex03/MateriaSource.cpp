
#include "AMateria.hpp"
#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _learnInventory()
{
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i])
			delete this->_learnInventory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy): _learnInventory()
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (copy._learnInventory[i])
			this->_learnInventory[i] = copy._learnInventory[i];
	}
}

MateriaSource  &MateriaSource::operator=(const MateriaSource &assign)
{
	if (this != &assign)
	{
		std::cout << "MateriaSource assignment operator called" << std::endl;
		for (size_t i = 0; i < 4; i++)
		{
			if (assign._learnInventory[i])
				this->_learnInventory[i] = assign._learnInventory[i];
		}
	}
	return (*this);
}

/*
 *Copies the Materia passed as a parameter and stores it in memory so it can be cloned
later. Like the Character, the MateriaSource can know at most 4 Materias. They
are not necessarily unique
*/
void MateriaSource::learnMateria(AMateria* blueprint)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (blueprint && this->_learnInventory[i] == NULL)
		{
			this->_learnInventory[i] = blueprint;
			std::cout << "MateriaSource learned the blueprint for " << blueprint->getType() << std::endl;
		}
		return ;
	}
	if (blueprint)
		std::cout << "can not learn Materia, inventory is full!" << std::endl;
}

/*Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown.
*/
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i]->getType() == type)
			return (_learnInventory[i]->clone());
	}
	return (NULL);
}
