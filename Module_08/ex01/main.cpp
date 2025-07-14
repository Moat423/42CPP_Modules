#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
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

void	randomFillSpan(Span sp, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		sp.addNumber(rand());
}

void	handleAddNumber(Span sp, int number)
{
	try {
	sp.addNumber(number);
	} catch (std::exception &e) {
		std::cout << e.what() << "for the number " << number << std::endl;
	}
}

void	fillWithDist(Span sp, unsigned int size, int start, int distance)
{
	for (unsigned int i = 0; i < size; i++)
	{
		sp.addNumber(start);
		start += distance;
	}
}

int main ( void )
{
	srand(time(NULL));
	Span tenner(10);
	Span bigOne(20000);
	unsigned int	someDistance;
	fillWithDist(tenner, 10, 0, 2);
	someDistance = tenner.longestSpan();
	std::cout << "longest Span of an object where longest span is 2: " << someDistance << std::endl;
	someDistance = tenner.shortestSpan();
	std::cout << "shortest Span of an object where shortest span is 2: " << someDistance << std::endl;
	handleAddNumber(tenner, 5);
	randomFillSpan(bigOne, 20000);
		
	return (0);
}
