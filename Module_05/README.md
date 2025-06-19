# TODO: make the debug.hpp disappear
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

## Exceptions on IO streams

[adding exceptions to streams](https://akrzemi1.wordpress.com/2019/05/23/operation-cancelling-and-stdfstream/)

I learned that:
"In fact IO streams were designed before we had exceptions in C++. So, in order to have our ofstream throw exceptions we have to instruct it to do so before we even open the file".

```C++
void save()
{
  std::ofstream f; 
  f.exceptions(ios_base::failbit | ios_base::badbit);
 
  f.open("work.txt");
  f << provideA();
  f << provideB();
  f.flush(); // write data (can throw)
} // only close
```

1. declare a stream (f)
2. tell it to report the following errors (using a mask with failbit or badbit)
3. flush in function, not in destructor, as destructor can never throw.

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

## RNG

since I am not allowed to use c11 random libraries or C libraries, I will code my own RNG.
Since i just need a bool, let's not make it too complicated, i will go with Pseudo Random Number Generators.

I could go with this:
https://en.wikipedia.org/wiki/Linear_congruential_generator


or an Xorshift seems fine:
https://en.wikipedia.org/wiki/Xorshift
```C++
class BoolGenerator {
    unsigned int state;
public:
    explicit BoolGenerator(unsigned int seed = 1) : state(seed) {
        if (seed == 0) state = 1;  // Prevent invalid zero seed
    }
    
    bool next() {
        // XORshift32 algorithm (George Marsaglia)
        state ^= state << 13;
        state ^= state >> 17;
        state ^= state << 5;
        return state & 1;  // Extract least significant bit
    }
};
```

on that note:


### mutable

mutable unsigned int state

means that state is a variable, that can be modiefied from functions that are const!.
its like a special exemption.
it's handy if i have a const function, but down the line i want to change something. like here.

### MOAR randomness

      _boolGen(static_cast<unsigned int>(std::time(NULL) ^ reinterpret_cast<unsigned long>(this)))
this is nice, it means XORing the time with the pointer to this, which is going to be different for each object created. so if ever two objs are created at the same time, they will have different seeds.

### explicit

In C++98, always use explicit for single-argument constructors unless you want implicit conversions.

Explicit prevents accidental convertions and makes code more intentional and clear.
When using it, it will throw an error if the constructor is given a wrong type, which is good, cause it prevents some accidental bugs.

			explicit BoolGenerator(unsigned int seed) : state(seed ? seed : 1) {}

### Factories

exercise 03 is about making a kind of factory that returns an object and saves it in a pointer of the parent class.

#### typedef vs. no typedef

	typedef AForm* (*formMaker)( std::string target );
	formMaker formMakers[3] = {
		makeRobotomyRequestForm,
		makeShrubberyCreationForm,
		makePresidentialPardonForm
	};

is the same as:

	AForm *(*formMakers[3])(const std::string target ) = {
		makeRobotomyRequestForm,
		makeShrubberyCreationForm,
		makePresidentialPardonForm
	}

the syntax for a function pointer is this:
AForm* (*formMaker)( std::string target )

and you can declare an array of function pointers in one go. the acutal "function pointer part" is the one in the first brackets: (*formMaker)
and either declare an array or use a typedef to call a type of that form and make an array.

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
