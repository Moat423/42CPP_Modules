#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main( void )
{
	try {
	Bureaucrat joe;
	} catch (std::exception &e) {
		std::cout << "Bureaucrat (default) creation failed" << std::endl;
	}
	try {
	Bureaucrat paul("Paul", 2);
	} catch (std::exception &e) {
		std::cout << "Bureaucrat (grade 2) creation failed" << std::endl;
	}
	try {
	Bureaucrat tim("tim", 150);
	} catch (std::exception &e) {
		std::cout << "Bureaucrat (grade 2) creation failed" << std::endl;
	}
}
