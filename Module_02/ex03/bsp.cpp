#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

Fixed	area(Point const a, Point const b, Point const c)
{
	return Fixed::abs(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
}
