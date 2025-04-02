#include "Zombie.hpp"
#include <iostream>
#include <ostream>


int	main (void)
{
	std::cout << "On the horizon the main bump. A large " << BOLD << "stack" << RESET << " of wood, thereupon lies an unmoving corpse" << std::endl;
	Zombie zombie1("Shaun");
	std::cout << "it growls at you:" << std::endl;
	zombie1.announce();

	std::cout << "You turn around to run away, but on the horizon you see a horde of zombies approaching" << std::endl;
	Zombie *horde = zombieHorde(HORDENUM, "Horton");
	for (int i = 0; i < HORDENUM; i++)
		horde[i].announce();

	std::cout << YEL << "By a saving grace, the first sunrays touch the horizon, as it deletes the ZombieHorde" << RESET << std::endl;
	delete [] horde;
	
	std::cout << YEL << "Day has come, the sun is about to ";
	std::cout << BOLD << "return" << RESET << YEL;
	std::cout << " even the zombies from the "<< BOLD << "stack" << RESET << YEL <<" to the ground" << RESET << std::endl;
	return 0;
}
