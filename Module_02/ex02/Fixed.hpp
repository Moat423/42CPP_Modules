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
		Fixed	&operator+(const Fixed &rhs);
		Fixed	&operator-(const Fixed &rhs);
		Fixed	&operator*(const Fixed &rhs);
		Fixed	&operator/(const Fixed &rhs);
};

std::ostream &operator<<( std::ostream &out, const Fixed &rhs );

#endif // FIXED_H
