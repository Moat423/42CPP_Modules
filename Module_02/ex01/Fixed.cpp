#include "Fixed.h"
#include <iostream>

Fixed::Fixed( void ):  _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ) 
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &rhs )
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(rhs.getRawBits());
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw)
{
	this->_value = raw;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return ( *this );
}


Fixed::operator<<(const Fixed &rhs)
{
	return ( *this );
}


float	Fixed::toFloat( void ) const
{
}

int		Fixed::toInt( void ) const
{
	return (this->_value >> this->_fractional);
}
