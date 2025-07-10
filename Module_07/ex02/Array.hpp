#ifndef ARRAY_HPP
# define ARRAY_HPP

// class template array that contains elements of type t implementing
// the following behavior and functions:
// • construction with no parameter: creates an empty array.
// • construction with an unsigned int n as a parameter: creates an array of n elements
// initialized by default.
// tip: try to compile int * a = new int(); then display *a.
// • construction by copy and assignment operator. in both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
// • you must use the operator new[] to allocate memory. preventive allocation (allocating memory in advance) is forbidden. your program must never access nonallocated memory.
// • elements can be accessed through the subscript operator: [ ].
// • when accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • a member function size() that returns the number of elements in the array. this
// member function takes no parameters and must not modify the current instance.

template <typename Type>
class Array
{
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array<Type> &rhs);
		Array<Type> &operator=(const Array<Type> &rhs);
		Type &operator[](int index);
		const Type &operator[](int index) const;
		unsigned int size( void ) const;
	private:
		unsigned int	_size;
		Type			*_array;
};

#include <stdexcept>

template <typename Type>
Array<Type>::Array(): _size(0), _array(new Type[0]) {}

template <typename Type>
Array<Type>::~Array()
{
	delete [] _array;
}

template <typename Type>
Array<Type>::Array(unsigned int n): _size(n), _array(new Type[n]) {}

template <typename Type>
Array<Type>::Array(const Array<Type> &rhs): _size(rhs._size), _array(new Type[rhs._size])
{
	for (unsigned int i = 0; i < _size; ++i)
		_array[i] = rhs._array[i];
}

template <typename Type>
Array<Type> &Array<Type>::operator=(const Array<Type> &rhs)
{
	if (this != &rhs)
	{
		if (size() != rhs.size())
		{
			delete [] _array;
			_size = rhs._size;
			_array = new Type[_size];
		}
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = rhs._array[i];
	}
	return (*this);
}

template <typename Type>
Type &Array<Type>::operator[](int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_array[index]);
}

template <typename Type>
const Type &Array<Type>::operator[](const int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_array[index]);
}

template <typename Type>
unsigned int Array<Type>::size( void ) const
{
	return (_size);
}

#endif // !ARRAY_HPP
