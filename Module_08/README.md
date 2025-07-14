# Templated containers, iterators, algorithms with the STL

## The C++ Standard Template Library (STL)

[geeksforgeeksSTL](https://www.geeksforgeeks.org/cpp/the-c-standard-template-library-stl/)
### Containers

##### Sequence Containers
Sequence containers store data linearlily.
You can have container adapters on top of them.
- Array (non-resizable, with lots of methods from STL)
- Vector (resizable array)
- Deque (Double-Ended Queue, can add/remove elements from both ends)
- List (linked list, non-contiguous memory, sequential access)
- Forward List (singly linked list, only next element pointers)

### Iterators

[introduction to iterators](https://hackingcpp.com/cpp/std/iterators_intro.html)
Iterators may be like the index of an array, (like when used for a vector) but fundametally they are a generalization of pointers. They can be used to traverse any container, not just arrays or vectors.
When you declare an iterator, you can never print out the iterator itself (as that might point to an object of the current implementation of the container).
Instead you dereference the iterator to get the value it points to, or you can use it to access the container's methods.

they can be declared like such:
```c++
std::vector<int>::iterator it;
```

it.end() is something that should never be printed, it is a special iterator that points to the end of the container, it is not a valid element in the container.

#### learnings from making loops
if we have a vector, and we want to walk over every sinlge element, we can do that in two ways:

either using a size_type and indexing that vector provides [] (same as the .at() funtion)
```C++
std::sort(_vec.begin(), _vec.end());
int shortestSpan = std::numeric_limits<int>::max();

for (std::vector<int>::size_type i = 0; i < _vec.size() - 1; ++i) {
    int tmp = _vec[i + 1] - _vec[i];
    if (tmp < shortestSpan)
        shortestSpan = tmp;
}
```

or using index as the form of iteration
```C++
std::sort(_vec.begin(), _vec.end());
int shortestSpan = std::numeric_limits<int>::max();

for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end() - 1; ++it) {
    int tmp = *(it + 1) - *it;
    if (tmp < shortestSpan)
        shortestSpan = tmp;
}
```

The last one looks confusing at first, but it's just using the classes own defined iterator till the end
and getting the value to calculate with by dereferencing the iterator.

### algorithms

There are many algorithms in the STL, they are supposted to impement the most efficient algorithms for the most common tasks.

Example of an algorithm that requires the container to imeplement iterators is `std::find`:

	std::vector::iterator it = std::find(container.begin(), container.end(), value);
this returns an iterator to the first element in the container that matches the value, or the end iterator if no such element exists.

std::sort
-requires container with random access iterator

available containers that have random access iterators:
-std::vector
-std::deque
-std::array (only in C++11 and onwards)


std::min / std::max
supported by 
-std::vector
-std::deque
-std::array (only in C++11 and onwards)
-lists


### making classes that use the STL

it is discouraged to inherit from the STL classes, they are [not designed for that](https://www.geeksforgeeks.org/cpp/why-should-we-not-inherit-std-vector-in-cpp/)

the solution is to make it a private(or protected) member to improve encapsulation.

