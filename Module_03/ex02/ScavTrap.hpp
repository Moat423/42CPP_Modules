#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>

# ifndef SCAV_MAX_HP
#  define SCAV_MAX_HP 100
# endif // SCAV_MAX_HP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const char *name);
		~ScavTrap();
		ScavTrap(const ScavTrap &rhs);
		ScavTrap &operator=(const ScavTrap &rhs);
		void	attack(const std::string& target);
		void	guardGate(void) const;
	private:
};

#endif // SCAVTRAP_HPP
