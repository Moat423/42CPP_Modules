#Inheritance

srcs:
https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm

class Rectangle:	public	Shape
class declaration
					type of inheritance
							name of class to inherit from
{...

### Inheritance design

https://isocpp.org/wiki/faq/multiple-inheritance#mi-example

bridge pattern: have one class with many derived classes and nest a pointer to another class inside that class, so the nested class can be arbitrarily chosen

nested generalization: have one base with many derived classes and write a derived class for every single comnbination of the derived + the feature that you want (so don't externaize it into a seperate class. this means a lot of duplicate code, but fine grain control)

multiple-inheritance: inherits from at least two separate parents

		Diamond inheritance: subproblem of multiple inheritance. A particular class appears more than once in the class's inheritance

To avoid the duplicated base class subobject that occurs with the “dreaded diamond”, you should use the virtual keyword in the inheritance part of the classes that derive directly from the top of the diamond

### virtual inheritance

https://stackoverflow.com/questions/2659116/how-does-virtual-inheritance-solve-the-diamond-multiple-inheritance-ambiguit

"Code class B: virtual A means, that any class inherited from B is now responsible for creating A by itself, since B isn't going to do it automatically."

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

### shadowing

https://www.programiz.com/cpp-programming/function-overriding

shadowing is when both the derived and the base class have the same function implemented.
But when the funciton gets called from a derived class, the derived class function with the same name gets called instead of the base clas Fkt, even though both exist.
You can however call the base class funciton from the derived class pointer as well:

	FR4G_TRAP.ClapTrap::attack("another target");

dereivedClassInstance.Base::functionFromBase();
