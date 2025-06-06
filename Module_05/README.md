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

## other Learnings

### getters and getters

encasulation is the reason why one would use getters and setters.
the setters might even be private or protected and the vaue is always private or protected.
Making the setter private bascially makes it read ony from the outside.

Encapsuation means, that eveything is spererated well.

so for this project, I decided to have read only classes basicaly.


