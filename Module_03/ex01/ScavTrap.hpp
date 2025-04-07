#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>

# ifndef SCAV_MAX_HP
#  define SCAV_MAX_HP 10
# endif // SCAV_MAX_HP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		void	attack(const std::string& target);
		const char	*getName(void);
		void	guardGate(void) const;
	private:
		ScavTrap();
		ScavTrap(const char *name);
		~ScavTrap();
		ScavTrap(const ScavTrap &rhs);
		ScavTrap &operator=(const ScavTrap &rhs);
};

#endif // SCAVTRAP_HPP
