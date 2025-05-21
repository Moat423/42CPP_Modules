# Subtype Polymorphism, Abstract Classes, and Interfaces

## virtual

srcs: https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c

What does writing virtual in front of something even mean and do?

virtual means that a method that will be called, might have been overwritten by an inheriting class, and C++ will use that special one.
C++ will look up the actual type of the object at runtime and call the most-derived override of that function—even if the pointer or reference is of the base class type
So that means, even if you call a method through a base class pointer, it will call the most advanced method.

that is the base requirement for polymorphism:
the ability for code to call functions on objects without knowing their exact type, as long as they share a common base class with virtual functions

