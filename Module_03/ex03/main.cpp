#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap	tim("Tim");
	DiamondTrap	dude;
	DiamondTrap	timsTwin(tim);
	tim.highFivesGuys();
	tim.whoAmI();
	dude.whoAmI();
}
