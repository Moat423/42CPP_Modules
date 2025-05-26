#include "Debug.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _learnInventory()
{
	debug("MateriaSource constructor called");
}

MateriaSource::~MateriaSource()
{
	debug("MateriaSource destructor called");
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i])
			delete this->_learnInventory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy): _learnInventory()
{
	debug("MateriaSource copy constructor called");
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
		debug("MateriaSource assignment operator called");
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
	if (!blueprint)
	{
		debug("MateriaSource can not learn from nothing");
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] == NULL)
		{
			this->_learnInventory[i] = blueprint;
			debug("MateriaSource learned the blueprint for " << blueprint->getType());
			return ;
		}
	}
	if (blueprint)
	{
		debug("can not learn Materia, " << blueprint->getType() << " inventory is full!");
		debug("MateriaSource dissolved the Materia " << blueprint->getType() << " because it could not hold it");
		delete blueprint;
	}
}

/*Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown.
*/
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] && this->_learnInventory[i]->getType() == type)
			return (_learnInventory[i]->clone());
	}
	debug("MateriaSource does not have a blueprint of the type " << type);
	return (NULL);
}
