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
