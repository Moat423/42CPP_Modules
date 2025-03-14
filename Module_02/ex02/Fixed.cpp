#include "Fixed.hpp"
/*#include <iostream>*/
#include <cmath>

const int	Fixed::_fractional = 8;

// round function of my own
static double myRound(double value) {
    return (value >= 0.0) ? floor(value + 0.5) : ceil(value - 0.5);
}

Fixed::Fixed( void ):  _value(0)
{
	/*std::cout << "Default constructor called" << std::endl;*/
}

Fixed::Fixed( const int value ): _value(value << this->_fractional)
{
	/*std::cout << "Int constructor called" << std::endl;*/
}

Fixed::Fixed( const float value ): _value(static_cast<int>(myRound(value * (1 << this->_fractional))))
{
	/*std::cout << "Float constructor called" << std::endl;*/
}

Fixed::~Fixed( void ) 
{
	/*std::cout << "Destructor called" << std::endl;*/
}

Fixed::Fixed( const Fixed &rhs )
{
	/*std::cout << "Copy constructor called" << std::endl;*/
	this->setRawBits(rhs.getRawBits());
}

int		Fixed::getRawBits( void ) const
{
	/*std::cout << "getRawBits member function called" << std::endl;*/
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
