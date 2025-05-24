#include "Cat.hpp"
#include <iostream>
#include <new>
#include "Debug.hpp"

Cat::Cat( void ): Animal("Cat")
{
	std::cout << RED << "🐱 Default constructor called" << RESET << std::endl;
	try {
	_brain = new Brain;
	} catch (const std::bad_alloc &e) {
		std::cerr << "Memory allocation failed" << e.what() << std::endl;
	}
}

Cat::~Cat( void )
{
	std::cout << RED << "🐱 Destructor called" << RESET << std::endl;
}

Cat::Cat( const Cat &copy): Animal( copy )
{
	std::cout << RED << "🐱 Copy constructed" << RESET << std::endl;
}

Cat &Cat::operator=( const Cat &assign )
{
	std::cout << RED << "🐱 Assignment Operator called" << RESET << std::endl;
	if (this != &assign)
		type = assign.getType();
	return (*this);
}

std::string Cat::getType() const
{
	return (type);
}

void Cat::makeSound( void ) const
{
	std::cout << RED << "😺 MEOOOOW ("<< getType() << " is meowing)" << RESET << std::endl;
}
