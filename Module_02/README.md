# Floating Point Numbers

### srcs:
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

what i take from this article for future computation:
- Equality is a hard thing to check for floating point numbers
	- use a tolerance value to check if two numbers are equal
	but be careful with the tolerance value, as it should reflect the number range I am calculating in (if i am calculating in the e20 in should be there, if i need to check closeness of numbers in e-200, then the tolerance should be way smaller)
- look out for subtractions of close numbers, they tent to get very inaccurate
	- a way to circumvent that is to change formulas for example:
	changing polynomials to be functions of 1/x instead of x
- Overflow: look out for multiplications of large numbers. If possible, rearrage the formula and extract some large number from the multiplication, you would always rather do more division, as getting closer to 0 doesn't matter, but when you reach infinity, its bad for calculations.

## Function overloading

that means, the programmer defines functions with the same name, that can takedifferent arguments. The compiler will choose the right function based on the arguments.

		Fixed();
		Fixed( const int value );
		Fixed( const float value );

## orthodox Canonical Form

- A default constructor that initializes what is needed
- A copy constructor.
- A copy assignment operator overload.
- A destructor.
- getters
- setters

as a so called rule of three, if a class implements any of the following, it should also implement the others:
destructor
copy constructor
copy assignment operator
srcs:
https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three

so this is where this "orthodox Canonical form" comes from.

## What is a copy constructor?
Fixed b(a);
this is called a copy contructor, because b has not yet been initialised and is initialised in this action. whereas in the assignment, the construction may already have happened.
this is how it is declared in the class:

		Fixed(const Fixed &rhs);

rhs stands for right hand side (of the operation)
// explanation here

## What is an assigment overload
srcs:
https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading
this is how it is defined in the class declaration:
``` C++
return_type operator<symbol>(parameters);
```

so in the case with an overload of '=' one could write in the class declaration:
``` C++
		Fixed &operator=(const Fixed &rhs)
```
Implementation of an operator overload:
``` C++
Fixed &	Fixed::operator=(const Fixed &rhs)
```
return-type		operator<operator>
		class				(parameters)
				
again, rhs stands for the right hand side of the asigment, which makes a lot of sense when a = b, then b is the right hand side.
why do a self assignment test:

	if (this != &rhs)
		this->_value = rhs._value;
this is to prevent data corruption in the case a = a. It is good form and a part of c++ robust programming. unlike C, where it's the programmers task to avoid such stupid mistakes, C++ tries to prevent even the possibility. and since it doesn't take many assembly instructions, it is kind of fine, even if it may just take a little bit longer, it won't be noticable.
Assignment operators (=, +=, -=, etc.)
-Return a reference to the object itself
-Take parameters by const reference
-Allow chaining

Binary operators (+, -, *, /, etc.)
-Usually return a new object (by value)
-Take parameters by const reference
-Are often implemented in terms of compound assignment operators

Unary operators (++, --, -, !, etc.)
-Can be prefix (++a) or postfix (a++)
-Prefix returns reference, postfix returns value
-Postfix takes a dummy int parameter to distinguish it
and this is how it is implemented:


What is a copy assignment operator?
a = b;  // Copy assignment operator called here
as is visible from this, a and b might have already been constructed, and now a just gets assigned the value through reference of b.
when the left side of a '=' is of the same class as the right side, a copying operation can take place.
and when we overload the '=' it means //TODO explanation

srcs
Rule of three:
https://en.wikipedia.org/wiki/Rule_of_three_(C++_programming)
copy constructor
https://unstop.com/blog/copy-constructor-in-cpp
## overloading for unary operators
(++, --,)
src for understanding post and precrement well:
https://isocpp.org/wiki/faq/operator-overloading


## overloading for binary operators
(that means operators that take two arguments)
+, -, *, /
these may be defined as member or non member functions, per rule of thumb, they should be defined as non member functions, as they are not changing the state of the object, but rather creating a new one.
I was however asked to implement them as member functions in this scenario.
That goes for both the comparing operators and the arithmetic operators. (they both should be non members and friends, but i am forbidden from using friends)

Since it it bad form and confuses the user to have + but not +=, i will also implement these, and the + can be based on the += operator as well.

this may not be defined as a member function, as that would make it have three arguments, because of the implicit this argument.
example:
std::ostream &operator<<( std::ostream &out, const Fixed &rhs );

## type-casting

https://favtutor.com/blogs/static-cast-cpp

	static_cast<float>( this->getRawBits() ) / ( 1 << _fractional );

in c++ you can use C style conversion, which which have some pitfalls
But there are other possibliitis. One of them is static_cast<type>(value). You can also do implicit conversion (which the compiler does automatically).
The advantage of static casting is that is more explicit, and has checks on compile time.

## conversion

### int

very easy, just a bitshift, since the int is basically a fixed with the dot behind the last number.

### float

https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/round-roundf-roundl?view=msvc-170
to convert a float to a fixed point value, you have to first understand that floats are not stored in the same way. and that means, that wee ned to multiply the float value by a the 2^ resolution of the fixed point value. that means

value * (1 >> this->_fractional)

and then it is very good to use roundf to round it to the nearest integer, as floats have a lot of decimal places, that we can't represent in the fixed point value.
std::roundf(value * (1 >> this->_fractional))

to convert something to the float representation, you have to divide by the resolution of the fixed point value.

	static_cast<float>( this->getRawBits() ) / ( 1 << _fractional );
just make sure to cast as needed, as the division will be an integer division, if you don't cast it to a float.

## static member functions

src:
https://www.learncpp.com/cpp-tutorial/static-member-functions/

-can be called directly by using the class name (Fixed) and scope resolution operator (::)
	that means they may be called without an object of the class
	a static member function may also be called thorugh an object of the class, but that is not recommended, as it is confusing to the user.
-have no this pointer, as they are not called on an object!!

