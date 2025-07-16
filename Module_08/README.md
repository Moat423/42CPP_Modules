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

### stack

has a [typedef for the container type](https://learn.microsoft.com/en-us/cpp/standard-library/stack-class?view=msvc-170), which is usually a deque or a vector.
```C++
		typedef Container container_type;
```
and typedefs for the size_type, the value_type, the iterator, const_iterator, reverse_iterator, const_reverse_iterator,
reference and const_reference.
	all of these are typedefs to the container inherent types and values.
Template default: lets you write MutantStack<int> instead of MutantStack<int, std::deque<int>>.
	template < class Type, class Container = std::deque<Type> >
	lets users avoid specifying the container type unless they want to override it.
Constructor default: lets you write MutantStack<int> s; instead of always having to pass a std::deque<int>.
	explicit MutantStack(const container_type &rhs = container_type());
	lets users avoid providing an initial container unless they have one already populated.
explicit copy constructor to prevent unintended copying and creation of a new stack.
```C++
	explicit MutantStack(const container_type& ctnr = container_type()) : c(ctnr) {}
```
push(const T&)	Adds an element to the top:	c.push_back()
pop()	Removes element from the top:	c.pop_back()
top()	Returns reference to top element:	c.back()
empty() const	Whether the stack has no elements:	c.empty()
size() const	Number of elements in the stack:	c.size()


first, i implemented all the member functions in stack as well, instead of inheriting from stack, but they are not needed anymore. but here they are now:
```c++
template < class Type, class Container >
bool	MutantStack<Type, Container>::empty() const {
	return (this->c.empty());
}

template < class Type, class Container >
void	MutantStack<Type, Container>::pop() {
	this->c.pop_back();
}

template < class Type, class Container >
void MutantStack<Type, Container>::push(const Type& value) {
	this->c.push_back(value);
}

template < class Type, class Container >
typename Container::size_type MutantStack<Type, Container>::size() const {
	return (this->c.size());
}

template < class Type, class Container >
typename Container::const_reference MutantStack<Type, Container>::top() const {
	return (this->c.back());
}

template < class Type, class Container >
typename Container::reference MutantStack<Type, Container>::top()
{ return (this->c.back());
}
```

### Iterator functions:
a lot of containers have iterators. These define the following functions:

begin, end, rbegin, rend with their const and non const variants


#### specifying Member functions of template classes

you must specify the [template parameter list and the function with class template and parameters](https://www.ibm.com/docs/en/zos/2.4.0?topic=only-member-functions-class-templates-c).
```C++
template <class Type, class Container>
MutantStack<Type, Container>::MutantStack(const container_type &rhs) 
{//definition}
```

### common practices

##### where to put typedefs:
```C++
template < class T, class Container = std::deque<T> >
class MutantStack {
	public:
		//Typedefs
		typedef typename Container::size_type size_type;
		typedef typename Container::value_type value_type;
```
apparently it is common to [put typedefs in the public section of the class](https://stackoverflow.com/questions/10144484/typedef-structs-declared-inside-class-or-outside).

It improves Readability and Consistency: Defining types like value_type and size_type inside the class makes code more readable and self-documenting. These aliases clarify what types users of your class should expect.
For templates, typedefs inside the class can reference dependent types (like Container::value_type). If you want to define such a typedef outside the class, you would have to repeat the template declaration and complicated syntax, which is error-prone and unwieldy.

### critique of this project:

I had to inherit from stack so that i could copy construct from MutantStack to stack, as this was part of the task. and thats really ugly, especially, because it's not endorsed to inherit from these containers.
	class MutantStack: public std::stack<Type, Container>
although for this specific usecase it is ok to do.
Also since stack is a container adapter, its contaienr is actually protected, not private. so its all good.
[src](https://stackoverflow.com/questions/73440733/how-can-i-implement-my-own-stack-iterator-in-c)
