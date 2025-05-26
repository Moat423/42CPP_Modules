#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "iostream"
#include <ostream>

int	subjectFunction();
int extensiveTestfuntion();

int	main()
{
	subjectFunction();
	return extensiveTestfuntion();
}

int	subjectFunction()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	if (!tmp)
		std::cout << "tmp for cure is NULL" << std::endl;
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

int extensiveTestfuntion()
{
	{
		std::cout << "1. Create new MateriaSource and learn materias (check maximum too):" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria *mat = new Cure();
		src->learnMateria(mat);
		std::cout << std::endl;
		
		std::cout << "2. Create 2 new characters and test deep copy:" << std::endl;
		Character *Alice = new Character("Alice");
		ICharacter *Alice1 = new Character(*Alice);
		delete Alice;
		delete Alice1;
		std::cout << std::endl;

		std::cout << "3. Create materias and equip them (also check unknown materias):" << std::endl;
		AMateria* tmp;
		ICharacter *Alice2 = new Character("Alice");
		tmp = src->createMateria("ice");
		Alice2->equip(tmp);
		tmp = src->createMateria("cure");
		Alice2->equip(tmp);
		tmp = src->createMateria("hi");
		Alice2->equip(tmp);
		delete src;
		std::cout << std::endl;

		std::cout << "4. Check maximum equipped too:" << std::endl;
		AMateria *cure = new Cure();
		AMateria *ice = new Ice();
		Alice2->equip(cure);
		Alice2->equip(cure);
		Alice2->equip(ice);
		Alice2->unequip(2);
		Alice2->unequip(2);
		Alice2->unequip(6);
		std::cout << "delteting ice beacause it's more than a Character can equipp" << std::endl;
		delete ice;
		std::cout << std::endl;

		std::cout << "5. Use materias on new chacarter:" << std::endl;
		ICharacter* bob = new Character("Bob");
		Alice2->use(0, *bob);
		Alice2->use(1, *bob);
		Alice2->use(2, *bob);
		Alice2->use(6, *bob);
		Alice2->use(-4, *bob);
		Alice2->use(3, *bob);
		delete bob;
		std::cout << std::endl;

		delete Alice2;

		return (0); 
	}
}
