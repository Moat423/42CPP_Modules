#include "Fixed.hpp"
#include "Debug.hpp"
/*#include <iostream>*/
#include <cmath>

const int	Fixed::_fractional = 8;

Fixed::Fixed( void ):  _value(0)
{
	debug("Default constructor called");
}

Fixed::Fixed( const int value ): _value(value << this->_fractional)
{
	debug("Int constructor called");
}

Fixed::Fixed( const float value ): _value(static_cast<int>(roundf(value * (1 << this->_fractional))))
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
	this->setRawBits(rhs._value);
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	debug("Copy assignment operator called");
	if (this != &rhs)
		this->setRawBits(rhs._value);
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
	return static_cast<float>( this->_value ) / ( 1 << _fractional );
}

int		Fixed::toInt( void ) const
{
	return (this->_value >> this->_fractional);
}

Fixed	&Fixed::min( Fixed &lhs, Fixed &rhs )
{
	if (lhs._value < rhs._value)
		return (lhs);
	else
	 	return (rhs);
}

const Fixed	&Fixed::min( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs._value < rhs._value)
		return (lhs);
	else
	 	return (rhs);
}

Fixed	&Fixed::max( Fixed &lhs, Fixed &rhs )
{
	if (lhs._value > rhs._value)
		return (lhs);
	else
	 	return (rhs);
}

const Fixed	&Fixed::max( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs._value > rhs._value)
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

Fixed Fixed::abs(Fixed const &value)
{
	if (value._value < 0)
		return (Fixed(value) * Fixed(-1));
	return (value);
}
