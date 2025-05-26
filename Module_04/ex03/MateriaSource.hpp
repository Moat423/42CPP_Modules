#ifndef MATERASOURCE_HPP
# define MATERASOURCE_HPP
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
        MateriaSource( MateriaSource const & );

        MateriaSource&  operator=( MateriaSource const & );

		void learnMateria(AMateria*);
	 	AMateria* createMateria(std::string const & type);
	private:
		AMateria	*_learnInventory[4];
};

#endif // !MATERASOURCE_HPP
