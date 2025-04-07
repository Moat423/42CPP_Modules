#include "ClapTrap.hpp"
#include <iostream>
#include <iterator>
#include <ostream>

int	main( void )
{
	ClapTrap	dummy;
	ClapTrap	npc("npc");
	ClapTrap	helper(dummy);
	dummy.attack("the air");
	std::cout << "the air took no damage, but npc is shocked" << std::endl;
	npc.takeDamage(0);
	npc.beRepaired(0);
	npc.beRepaired(5);
	dummy.attack("the space");
	std::cout << "helper takes imaginary damage" << std::endl;
	helper.takeDamage(0);
	for (int i = 0; i < 10; i++)
	{
		dummy.attack("his imagination");
		npc.takeDamage(0);
	}
	dummy.beRepaired(5);
	npc.beRepaired(9);
	for (int i = 0; i < 7; i++)
	{
		npc.beRepaired(1);
		std::cout << "but he didn't need to be beRepaired" << std::endl;
	}
	npc.beRepaired(1);
}
