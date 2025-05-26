#include "DiamondTrap.hpp"
#include <iostream>

int	main( void )
{
	DiamondTrap	tim("Tim");
	DiamondTrap	dude;
	DiamondTrap	timsTwin(tim);
	tim.highFivesGuys();
	tim.whoAmI();
	dude.whoAmI();
	tim.attack("default");
	dude.takeDamage(30);
	dude.beRepaired(50);
	std::cout << "testing death:" << std::endl;
	dude.takeDamage(100);
	dude.beRepaired(50);
	dude.guardGate();
	dude.highFivesGuys();
	dude.takeDamage(9);
}
