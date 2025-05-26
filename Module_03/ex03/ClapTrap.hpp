#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

# ifndef BASE_MAX_HP
#  define BASE_MAX_HP 10
# endif // BASE_MAX_HP

class ClapTrap
{
	public:
		virtual ~ClapTrap();
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& rhs);
		ClapTrap	&operator=(const ClapTrap& rhs);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
	protected:
		std::string 		_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
		void				exhaustMsg(const std::string action) const;
		void				deadMsg(const std::string action) const;
};

#endif // CLAPTRAP_HPP
