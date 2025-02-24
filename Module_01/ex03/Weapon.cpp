#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

//using a getter by reference to avoid a having to do a full copy of the string
const std::string	&Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
