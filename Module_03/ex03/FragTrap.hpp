#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

# ifndef FRAG_MAX_HP
#  define FRAG_MAX_HP 100
# endif // FRAG_MAX_HP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		~FragTrap();
		FragTrap(const FragTrap& rhs);
		FragTrap &operator=(const FragTrap& rhs);
		void	attack(const std::string& target);
		void	highFivesGuys(void) const;
	protected:
		unsigned int		_hitPoints;
		unsigned int		_attackDamage;
};

#endif // FRAGTRAP_HPP
