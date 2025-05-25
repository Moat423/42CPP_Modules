# Subtype Polymorphism, Abstract Classes, and Interfaces

## virtual

srcs: https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c

What does writing virtual in front of something even mean and do?

virtual means that a method that will be called, might have been overwritten by an inheriting class, and C++ will use that special one.
C++ will look up the actual type of the object at runtime and call the most-derived override of that function—even if the pointer or reference is of the base class type
So that means, even if you call a method through a base class pointer, it will call the most advanced method.

that is the base requirement for polymorphism:
the ability for code to call functions on objects without knowing their exact type, as long as they share a common base class with virtual functions

## object slicing

An interesting observation and learning about best practices.

```C++
const Animal* schnuffi = new Dog();
const Animal* mitzi = new Cat();
const Animal *animalCollection[4];

	animalCollection[0] = new Cat;
	animalCollection[1] = new Dog();
	animalCollection[2] = new Animal(*mitzi);
	animalCollection[3] = new Animal(*schnuffi);
```
using a copy constructer of animal from an animal pointer that actually points to an inherited class will not recognize that its actually an inherited class.
the copy constructor of Animal will just copy the Animal parts and disregard any overridden functions.
therefore:

	for (size_t i = 0; i < 4; i++)
		animalCollection[i]->makeSound();
outputs:
😺 MEOOOOW (Cat is meowing)
🐶 Wau wau (Dog is barking)
a wild Cat makes an unrecognized sound
a wild Dog makes an unrecognized sound

I am constructing a new Animal object by copying only the Animal part of the original Cat or Dog. The derived parts (e.g., the overridden methods, additional data members) are sliced off
so it copies the type but not the overwritten function makeSound.
That is what is called object slicing.

this will lead to problems, because the destructor will ALSO not be overwritten and that means the object will get destructed with just the Animal destructor,
which can lead to undefined behaviour.

--> Object slicing happens when copying derived objects into base class objects, losing derived-specific data and behavior

## Memory allocation errors

srcs: https://wiki.sei.cmu.edu/confluence/display/cplusplus/MEM52-CPP.+Detect+and+handle+memory+allocation+errors

#### throwing an exception
	try {
	_brain = new Brain;
	} catch (const std::bad_alloc &e) {
		std::cerr << "Memory allocation failed" << e.what() << std::endl;
	}


## Casting

srcs: https://arne-mertz.de/2015/01/a-casting-show/

C style type casting is to be avoided, since it is not as memory safe, as there are no tests performed.
$$(const Cat*) AnimalPointerToCat;$$

there is also function style casting, which is basically the same as the C style typecasting
$$double(getInt());$$

there is also a C11 casting, which has some more restrictions for use, but is still very broad
$$long{getInt()}$$

### C++ explicit cast operators 

#### `const_cast`

```C++ 
const Cat &constantCat;
const_cast<Cat&>(constantCat);
``` 

Its only use is to remove or add the const qualifier to a pointer or reference.

#### `reinterpret_cast`

most unsafe cast, it just reinterprits the sequence of bits in a variable into another type (like pointer to int)
can be used on completely unrelated types and has no checks.

#### `static_cast`

no runtime checks, so might lead to undefined behaviour, if downcasting and it's not actually the expected type.

```C++ 

```
#### `dynamic_cast`

performs runtime type checking, if not as expected, returns a nullpointer for pointers.

```C++ 
	const Cat* cat = dynamic_cast<const Cat*>(animalArray[i]);
```


## Abstract Classes

srcs: https://en.wikibooks.org/wiki/C++_Programming/Classes/Abstract_Classes

Have at least one pure virtual function:
An abstract class must have at least one pure virtual function. This is a virtual function declared with = 0 in its declaration, meaning it has no implementation in the base class and must be implemented by derived classes.

Cannot be instantiated:
You cannot create objects of an abstract class directly. However, you can declare pointers and references to abstract classes, which is useful for polymorphism.

Used as a base class:
Abstract classes are designed to be inherited from. Any concrete (non-abstract) class derived from an abstract class must implement all pure virtual functions; otherwise, it remains abstract.

Can have regular members:
Abstract classes can have data members, constructors, destructors, and even non-pure (concrete) member functions in addition to pure virtual functions.


src: https://www.simplilearn.com/tutorials/cpp-tutorial/abstract-class-in-cpp

##### Why Can't We Make an Abstract Class Object?

When we construct a pure virtual function in Abstract, we reserve a slot in the VTABLE(discussed in the previous topic) for a function, but we don't put any address in that slot. As a result, the VTABLE will be unfinished.

Since the VTABLE for the Abstract class is missing, the compiler will refuse to let you create an object for it and will show an error message if you try.

So tldr:
An abstract class cannot be instantiated directly, but it can be used as a parent.


## ex03: "interfaces"

I disagree with implementing a getter like this:

$$std::string const &AMateria::getType() const;$$
since the whole point of having seperate getters and setters is, to have the getter return a value that is different from the actual field in the class,
so one can not accidentally set that field when it's not inteded. In this case, there is no setter, because the getter does it all.
