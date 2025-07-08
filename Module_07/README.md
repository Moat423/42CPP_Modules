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

