#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::_debug( void ) const
{
	std::cout << "Debug" << std::endl;
}

void	Harl::_info( void ) const
{
	std::cout << "Info" << std::endl;
}

void	Harl::_warning( void ) const
{
	std::cout << "Warning" << std::endl;
}

void	Harl::_error( void ) const
{
	std::cout << "Error" << std::endl;
}

void	Harl::complain( const std::string level ) const
{
	typedef	void(Harl::*FunctionPointer) () const;
	FunctionPointer MembFunctions[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string FktNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (unsigned int i = 0; i < 4; i++)
	{
		if (level == FktNames[i])
		{
			(this->*MembFunctions[i]) ();
			return ;
		}
	}
}
