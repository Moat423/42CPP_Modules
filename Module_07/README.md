# Templates

[explanation for all templates](https://www.geeksforgeeks.org/cpp/templates-cpp/)
[C++ tutorial](https://cplusplus.com/doc/oldtutorial/templates/)

A template is there to save the user from writing overloaded functions for every type this function could be done with. the compiler writes it for you.
They must be defined and declared in the header and are always prepended by a "template" keyword.

## Function Templates

- they use "typename" to have a spaceholder for any normal type.


example:
```C++
template <typename T>
void	swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}
```
in the above example T is the name I gave the type that this function will take when it gets compiled and used.

#### using templates for function pointers or passed functions

you can just define it as a type too:
```C++
template <typename T, typename Func>
void	iter(T *array, unsigned int length, Func func)
{
	for (unsigned int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}
 
```
func can be any callable object: function pointer, functor (object with operator()), lambda, or any type that can be called with a single T argument.

if someone passed something like an int as the func argument, one would get a confusing compiler warning, it has to be callable.

but there is also the option of explicitly only allowing FUNCTION POINTERS:
```C++
template <typename T, typename Func>
void	iter(T *array, unsigned int length, void (*func)(T))
...
```
the downside (or maybe usecase dependent upside?) is that only free functions (not member functions or functors)
with the exact signature void func(T) can be passed.
