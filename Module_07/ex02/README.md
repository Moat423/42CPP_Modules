### templates

template function definition can be put into a seperate .tpp file. In case of the Boost libraries, it is also customary to have a custom [.ipp](https://stackoverflow.com/questions/44774036/why-use-a-tpp-file-when-implementing-templated-functions-and-classes-defined-i) file.

You just call #include $"<name>.tpp"$ at the very end of the .hpp file so that all the function definitions get included.
Though by default [Ubuntu does not actually recognizes .tpp files](https://gitlab.gnome.org/GNOME/gtksourceview/-/issues/23) as c++ language files as of now, so I decided to put it into the header iteslf without a .tpp file for compatiability

### class templates
```C++
template <typename T> class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &rhs);
		Array<T> operator=(const Array<T> &rhs);
		~Array();
}
```

the operator overload and copy constructor was first confusing to me, because it looks weird as a template. But the operator overload is specified like this:

$$[return type]	operator[sign]	([type of argument]	&[name of argument])$$
so this makes sense:
$$	Array<T>	operator=		(const Array<T>		&rhs);$$


#### constructor of an array or to NULL or not to NULL

there are two options for the default constructor for an array and both are valid:
1.
```C++
Array<Type>::Array() : _size(0), _array(new Type[0]) {}
```
Allocates an array of zero elements using new Type.
new Type is legal in C++: it returns a non-null pointer, but one must still delete it with delete[] in your destructor.
This approach means _array always points to a valid (but empty) dynamically allocated array, which can simplify destructor logic (can just call delete _array).

2.
```C++
Array<Type>::Array() : _size(0), _array(NULL) {}
```
Does not allocate any memory; _array is set to NULL.
Be careful in the destructor and other member functions to check if _array is NULL before accessing or deleting it.
This approach can save a (very small) allocation, but requires more null checks elsewhere.

In this case, as it was a training excercise I decided to go with the first option, as I have not taken that approach before, because usually I try to optimize the allocations very much, but I don't think it matters here.

### Variable templates

sadly I am not trying them out here, since I am limited to using C++98.
But it means that you define a variable that can work with any type specified when the variable gets used.

[read more here](https://www.geeksforgeeks.org/cpp/templates-cpp/)


## General


ORDER matters

You can not use a different order for the variables declared in the class and in the initializer list.
If you do:

	private:
		unsigned int	_size;
		Type			*_array;

Then you *have* to initialize the size first:

$$Array<Type>::Array(): _size(0), _array(new Type[0]) {}$$
