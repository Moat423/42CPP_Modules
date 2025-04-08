#include "Debug.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <ostream>

int	main( void )
{
	ClapTrap	dummy;
	ClapTrap	npc("npc");
	ScavTrap	SC4V_TRAP;
	ScavTrap	paul("Paul");
	//testing for correct destruction
	ClapTrap	*pretender = new FragTrap("pretender");
	ClapTrap	mutant(*pretender);
	FragTrap	anon;
	FragTrap	FR4G_TRAP(anon);
	FragTrap	FR4G_TRAP2("Frederick");
	pretender->takeDamage(50);
	pretender->beRepaired(30);
	pretender->beRepaired(30);
	pretender->takeDamage(100);
	pretender->attack("nothing");
	pretender->takeDamage(80);
	pretender->beRepaired(20);
	delete pretender;
	anon.attack("a tumpling fly");
	anon.takeDamage(4);
	anon.highFivesGuys();
	FR4G_TRAP.highFivesGuys();
	FR4G_TRAP2.highFivesGuys();
	FR4G_TRAP.beRepaired(80);
	mutant.takeDamage(20);
	dummy.attack("his imagination");
	npc.takeDamage(0);
	dummy.beRepaired(5);
	dummy.attack("again");
	for (int i = 0; i < 11; i++)
		npc.beRepaired(1);

	std::cout << std::endl;
	std::cout << "the ScavTraps have had enough and now it's their turn!!" << RESET << std::endl;
	SC4V_TRAP.attack("his imagination WITH RANGE");
	paul.takeDamage(50);
	SC4V_TRAP.beRepaired(5);
	for (int i = 0; i < 11; i++)
		paul.beRepaired(20);
	SC4V_TRAP.attack("again WITH RANGE");
	paul.beRepaired(1);
	SC4V_TRAP.guardGate();
}
