#include <deque>
#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main ( void )
{
	std::cout << "finding 3 in some integers:" << std::endl;
	std::vector<int> vec1(5);
	std::vector<int> vec2(10);
	std::vector<int>::iterator it;
	std::deque<int>::iterator dit;
	int	value = 3;
	std::deque<int> deq(10);

	for (int i = 0; i < 10; ++i)
		deq.push_back(i + 2);
	std::cout << "printing initialized deque:" << std::endl;
	printContainer(deq);
	try {
		dit = easyfind(deq, value);
		std::cout << "found value: " << *dit << std::endl;
	} catch (std::exception &e) {
		std::cout << "value = " << value << std::endl << e.what() << std::endl;
	}
	for (int i = 0; i < 10; ++i)
		vec2[i] = i + 2;
	std::cout << "printing uninitialized vector:" << std::endl;
	printContainer(vec1);
	std::cout << "vector contains: " << value << "?" << std::endl;
	try {
		it = easyfind(vec1, value);
		std::cout << "found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "value = " << value << ": "<< e.what() << std::endl;
	}
	std::cout << "printing initialized vector:" << std::endl;
	printContainer(vec2);
	std::cout << "vector contains: " << value << "?" << std::endl;
	try {
		it = easyfind(vec2, value);
		std::cout << "found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "value = " << value << ": "<< e.what() << std::endl;
	}
	return (0);
}
