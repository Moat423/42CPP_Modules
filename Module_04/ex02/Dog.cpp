#include "Dog.hpp"
#include <iostream>
#include "Debug.hpp"

Dog::Dog( void ): A_Animal("Dog")
{
	std::cout << CYN << "🐶 Default constructor called" << RESET << std::endl;
	try {
	_brain = new Brain;
	} catch (const std::bad_alloc &e) {
		std::cerr << "Memory allocation failed" << e.what() << std::endl;
	}
}

Dog::~Dog( void )
{
	std::cout << CYN << "🐶 Destructor called" << RESET << std::endl;
	delete _brain;
}

Dog::Dog( const Dog &copy): A_Animal( copy ), _brain(new Brain(*copy._brain))
{
	std::cout << CYN << "🐶 Copy constructed" << RESET << std::endl;
}

Dog &Dog::operator=( const Dog &assign )
{
	std::cout << CYN << "🐶 Assignment Operator called" << RESET << std::endl;
	if (this != &assign)
	{
		type = assign.getType();
		_brain = assign._brain;
	}
	return (*this);
}

std::string Dog::getType() const
{
	return (type);
}

void Dog::makeSound( void ) const
{
	std::cout << CYN << "🐶 Wau wau ("<< getType() << " is barking)" << RESET << std::endl;
}

std::string	Dog::getIdea( const size_t index) const
{
	return (_brain->getIdea(index));
}

void Dog::setIdea(const size_t index, const std::string idea) const
{
	std::cout << CYN << getType() << " is having an idea" << RESET << std::endl;
	this->_brain->setIdea(index, idea);
}

void Dog::printIdeas( void ) const
{
	std::cout << CYN << getType() << "'s idias:" << RESET << std::endl;
	this->_brain->printIdeas();
}
