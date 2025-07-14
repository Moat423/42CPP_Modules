#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void	randomFillSpan(Span sp, unsigned int size)
{
	for (int i; i < size; i++)
		sp.addNumber(rand());
}

void	handleAddNumber(Span sp, int number)
{
	try {
	sp.addNumber(number);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main ( void )
{
	srand(time(NULL));
	Span tenner(10);
	Span bigOne(20000);
		
	return (0);
}
