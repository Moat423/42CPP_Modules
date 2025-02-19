#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP


# define RED "\033[31m"
# define GREEN "\033[32m"
# define YEL "\033[33m"
# define BLUE "\033[34m"
# define MAG "\033[35m"    // Magenta
# define CYN "\033[36m"    // Cyan
# define WHT "\033[37m"    // White
# define BRED "\033[1;31m" // Bold Red
# define RESET "\033[0m"
# define BOLD "\033[1m"

#include <string>
class Zombie
{
	private:
		std::string _name;
	public:
		Zombie( std::string name );
		~Zombie ( void );
		void	announce( void ) const;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif //ZOMBIE_HPP
