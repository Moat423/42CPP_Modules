
		/*Point( void );*/
		/*~Point( void );*/
		/*Point(const Point &rhs);*/
		/*Point operator=(Point const &rhs);*/
		/*Fixed getX( void ) const;*/
		/*Fixed getY( void ) const;*/

#include "Point.hpp"
#include "Debug.hpp"

Point::Point( void ): x(0), y(0)
{
	debug("Default constructor called");
}

Point::~Point( void )
{
	debug("Destructor called");
}

Point::Point( const Point &rhs ): x(rhs.getX()), y(rhs.getY())
{
	debug("Copy constructor called");
}

Point Point::operator=( Point const &rhs )
{
	debug("Copy assignment operator called");
	if (this != &rhs)
	{
		Point	tmp(rhs);
		std::swap(*this, tmp);
	}
	return (*this);
}

Fixed Point::getX( void ) const
{
	debug("getX member function called");
	return x;
}

Fixed Point::getY( void ) const
{
	debug("getY member function called");
	return y;
}
