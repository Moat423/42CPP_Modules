#ifndef FIXED_H
# define FIXED_H

# include <iostream>


class Fixed
{
	private:
		int					_value;
		static const int	_fractional = 8;

	public:
		Fixed();
		Fixed( const int value );
		Fixed( const float value );
		~Fixed();
		Fixed( const Fixed &rhs );
		Fixed	&operator=( const Fixed &rhs );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;
		Fixed	&operator+=(const Fixed &rhs);
		Fixed	&operator-=(const Fixed &rhs);
		Fixed	&operator*=(const Fixed &rhs);
		Fixed	&operator/=(const Fixed &rhs);
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;
		Fixed	&operator++( void ); // ++precrement
		Fixed	operator++ ( int ); // postcrement++ with dummy int
		Fixed	&operator--( void ); // --precrement
		Fixed	operator-- ( int ); // postcrement-- with dummy int
		static Fixed	&min( Fixed &lhs, Fixed &rhs );
		static Fixed	&min( const Fixed &lhs, const Fixed &rhs );
		static Fixed	&max( Fixed &lhs, Fixed &rhs );
		static Fixed	&max( const Fixed &lhs, const Fixed &rhs );
};

std::ostream &operator<<( std::ostream &out, const Fixed &rhs );

#endif // FIXED_H
