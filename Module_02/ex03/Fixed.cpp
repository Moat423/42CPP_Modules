#include "Fixed.hpp"
#include "Debug.hpp"
/*#include <iostream>*/
#include <cmath>

const int	Fixed::_fractional = 8;

// round function of my own static to only this file
static double myRound(double value)
{
    return (value >= 0.0) ? floor(value + 0.5) : ceil(value - 0.5);
}

Fixed::Fixed( void ):  _value(0)
{
	debug("Default constructor called");
}

Fixed::Fixed( const int value ): _value(value << this->_fractional)
{
	debug("Int constructor called");
}

Fixed::Fixed( const float value ): _value(static_cast<int>(myRound(value * (1 << this->_fractional))))
{
	debug("Float constructor called");
}

Fixed::~Fixed( void ) 
{
	debug("Destructor called");
}

Fixed::Fixed( const Fixed &rhs )
{
	debug("Copy constructor called");
	this->setRawBits(rhs.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	debug("Copy assignment operator called");
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return ( *this );
}

int		Fixed::getRawBits( void ) const
{
	debug("getRawBits member function called");
	return (this->_value);
}

void	Fixed::setRawBits( int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>( this->getRawBits() ) / ( 1 << _fractional );
}

int		Fixed::toInt( void ) const
{
	return (this->_value >> this->_fractional);
}

Fixed	&Fixed::min( Fixed &lhs, Fixed &rhs )
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	else
	 	return (rhs);
}

const Fixed	&Fixed::min( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	else
	 	return (rhs);
}

Fixed	&Fixed::max( Fixed &lhs, Fixed &rhs )
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	else
	 	return (rhs);
}

const Fixed	&Fixed::max( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	else
	 	return (rhs);
}

Fixed Fixed::fromRawBits(int rawBits)
{
	Fixed result;
	result._value = rawBits;
	return result;
}

Fixed &Fixed::abs(Fixed &value)
{
	if (value.getRawBits() < 0)
		value._value *= -1;
	return (value);
}
