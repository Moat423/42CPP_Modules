#include "Span.hpp"
#include "Debug.hpp"

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
	//TODO: does this deepcopy?
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

