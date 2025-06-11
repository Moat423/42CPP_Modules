# 42CPP_Module05
An artificial nightmare of offices, corridors, classes and others with the purpose of getting familiar with C++

## Exception classes

[stackoverflow-exception-class](https://stackoverflow.com/questions/35215169/c-create-a-class-exception)

## Exception specification

https://cplusplus.com/doc/tutorial/exceptions/

something one might come accross in older codebases and maybe even std98 coding: **dynamic exception handling**

$$double myfunction (char param) throw (int);$$

this throws std::unexpected for any thing other than int.
if int is not given and left ampty, it throws std::unexpected for all.

normally functions don't throw std::unexpected right away but instead follow the normal path, looking for their exception handler.

from [cplusplus](https://cplusplus.com/doc/tutorial/exceptions/)
"The C++ Standard library provides a base class specifically designed to declare objects to be thrown as exceptions. It is called std::exception and is defined in the <exception> header. This class has a virtual member function called what that returns a null-terminated character sequence (of type char *) and that can be overwritten in derived classes to contain some sort of description of the exception.
"
```C++
class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;
```
this is really coo cause we can just overwrite "what" to give it a meaningful and explanatory exception name.

to catch derived exeption casses, we can catch them by reference of the exception class
just like how a pointer of a base class can hold all derived classes, we can get the value of a class with the base reference.

```c++
int main () {
  try
  {
    throw myex;
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }
  return 0;
}

```

so for this project I am creating a new class in my bureaucrat:

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

Did you know, that when created nested classes, and you wnat to put the implementation somehwere, you have to use the "qualified name" meaning including the outer classes?

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

yey, let's nest classes and make an endless row of classes inside classes XD

this class is using the "throw" to declare that this function will call std::unexpected.
However, I can change the return of the error. it is the return of this function (const char *)

### Exception specification

[history of exception specifications](https://devblogs.microsoft.com/oldnewthing/20180928-00/?p=99855)
C++98 introduced exception specifications like throw(int, char*), which declare what types of exceptions a function might throw
exception specifications: throw(int, char*)
These were removed in C++17 and deprecated in C++11. For portable, modern code, you should not use them

#### But why are they BAD?
[reason you shouldn't use exception specifications](https://softwareengineering.stackexchange.com/questions/114338/why-are-exception-specifications-bad)

- Weak Enforcement:
Compilers do not strictly enforce these specifications. If a function throws an exception not listed, the program calls std::unexpected() and usually terminates, which is not much safer than undefined behavior.

- Performance Overhead:
They require runtime checks for unexpected exceptions, which can slow down your program and increase code complexity, with little practical benefit.

- Fragile and Dangerous:
If you throw an exception type not listed, your program will terminate in a hard-to-debug way, rather than just propagating the error. This makes code maintenance and evolution risky.

- Removed for Good Reason:
Because of these issues, dynamic exception specifications were deprecated and then removed in modern C++ standards. Only throw() (meaning “does not throw”) survived, and in C++11 and later, it’s replaced by noexcept.

Avoid using exception specifications like throw(int, char*) in any new code. They are unreliable, add overhead, and have been removed from the language for good reason

### marking with throw()

Best Practice for C++98
Always mark destructors as throw()
Even if empty:

```cpp
~MyClass() throw() {}
```
Handle errors internally
Use logging/cleanup instead of exceptions:

```cpp
~FileHandler() throw() {
    if (!_isClosed) {
        ::close(_fd); // Non-throwing fallback
    }
}
```
the above code is something to remember, I need to handle things that CAN throw exceptions, like the closing of files or other mechanism like threads with more care in destructors.

**Destructors should never throw exceptions.**
This is a fundamental C++ guideline, especially in C++98 and later standards.

Why?
- Stack Unwinding Danger:
If an exception is already active (e.g., during stack unwinding due to another exception) and a destructor throws a new exception, this leads to two active exceptions.
This situation is illegal in C++ and causes std::terminate to be called, abruptly ending your program.

- Resource Management:
Destructors are typically used to clean up resources. If they throw, it’s unclear whether the resource was properly released, leading to leaks or undefined behavior.

- Exception Specifications and Optimization
Marking with throw():
In C++98, marking a destructor with throw() tells the compiler that the destructor does not throw exceptions:

```cpp
~MyClass() throw() { /* cleanup code */ }
```
This is not just for style—compilers can optimize more aggressively:

- They may omit exception-handling code paths for such destructors.
- They can safely assume that stack unwinding won’t be interrupted by further exceptions.
- This can enable register/cache optimizations and reduce code size.

Error Handling Inside Destructor:
By marking with throw(), you force yourself to handle all errors inside the destructor (e.g., logging, cleanup), rather than propagating them out.

Is throw() Dead Weight?
Not Dead Weight in C++98:
In C++98, throw() is valuable for both documentation and optimization.
It explicitly communicates intent and enables compiler optimizations.

Modern C++:
In C++11 and later, destructors are implicitly noexcept (non-throwing), so the explicit throw() is less necessary, but in C++98 it is good practice

## things specific to this task

A Bureaucrat had to have:
• A **constant** name
• A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade)

therefore i could not change the name without recreating the object.

The Form class has:
• A constant name
• A boolean indicating whether it is signed (at construction, it is not)
• A constant grade required to sign it
• A constant grade required to execute it
All these attributes are private.

## other Learnings

### C vs C++

in C you can create compount literals:
$$(struct Point){1, 2}$$
which you can't do in C++.

C++11 and later allows for this syntax:
$$Form{"tempForm", 140, 145}$$

so I am left with three choices for assigning:

```C++
// Option 1
Form timsForm(Form("tempForm", 140, 145));

// Option 2
Form timsForm = Form("tempForm", 140, 145);

// Option 3 (C++11 and above!)
Form timsForm = Form{"tempForm", 140, 145};
```

However note, that Option 2 is **equivilant** to option 3.
Even though it uses an equal, it's actually also copy constructing.

### getters and getters

encasulation is the reason why one would use getters and setters.
the setters might even be private or protected and the vaue is always private or protected.
Making the setter private bascially makes it read ony from the outside.

Encapsuation means, that eveything is spererated well.

so for this project, I decided to have read only classes basicaly.

### Error: Member access into incomplete type

this usually means, that the file is missing some headers that should be inscluded. in this case, in an included header, there is only a forward declaration of another class, but not its full declaration.
