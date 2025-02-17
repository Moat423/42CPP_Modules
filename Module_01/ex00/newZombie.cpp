#include "Zombie.hpp"

//returns a reference of the created obj to the calling function, to manually 
//manage deletion of this zombie when needed
Zombie*	newZombie( std::string name )
{
	return (new Zombie(name));
}
