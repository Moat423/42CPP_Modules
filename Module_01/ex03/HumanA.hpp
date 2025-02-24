#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		const Weapon		&_weapon;
	// HumanA has no weapon setter, therefore it will never change it, so it should be const
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA( void );
		void	attack( void ) const;
};
#endif // HUMANA_HPP
