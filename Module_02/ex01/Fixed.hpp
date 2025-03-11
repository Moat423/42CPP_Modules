#ifndef FIXED_H
# define FIXED_H


class Fixed
{
	private:
		int					_value;
		static const int	_fractional = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &rhs);
		Fixed	&operator=(const Fixed &rhs);
		Fixed	&operator<<(const Fixed &rhs);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif // FIXED_H
