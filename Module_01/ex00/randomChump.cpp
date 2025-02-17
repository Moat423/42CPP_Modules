#include "Zombie.hpp"

// zombie gets created on stack and automatically destroyed as this function ends
void	randomChump( std::string name )
{
	Zombie zombie(name);
	zombie.announce();
}
