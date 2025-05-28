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
	delete _brain;
}

Cat::Cat( const Cat &copy): Animal( copy ), _brain(new Brain(*copy._brain))
{
	std::cout << RED << "🐱 Copy constructed" << RESET << std::endl;
}

Cat &Cat::operator=( const Cat &assign )
{
	std::cout << RED << "🐱 Assignment Operator called" << RESET << std::endl;
	if (this != &assign)
	{
		type = assign.getType();
		*_brain = *assign._brain;
	}
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

std::string	Cat::getIdea( const size_t index) const
{
	return (_brain->getIdea(index));
}

void Cat::setIdea(const size_t index, const std::string idea) const
{
	std::cout << RED << getType() << " is having an idea" << RESET << std::endl;
	this->_brain->setIdea(index, idea);
}

void Cat::printIdeas( void ) const
{
	std::cout << RED << getType() << "'s idias:" << RESET << std::endl;
	this->_brain->printIdeas();
}
