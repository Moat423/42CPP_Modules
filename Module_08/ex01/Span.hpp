#ifndef SPAN_HPP
# define SPAN_HPP
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
// Span class that can store a maximum of N integers. N is an unsigned int
// variable and will be the only parameter passed to the constructor.
// This class will have a member function called addNumber() to add a single number
// to the Span. It will be used in order to fill it. Any attempt to add a new element if there
// are already N elements stored should throw an exception.
// Next, implement two member functions: shortestSpan() and longestSpan()
// They will respectively find out the shortest span or the longest span (or distance, if
// you prefer) between all the numbers stored, and return it. If there are no numbers stored,
// or only one, no span can be found. Thus, throw an exception.
// Of course, you will write your own tests, and they will be far more thorough than the
// ones below. Test your Span with at least 10,000 numbers. More would be even better.
#include <exception>
#include <vector>

class Span
{
	public:
		Span(int n);
		virtual ~Span();
		Span(Span &rhs);
		Span &operator=(Span &rhs);
		void	addNumber( int number );
		void	shortestSpan( void );
		void	longestSpan( void );
		class	isFull: std::exception {
			const char *what() const throw();
		};
		class	notEnoughMembers: std::exception {
			const char *what() const throw();
		};
	private:
		std::vector<int> _vec;
		unsigned int	_maxSize;
};

#endif // !SPAN_HPP

