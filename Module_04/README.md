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
