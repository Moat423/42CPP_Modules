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

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(char *name);
		~ClapTrap();
		ClapTrap(const ClapTrap &rhs);
		ClapTrap &operator=(const ClapTrap &rhs);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		const char	*getName(void);
	private:
		const char	*_name;
		int		_hitPoints;
		int		_energyPoints;
		int		_attackDamage;
};

#endif // CLAPTRAP_HPP
