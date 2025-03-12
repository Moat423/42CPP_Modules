#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>

//UNARY OPERATORS

//---------------------------------------pre- and postcrement---------------------------------------

Fixed	&Fixed::operator++( void )
{
	this->_value += 1;
	return ( *this );
}

Fixed	Fixed::operator++ ( int )
{
	Fixed ans(*this);
	++(*this);
	return (ans);
}

Fixed	&Fixed::operator--( void )
{
	this->_value -= 1;
	return ( *this );
}

Fixed	Fixed::operator-- ( int )
{
	Fixed ans(*this);
	++(*this);
	return (ans);
}

//BINARY OPERATORS

//----------------------------comparison operators----------------------------

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (getRawBits() == rhs.getRawBits());
}
bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (!operator==(rhs));
}

//----------------------------arithmetic operators----------------------------

Fixed	&Fixed::operator+=(const Fixed &rhs)
{
	long long result = static_cast<long long>(this->_value) + static_cast<long long>(rhs._value);
	if (result > std::numeric_limits<int>::max())
		throw std::overflow_error("Overflow error");
	else if (result < std::numeric_limits<int>::min())
		throw std::underflow_error("Underflow error");
	else
		this->_value = result;
	return ( *this );
}

Fixed	&Fixed::operator-=(const Fixed &rhs)
{
	long long result = static_cast<long long>(this->_value) - static_cast<long long>(rhs._value);
	if (result > std::numeric_limits<int>::max())
		throw std::overflow_error("Overflow error");
	else if (result < std::numeric_limits<int>::min())
		throw std::underflow_error("Underflow error");
	else
		this->_value = result;
	return ( *this );
}

Fixed &Fixed::operator*=(const Fixed &rhs)
{
	long long result = (static_cast<long long>(this->_value) * static_cast<long long>(rhs._value)) >> this->_fractional;
	if (result > std::numeric_limits<int>::max())
		throw std::overflow_error("Overflow error");
	else if (result < std::numeric_limits<int>::min())
		throw std::underflow_error("Underflow error");
	else
		this->_value = result;
	return ( *this );
}

Fixed &Fixed::operator/=(const Fixed &rhs)
{
	if (rhs._value == 0)
		throw std::runtime_error("Division by zero");
	long long result = ((static_cast<long long>(this->_value) << this->_fractional) / (static_cast<long long>(rhs._value)) << this->_fractional);
	if (result > std::numeric_limits<int>::max())
		throw std::overflow_error("Overflow error");
	else if (result < std::numeric_limits<int>::min())
		throw std::underflow_error("Underflow error");
	else
		this->_value = result;
	return ( *this );
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result(*this);
	result += rhs;
	return (result);
}


Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result(*this);
	result -= rhs;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result(*this);
	result *= rhs;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	result(*this);
	result /= rhs;
	return (result);
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	/*std::cout << "Copy assignment operator called" << std::endl;*/
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return ( *this );
}

//----------------------------non-member functions----------------------------

std::ostream &operator<<( std::ostream &out, const Fixed &rhs )
{
	out << rhs.toFloat();
	return ( out );
}
