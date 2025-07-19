#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename Container>
void	printContainer(Container container)
{
	typename Container::iterator it = container.begin();
	while (it != container.end() - 1)
		std::cout << *it++ << " ";
	std::cout << *it << std::endl;
}

// function template easyfind: accepts a type T, takes two parameters:
// first type T, second an integer.
// assumes T is container of integers, function finds the first occurrence of the second parameter in the first parameter.
// If no occurrence is found, throws an exception (just to differentiate from just returning the end iterator).
//
// this will only work with containers that have begin() and end() methods, as well as an iterator type.
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::logic_error("no occurance of value in container");
	return (it);
}

#endif // !EASYFIND_HPP
