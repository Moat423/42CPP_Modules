#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	dummy;
	ClapTrap	npc("standard");
	ClapTrap	helper("helper");
	dummy.attack(npc.getName());
	npc.takeDamage(0);
	npc.beRepaired(0);
	npc.beRepaired(5);
	for (int i = 0; i < 10; i++)
	{
		dummy.attack(npc.getName());
		npc.takeDamage(0);
	}
	npc.beRepaired(9);
}
