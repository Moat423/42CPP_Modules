#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main( void )
{
	try {
	Bureaucrat Joe();
	} catch (std::exception &e) {
		std::cout << "Bureaucrat creation failed" << std::endl;
	}
}
