#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	dummy;
	ClapTrap	npc("npc");
	ClapTrap	helper(dummy);
	dummy.attack(npc.getName());
	npc.takeDamage(0);
	npc.beRepaired(0);
	npc.beRepaired(5);
	dummy.attack(helper.getName());
	helper.takeDamage(0);
	for (int i = 0; i < 10; i++)
	{
		dummy.attack(npc.getName());
		npc.takeDamage(0);
	}
	dummy.beRepaired(5);
	
	npc.beRepaired(9);
	for (int i = 0; i < 9; i++)
	{
		npc.beRepaired(1);
	}
}
