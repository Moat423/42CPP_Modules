#include "Fixed.hpp"
#include <cstdlib>
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

// using += as base for +
Fixed	&Fixed::operator+=(const Fixed &rhs)
{
	if (rhs._value > 0 && this->_value > std::numeric_limits<int>::max() - rhs._value)
		throw std::overflow_error("Overflow error");
	else if (rhs._value < 0 && this->_value < std::numeric_limits<int>::min() - rhs._value)
		throw std::underflow_error("Underflow error");
	else
		this->_value = this->_value + rhs._value;
	return ( *this );
}

Fixed	&Fixed::operator-=(const Fixed &rhs)
{
	if (rhs._value < 0 && this->_value > std::numeric_limits<int>::max() + rhs._value)
		throw std::overflow_error("Overflow error");
	else if (rhs._value > 0 && this->_value < std::numeric_limits<int>::min() + rhs._value)
		throw std::underflow_error("Underflow error");
	else
		this->_value = this->_value + rhs._value;
	return ( *this );
}

Fixed &Fixed::operator*=(const Fixed &rhs)
{
	if (rhs._value == 0 || this->_value == 0)
	{
		this->_value = 0;
		return (*this);
	}
	bool	negative = (this->_value < 0) != (rhs._value < 0);
	int		abs_this = std::abs(this->_value);
	int		abs_rhs = std::abs(rhs._value);
	if (abs_rhs > ((std::numeric_limits<int>::max() >> _fractional) / abs_this))
		throw std::overflow_error("Overflow error in multiplication");
	int	result = 0;
	//splitting the number
	int	this_high = abs_this >> (_fractional / 2);
	int	this_low = abs_this & ((1 << _fractional / 2) - 1);
	int	rhs_high = abs_rhs >> (_fractional / 2);
	int	rhs_low = abs_rhs & ((1 << _fractional / 2) - 1);
	// distributive mutliplication to preserve accuracy
	int	high_high = this_high * rhs_high;
	int	high_low = this_high * rhs_low;
	int	low_high = this_low * rhs_high;
	int	low_low = this_low * rhs_low;
	// combining the results
	result = high_high;
	result += (high_low >> (_fractional / 2));
	result += (low_high >> (_fractional / 2));
	result += (low_low >> _fractional);
	this->_value = negative ? -result : result;
	return ( *this );
}

Fixed &Fixed::operator/=(const Fixed &rhs)
{
	if (rhs._value == 0)
		throw std::runtime_error("Division by zero");
	if (this->_value == 0)
		return *this;
	bool	negative = (this->_value < 0) != (rhs._value < 0);
	int	abs_this = std::abs(this->_value);
	int	abs_rhs = std::abs(rhs._value);
	//simple overflow check for small divisors causing overflow
	if (abs_rhs < (1 << _fractional) &&
		abs_this > (std::numeric_limits<int>::max() >> (_fractional / 2 - 1)))
		throw std::overflow_error("Overflow error in division");
	// Simple fixed-point division with some safety margin
    int result = ((abs_this << (_fractional - 2)) / abs_rhs) << 2;
	this->_value = negative ? -result : result;
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
