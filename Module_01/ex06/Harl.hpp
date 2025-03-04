#ifndef HARL_HPP
# define HARL_HPP

#include <string>

enum harlLevel {DEBUG, INFO, WARNING, ERROR, DFL};

class Harl
{
	public:
		Harl();
		~Harl();
		void	_debug( void ) const;
		void	_info( void ) const;
		void	_warning( void ) const;
		void	_error( void ) const;
		void	_ramble( void ) const;
	public:
		void	filteredComplain( const std::string level ) const;
};

#endif // HARL_HPP
