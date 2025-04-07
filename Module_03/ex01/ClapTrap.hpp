#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

/*Name, which is passed as a parameter to the constructor*/
/*• Hit points (10), representing the health of the ClapTrap*/
/*• Energy points (10)*/
/*• Attack damage (0)*/
/*Add the following public member functions so that the ClapTrap behaves more real-*/
/*istically:*/
/*• void attack(const std::string& target);*/
/*• void takeDamage(unsigned int amount);*/
/*• void beRepaired(unsigned int amount);*/

# ifndef BASE_MAX_HP
#  define BASE_MAX_HP 10
# endif // BASE_MAX_HP

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const char *name);
		~ClapTrap();
		ClapTrap(const ClapTrap &rhs);
		ClapTrap &operator=(const ClapTrap &rhs);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	exhaustMsg(const std::string action) const;
		void	deadMsg(const std::string action) const;
	protected:
		const char *_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif // CLAPTRAP_HPP
