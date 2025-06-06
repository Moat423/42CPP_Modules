#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <ostream>
#include "Debug.hpp"

int	main( void )
{
	ClapTrap	dummy;
	ClapTrap	npc("npc");
	ScavTrap	SC4V_TRAP;
	ScavTrap	paul("Paul");
	ScavTrap	SC4V_TRAP2(SC4V_TRAP);
	//testing for correct destruction
	ClapTrap	*pretender = new ScavTrap("pretender");
	ClapTrap	mutant(*pretender);
	delete pretender;
	mutant.beRepaired(100);
	mutant.attack("himself");
	for (int i = 0; i < 10; i++)
	{
		dummy.attack("his imagination");
		npc.takeDamage(0);
	}
	dummy.beRepaired(5);
	dummy.attack("one too many times");
	for (int i = 0; i < 11; i++)
		npc.beRepaired(1);
	std::cout << std::endl;
	std::cout << CYN << "the ScavTraps have had enough and now it's their turn!!" << RESET << std::endl;
	paul.takeDamage(110);
	for (int i = 0; i < 50; i++)
	{
		SC4V_TRAP.attack("his imagination WITH RANGE");
		mutant.attack("flailing arround");
	}
	SC4V_TRAP.beRepaired(5);
	SC4V_TRAP.attack("one too many times WITH RANGE");
	paul.beRepaired(1);
	paul.guardGate();
	SC4V_TRAP.guardGate();
	SC4V_TRAP2.guardGate();
}
