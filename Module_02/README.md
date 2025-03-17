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

## something specific for my implementation

I read in that very elaborate stackoverflow (link above in text) that you can use += to define + and prefix ++ to define postfix ++,
so i am trying to do that here, as I read it is good form to limit the amount of code you write, and to make it more readable.

I also added the fromRawBits function, which enables me to create a Fixed from a raw bit integer value i am giving it, which makes the testing cleaner, because i don't have to initialize every obejct with a float or int value. it's usage can be seen in the tests.


## overflow/underflow checks

I decided to make this Fixed point class more robust and have overflow checks, which isn't that easy in C++98 standard, since i can't use a long long int. 
Her however is a great source that discusses long long fixed point implementations and operations very well:
https://vanhunteradams.com/FixedPoint/FixedPoint.html
There are also some compiler flags that could be set, but these are more for debugging and not for the final product.
Therefore i have this solution for += (and -=, which just mirrors that)

``` C++
	if (rhs._value > 0 && this->_value > std::numeric_limits<int>::max() - rhs._value)
		throw std::overflow_error("Overflow error");
```
this checks if the value is positive and if value is bigger that the maximum minus that positive value. if it is, if would overflow. (that would mean there is "not enough space" for rhs till int max)

``` C++
	else if (rhs._value < 0 && this->_value < std::numeric_limits<int>::min() - rhs._value)
		throw std::underflow_error("Underflow error");
}
```
same with negative numbers, so I check if its a negative and then see if int min minus the negative value (meaning + the absolute value) is bigger that the current value. If it is, it would underflow.

### multiplication
 that is a bit more complicated. I decided to try to make my class more robust and have overflow checks and preserve as much accuracy as possible.
But that means it is going to be slightly slower.
```C++

	if (rhs._value == 0 || this->_value == 0)
	{
		this->_value = 0;
		return (*this);
	}
```
first a basic check if i can return quci, as multiplying by 0 is always 0.
``` C++
	bool	negative = (this->_value < 0) != (rhs._value < 0);
	int		abs_this = std::abs(this->_value);
	int		abs_rhs = std::abs(rhs._value);
	if (abs_rhs > ((std::numeric_limits<int>::max() >> _fractional) / abs_this))
		throw std::overflow_error("Overflow error in multiplication");
	int	result = 0;
```
switching over to absolute values to simplify for checking for overflow and preserve if the result should be negative.
``` C++
	//splitting the number
	int	this_high = abs_this >> (_fractional / 2);
	int	this_low = abs_this & (1 << _fractional / 2) - 1;
	int	rhs_high = abs_rhs >> (_fractional / 2);
	int	rhs_low = abs_rhs & (1 << _fractional / 2) - 1;
```
making the multiplication in parts to preserve accuracy and to check for overflow.
``` C++
	// distributive mutliplication to preserve accuracy
	int	high_high = this_high * rhs_high;
	int	high_low = this_high * rhs_low;
	int	low_high = this_low * rhs_high;
	int	low_low = this_low * rhs_low;
```
then using the distributive property of multiplication to split the multiplication in parts, to preserve accuracy and to check for overflow.
in this case:
(a + b) * (c + d) = (a*c) + (a*d) + (b*c) + (b*d)
with
a = high bits of first number(this) (shifted left)
b = low bits of first number (this)
c = high bits of second number (rhs)(shifted left)
d = low bits of second number (rhs)
``` C++
	// combining the results
	result = high_high;
	result += (high_low >> (_fractional / 2));
	result += (low_high >> (_fractional / 2));
	result += (low_low >> _fractional);
	this->_value = negative ? -result : result;
	return ( *this );
```

### Division
Now that is an even more complicated topic. I decided on a middleground between preserving some accuracy, but still being a bit fast.
ofc it would have been all easy if i used a long long:
```C++
	long long result = ((static_cast<long long>(this->_value) << this->_fractional) / static_cast<long long>(rhs._value));
	if (result > std::numeric_limits<int>::max())
		throw std::overflow_error("Overflow error");
	else if (result < std::numeric_limits<int>::min())
		throw std::underflow_error("Underflow error");
	else
		this->_value = result;
	```
but this not what we are doing. We are implementing some c++98 safe code.

``` C++
	if (rhs._value == 0)
		throw std::runtime_error("Division by zero");
	if (this->_value == 0)
		return *this;
```
first is of course 0 check.
``` C++
	bool	negative = (this->_value < 0) != (rhs._value < 0);
	int	abs_this = std::abs(this->_value);
	int	abs_rhs = std::abs(rhs._value);
```
converting to absolute values and saving if result should be negative, so overflow check is easier.
``` C++
	//simple overflow check for small divisors causing overflow
	if (abs_rhs < (1 << _fractional) &&
		abs_this > (std::numeric_limits<int>::max() >> (_fractional / 2 - 1)))
		throw std::overflow_error("Overflow error in division");
```
now this is where I am simplifying to save some time. I check if I have a small divisor, and if I do, then i check if I have some space in my value to have it become bigger.
If abs_rhs was the minimum (0.00390625 with 8 fractional bits) then that would mean the resulting multiplication factor would be 2^_fractional. So its going to become large.
But I am not shifting by the full _fractional, but i am shifting by a safety ammount and I have decided that _fractional / 2 - 1 would be reasonable.

``` C++
// Simple fixed-point division with some safety margin
    int result = ((abs_this << (_fractional - 2)) / abs_rhs) << 2;
```
now normally you would shift by _fractional first and then do the division, but i am doing part of the shift first and then the rest in the hopes of perserving some accuracy and speed.
``` C++
	this->_value = negative ? -result : result;
	return *this;
```


ofc the most robust version would be to check how many bits can be safely shifted by and then still split the number into a lover and an upper part to preserve the most accuracy.
I had a previous version that was more compact and sacrificed accuracy for speed:
```C++
Fixed &Fixed::operator/=(const Fixed &rhs)
{
	if (rhs._value == 0)
		throw std::runtime_error("Division by zero");
	if (this->_value == 0)
		return *this;
	bool	negative = (this->_value < 0) != (rhs._value < 0);
	int	abs_this = std::abs(this->_value);
	int	abs_rhs = std::abs(rhs._value);
	//simple overflow check for small divisors causing overflow
	if (abs_rhs < (1 << _fractional) &&
		abs_this > (std::numeric_limits<int>::max() >> (_fractional / 2 - 1)))
		throw std::overflow_error("Overflow error in division");
	// Simple fixed-point division with some safety margin
    int result = ((abs_this << (_fractional - 2)) / abs_rhs) << 2;
	this->_value = negative ? -result : result;
	return ( *this );
}
```
in the end, the version that is in my code now is more complex, but also more accurate and robust.

## BSP

### the Point

since i am required to make my private attribus x and y Fixed const, it is not actually that nice to make a copy assignment operator overload, as that would mean that the x and y values could be changed, which is not what i want.
So acutally implementing a copy assignment operator overload is a bit stupid, as shown in this discussion:
https://cplusplus.com/forum/beginner/55742/
But anyway, there are ways to circumvent constness in CPP too.

This one is to const_cast. But it is not recommended, as it is not safe and can lead to undefined behaviour.
```C++
	if (this != &rhs)
	{
		const_cast<Fixed&>(this->x) = rhs.getX();
		const_cast<Fixed&>(this->y) = rhs.getY();
	}
	return (*this);
```
the second one is the one I decided for in the end, it just swaps in a new instance on the class.
```C++
	if (this != &rhs)
	{
		Point	tmp(rhs);
		std::swap(*this, tmp);
	}
	return (*this);
```
that is more elegant and safe, as it is a standard library function and is guaranteed to work.

## the debug header
in ex03 i started using a debug header to only pront the messages of the constructor and the other stuff when i need them
it is enabled with the DEBUG flag in the Makefile
