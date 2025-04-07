#Inheritance

srcs:
https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm

class Rectangle:	public	Shape
class declaration
					type of inheritance
							name of class to inherit from
{...

### type of inheritance

Public Inheritance − When deriving a class from a public base class, public members of the base class become public members of the derived class and protected members of the base class become protected members of the derived class. A base class's private members are never accessible directly from a derived class, but can be accessed through calls to the public and protected members of the base class.
Protected Inheritance − When deriving from a protected base class, public and protected members of the base class become protected members of the derived class.
Private Inheritance − When deriving from a private base class, public and protected members of the base class become private members of the derived class.

### descructors

I need virtual functions if I intend to have subclasses 
that override the behavior of these functions.
I need a virtual destructor if I intend to delete a derived class object
through a pointer to a base class.  
If you don't declare the base class destructor as virtual and delete a 
derived object through a base class pointer, the behavior is undefined. 
The base class destructor will be called, but the derived class's destructor won't, 
leading to memory leaks and potential crashes.

so what that means is when i do
	ClapTrap	*pretender = new FragTrap("pretender");
	ClapTrap	mutant(*pretender);

i should not get memory leaks.
this is really weird, as i am copying from a derived class to a base class, but it does not copy the derived class functions.

### virtual

https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
