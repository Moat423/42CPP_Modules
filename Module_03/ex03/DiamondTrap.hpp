#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# ifndef DIAMOND_MAX_HP
#  define DIAMOND_MAX_HP 100
# endif // DIAMOND_MAX_HP

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const char *name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &rhs);
		DiamondTrap &operator=(const DiamondTrap &rhs);
		using ScavTrap::attack;
		void whoAmI() const;
	private:
		std::string _name;
};

#endif // DIAMONDTRAP_HPP
