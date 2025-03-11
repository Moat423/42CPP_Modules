#include "Harl.hpp"
#include <iostream>

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

void Harl::debug( void ) const
{
	std::cout << "🐛 :" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

void Harl::info( void ) const
{
	std::cout << "ℹ️  :" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void Harl::warning( void ) const
{
	std::cout << "⚠️  :" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";
	std::cout << std::endl;
}

void Harl::error( void ) const
{
	std::cout << "🚨 :" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain( const std::string level ) const
{
	typedef	void(Harl::*FunctionPointer) () const;
	FunctionPointer MembFunctions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string FktNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (unsigned int i = 0; i < 4; i++)
	{
		if (level == FktNames[i])
		{
			(this->*MembFunctions[i]) ();
			return ;
		}
	}
	std::cout << "No matching level found." << std::endl;
}
