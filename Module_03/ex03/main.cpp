#include "Debug.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

int	main( void )
{
	DiamondTrap	tim("Tim");
	DiamondTrap	dude;
	DiamondTrap	timsTwin(tim);
	tim.highFivesGuys();
	tim.whoAmI();
	dude.whoAmI();
}
