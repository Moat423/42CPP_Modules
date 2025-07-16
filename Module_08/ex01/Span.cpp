#include "Span.hpp"
#include "Debug.hpp"
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

// Default Constructor
Span::Span( void )
{
	debug("Span Constructor called");
}

// Parameterized Constructor
Span::Span( unsigned int maxSize ):_maxSize(maxSize)
{
	debug("Span maxsize constructor called");
}

// Destructor
Span::~Span()
{
	debug("Span Destructor called");
}

// Copy Constructor
Span::Span(const Span &rhs):_maxSize(rhs._maxSize), _vec(rhs._vec)
{
	debug("Span copy constructor called");
}

// Copy Assignment Operator
Span& Span::operator=( const Span &rhs )
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_vec = rhs._vec;
	}
	return *this;
}

void	Span::addNumber( int number )
{
	if (_maxSize == _vec.size())
		throw Span::isFull();
	_vec.push_back(number);
}

unsigned int	Span::longestSpan( void )
{
	int	max;
	int min;

	if (_vec.size() <= 1)
		throw Span::notEnoughMembers();
	max = *std::max_element(_vec.begin(), _vec.end());
	min = *std::min_element(_vec.begin(), _vec.end());
	return (max - min);
}

unsigned int	Span::shortestSpan( void )
{
	int	shortestSpan = std::numeric_limits<int>::max();
	int	tmp;

	if (_vec.size() <= 1)
		throw Span::notEnoughMembers();
	std::sort(_vec.begin(), _vec.end());
	for (std::vector<int>::size_type i  = 0; i < _vec.size() - 1; i++)
	{
		tmp = _vec[i + 1] - _vec[i];
		if (tmp < shortestSpan)
			shortestSpan = tmp;
	}
	return (shortestSpan);
}

void	Span::printSpan( void )
{
	std::vector<int>::size_type i = 0;
	std::cout << "{";
	while (i < _vec.size() - 1)
		std::cout << _vec[i++] << ", ";
	std::cout << _vec[i];
	std::cout << "}" << std::endl;
}

const char *Span::isFull::what() const throw()
{
	return ("Span is full, can not add more numbers");
}

const char *Span::notEnoughMembers::what() const throw()
{
	return ("not enough members in span to calculate a span");
}
