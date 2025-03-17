#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

Fixed	area(Point const a, Point const b, Point const c)
{
	return Fixed::abs(a.getX() * (b.getY() - c.getY()) + 
			b.getX() * (c.getY() - a.getY()) + 
			c.getX() * (a.getY() - b.getY()) / Fixed(2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	pab = area(point, a, b);
	Fixed	pbc = area(point, b, c);
	Fixed	pac = area(point, a, c);
	if (pab == 0 || pbc == 0 || pac == 0)
		return (false);
	Fixed	total_area = area(a, b, c);
	if (pab + pbc + pac == total_area)
		return (true);
	return (false);
}
