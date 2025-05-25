#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class Character: public ICharacter
{
	public:
		Character(std::string name);
		~Character();
		Character(const Character &copy);
		Character &operator=(const Character &assign);

		std::string const & getName() const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, Character& target);
	private:
		std::string	_name;
		AMateria	*_inventory[4];
};

#endif // !CHARACTER_HPP
