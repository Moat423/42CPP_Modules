#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

# ifndef BASE_MAX_HP
#  define BASE_MAX_HP 10
# endif // BASE_MAX_HP

class ScavTrap
{
	public:
		ScavTrap();
		ScavTrap(const char *name);
		~ScavTrap();
		ScavTrap(const ScavTrap &rhs);
		ScavTrap &operator=(const ScavTrap &rhs);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		const char	*getName(void);
		void	exhaustMsg(const std::string action) const;
		void	deadMsg(const std::string action) const;
	private:
		const char *_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif // CLAPTRAP_HPP
