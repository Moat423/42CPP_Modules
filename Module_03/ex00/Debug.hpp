#ifndef DEBUG_HPP
# define DEBUG_HPP

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

# ifdef DEBUG
# include <iostream>
# include <sstream>

# define debug(msg) \
	std::cerr << YEL << __FILE__ << ":" << __LINE__ << " " << msg << RESET << std::endl;
# else
# define debug(msg) (void(0))
# endif

#endif // !DEBUG_HPP
