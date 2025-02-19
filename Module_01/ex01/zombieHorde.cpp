
#include "Zombie.hpp"
#include <sstream>
#include <string>


//allocates N zombies on the heap in a single allocation
//initializes the zombies, giving each one of them the name passed as parameter
//returns a pointer to the first zombie
Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde = new Zombie[N];
	int		i = -1;

	while (++i < N)
	{
		std::ostringstream fullName;
		fullName << name << " nb. " << (i + 1);
		std::string newName;
		newName = fullName.str();
		horde[i].setName(newName);
	}
	return (horde);
}
