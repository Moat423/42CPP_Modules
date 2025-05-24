#include "Brain.hpp"
#include "Debug.hpp"
#include <string>

Brain::Brain()
{
	std::cout << BLUE << "Brain has been created" << RESET << std::endl;
}

Brain::~Brain()
{

	std::cout << BLUE << "Brain has been destroyed" << RESET << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << BLUE << "Brain copy constructor called" << RESET << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &assignment)
{
	std::cout << BLUE << "Brain copy assignment constructor called" << RESET << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = assignment._ideas[i];
	return (*this);
}

std::string	Brain::getIdea( const size_t index) const
{
	return (this->_ideas[index]);
}

void Brain::setIdea(const size_t index, const std::string idea)
{
	this->_ideas[index] = idea;
}
