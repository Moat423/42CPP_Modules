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

void	Harl::_ramble( void ) const
{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::filteredComplain( const std::string level ) const
{
	typedef	void(Harl::*FunctionPointer) () const;
	FunctionPointer MembFunctions[5] = {
		&Harl::_debug, 
		&Harl::_info, 
		&Harl::_warning, 
		&Harl::_error, 
		&Harl::_ramble
	};
	std::string FktNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	unsigned int	intLevel = 0;

	while (intLevel < 4)
	{
		if (level == FktNames[intLevel])
			break ;
		intLevel++;
	}

	switch (intLevel)
	{
		case DEBUG:
			(this->*MembFunctions[DEBUG]) ();
			//intentional fallthrough
		case INFO:
			(this->*MembFunctions[INFO]) ();
			//intentional fallthrough
		case WARNING:
			(this->*MembFunctions[WARNING]) ();
			//intentional fallthrough
		case ERROR:
			{
				(this->*MembFunctions[ERROR]) ();
				break;
			}
		default:
			(this->*MembFunctions[DFL]) ();
	}
}
