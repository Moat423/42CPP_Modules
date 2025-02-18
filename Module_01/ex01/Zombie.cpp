#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "A Zombie named " << _name << "has risen from the ground and starts walking towards you" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << GREEN << _name << " collapses and lays still, unmoving, as if nothing ever happened" << RESET << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << BRED << _name << ": " << RESET << RED << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
