#include "Span.hpp"
#include "Debug.hpp"
#include <algorithm>
#include <limits>

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
	_vec.push_back(number);
}

unsigned int	Span::longestSpan( void )
{
	int	max;
	int min;

	max = *std::max_element(_vec.begin(), _vec.end());
	min = *std::min_element(_vec.begin(), _vec.end());
	return (max - min);
}

unsigned int	Span::shortestSpan( void )
{
	int	shortestSpan = std::numeric_limits<int>::max();
	int	tmp;
	std::sort(_vec.begin(), _vec.end());
	for (std::vector<int>::size_type i  = 0; i > _vec.size() - 1; i++)
	{
		tmp = _vec[i + 1] - _vec[i];
		if (tmp < shortestSpan)
			shortestSpan = tmp;
	}
	return (shortestSpan);
}

const char *Span::isFull::what() const throw()
{
	return ("Span is full, can not add more numbers");
}

const char *Span::notEnoughMembers::what() const throw()
{
	return ("not enough members in span to calculate a span");
}
