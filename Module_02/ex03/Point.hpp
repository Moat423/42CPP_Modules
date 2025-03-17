#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point( void );
		Point( const float x, const float y );
		~Point( void );
		Point(const Point &rhs);
		Point operator=(Point const &rhs);
		Fixed getX( void ) const;
		Fixed getY( void ) const;
};

# endif // POINT_HPP
