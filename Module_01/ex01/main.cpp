#include "Zombie.hpp"
#include <iostream>


int	main (void)
{
	Zombie *zombie2;

	std::cout << "On the horizon the main bump. A large " << BOLD << "stack" << RESET << " of wood, thereupon lies an unmoving corpse" << std::endl;
	Zombie zombie1("Shaun");
	std::cout << "it growls at you:" << std::endl;
	zombie1.announce();
	
	std::cout << "On the other side there is a giant " << BOLD << "heap" << RESET << " of corpses, scared, you look at them" << std::endl;
	zombie2 = newZombie("Henry");
	zombie2->announce();

	std::cout << "from somewhere, a completely random Zombie suddely appeared,";
	std::cout << "but it is contrained to it's small area.";
	std::cout << "As it left to wander towards you, it didn't get far" << std::endl;
	randomChump("Chump");
	
	std::cout << "Another Zombie arises from the " << BOLD << "heap" << RESET << std::endl;
	Zombie *zombie3 = newZombie("Harvy");
	zombie3->announce();
	delete zombie2;
	delete zombie3;

	std::cout << YEL << "Day has come, the sun is about to ";
	std::cout << BOLD << "return" << RESET << YEL;
	std::cout << " even the zombies from the "<< BOLD << "stack" << RESET << YEL <<" to the ground" << RESET << std::endl;
	return 0;
}
