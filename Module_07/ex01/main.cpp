#include <iostream>
#include "iter.hpp"

void	printInt(int x)
{
	std::cout << x << std::endl;
}

struct Increment {
	void	operator()(int &x) {
		x++;
	};
};

int main (void)
{
	int	arr[] = {1, 3, 4, 6};
	std::cout << "Printing array:" << std::endl;
	iter(arr, 4, printInt);
	std::cout << "incrementing array by one" << std::endl;
	Increment incr;
	iter(arr, 4, incr);
	std::cout << "Printing array:" << std::endl;
	iter(arr, 4, printInt);
	return 0;
}
