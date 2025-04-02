#include "Point.hpp"
#include <iostream>
#include <ostream>

//TODO: remove the debug to enforce c++98 standard
//TODO: do an approximateEqual

//smallest representable number: 0.00390625f
bool	approximateExqual(Fixed a, Fixed b, Fixed epsilon = Fixed(0.00390625f))
{
	Fixed	tmp = a - b;
	return (tmp <= epsilon || tmp >= epsilon * -1);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point);

//abs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2
Fixed	area(Point const a, Point const b, Point const c)
{
	return Fixed::abs((a.getX() * (b.getY() - c.getY()) + 
			b.getX() * (c.getY() - a.getY()) + 
			c.getX() * (a.getY() - b.getY())) / Fixed(2));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed minX = Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX());
    Fixed maxX = Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX());
    Fixed minY = Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY());
    Fixed maxY = Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY());
	if (point.getX() < minX || point.getX() > maxX || point.getY() < minX || point.getY() > maxX)
		return (false);
	try {
		Fixed	pab = area(point, a, b);
		Fixed	pbc = area(point, b, c);
		Fixed	pac = area(point, a, c);
		if (pab == 0 || pbc == 0 || pac == 0)
			return (false);
		Fixed	total_area = area(a, b, c);
		Fixed	sum = pab + pac + pbc;
		return (approximateExqual(sum, total_area));
	}
	catch (const std::exception&) {
		std::cout << "overflow occured" << std::endl;
		return (false);
	}
}
