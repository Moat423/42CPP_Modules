#Casts

### NAN

```C++
f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min()
```
We're checking if the float value is within the range that can be represented by an int. However:

-When comparing NaN with any value (including min/max limits), the comparison always evaluates to false
-When comparing positive infinity, f <= max evaluates to false
-When comparing negative infinity, f >= min evaluates to false
While mathematically these checks would exclude NaN and infinity, in C++ it's considered good practice to explicitly check for NaN and infinity for two reasons:

Clarity: It makes the intent of the code more explicit
Portability: Some compilers or floating-point implementations might have different behavior with these special values


Therefore the reccomended pattern looks like this:

	if (!std::isnan(fl)
			&& !std::isinf(fl)
			&& fl >= std::numeric_limits<int>::min()
			&& fl <= static_cast<float>(std::numeric_limits<int>::max()))
	{
```C++

```

### Design Patterns

#### a static class

A static class is a class that cannot be instantiated and has only static members.
It is advised against using this pattern, as a namespace is usually a better choice.

[anti-pattern: static class](https://softwareengineering.stackexchange.com/questions/134540/are-utility-classes-with-nothing-but-static-members-an-anti-pattern-in-c)
[static is bad](https://softwareengineering.stackexchange.com/questions/408193/should-i-use-a-class-with-only-static-members-to-encapsulate-my-program)
The above link makes the argument, that static classes are basically globals and therefore come with all disadvantages like poor testablility and maintainability as them.

However, they can be used, if you need them as template or want to protect certain things from the user of the class.
[usecase: static template](https://www.embeddedrelated.com/showarticle/1598.php)

I am doing this exercise in awareness, not to use namespaces. So I will use a static class to hold the converting methods.

### strings

from [cplusplus.com](https://cplusplus.com/reference/string/string/npos/)

std::string::npos
static const size_t npos = -1;

**Maximum value for size_t**
npos is a static member constant value with the greatest possible value for an element of type size_t.
This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
As a return value, it is usually used to indicate no matches.
This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type.

-->That means, one can use the npos value to find out if search did not find a match.

###vtable

[q&a uninstantiable classes](https://cplusplus.com/forum/general/12600/)
"Classes that contain at least 1 virtual function have a hidden group of function pointers for all virtual functions. This group is often known as the "vtable". The vtable is constructed automatically in a class's ctor, and when a virtual function is called, the vtable is determined to know which function to call.

```C++
class Base
{
public:
  virtual ~Base() { }  // because it's virtual, this creates an entry in the vtable for 'dtor'

  Base()
  {
    // 'dtor' is set to point to ~Base() here
  }
};

class Derived : public Base
{
public:
  ~Derived() { }  // because Base::~Base is virtual
      // this is also virtual, even if you don't use the virtual keyword

  Derived()
  {
    // 'dtor' in the vtable is set to point to ~Derived() here
  }
};
```

Where and how the vtable is stored is up to the compiler to determine, so it's not something you should try to mess with manually in your code."

What this taught me, is that if one vtable is made, all derived classes will also use a vtable if the first function it inherits from was marked virtual.
-> no need to put the virtual keyword anymore, once it was put in the parent class (still good for clarity)

### conversion operator overloads

As a sidenote I learned, that you can overload the conversion. Normally implicit conversion in C++98 is disabled. But you can cast things. And you can define how it will behave if I cast something.
```C++
operator char();
```
that is the prototype for the overload of the conversion to a char.
It may be used like this:
```C++
c = static_cast<char>(converter);
```
## converter

first draft:
- If the string is a single printable character (and not a digit), treat as char.

- If there is a leading + or - it might be int, float or double.

- If all characters are digits (possibly with a leading + or -), treat as int.

- If it contains exactly one . or an e/E (for scientific notation), and the rest are digits (with possible sign), treat as float/double.

- Otherwise, invalid input.



