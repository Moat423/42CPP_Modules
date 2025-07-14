#ifndef SPAN_HPP
# define SPAN_HPP
#include <exception>
#include <vector>

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
		class	isFull: std::exception {
			const char *what() const throw();
		};
		class	notEnoughMembers: std::exception {
			const char *what() const throw();
		};
	private:
		Span();
		unsigned int	_maxSize;
		std::vector<int> _vec;
};

#endif // !SPAN_HPP

