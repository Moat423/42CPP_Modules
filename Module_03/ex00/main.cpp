#include "ClapTrap.hpp"
#include <iostream>
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
	for (int i = 0; i < 9; i++)
	{
		dummy.attack("his imagination");
		npc.takeDamage(1);
		helper.takeDamage(2);
	}
	helper.beRepaired(10);
	dummy.beRepaired(5);
	npc.beRepaired(5);
	for (int i = 0; i < 7; i++)
		npc.beRepaired(1);
	npc.beRepaired(1);
}
