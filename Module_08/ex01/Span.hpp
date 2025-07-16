#ifndef SPAN_HPP
# define SPAN_HPP
#include <exception>
#include <vector>

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

/*
 * Span class: can store maximum of n integers.
 * unsigned int n: only parameter passed to constructor
 * member functions:
 * 	addNumber() add a single number to span (to fill the class)
 * 	throws exception if attempting to add more items than n (if there are already n elements inside)
 * 	shortestSpan()
 * 	longestSpan()
 * 	returns shortest/longest span or distance between all the numberes stored
 * 	if no numbers stored: exception
 */
class Span
{
	public:
		Span(unsigned int maxSize);
		virtual ~Span();
		Span(const Span &rhs);
		Span &operator=(const Span &rhs);
		void	addNumber( int number );
		unsigned int		longestSpan( void );
		unsigned int		shortestSpan( void );
		void				printSpan( void );
		void				fillWithDist(unsigned int size, int start, int distance);
		void				fillWithRandom(unsigned int size);
		class	isFull: std::exception {
			public:
				const char *what() const throw();
		};
		class	notEnoughMembers: std::exception {
			public:
				const char *what() const throw();
		};
	private:
		Span();
		unsigned int	_maxSize;
		std::vector<int> _vec;
};

#endif // !SPAN_HPP

