#Casts

C++ provides several cast operators. static_cast is for safe, standard conversions; reinterpret_cast is for low-level, risky reinterpretation; const_cast adds or removes constness; and dynamic_cast is for safe casting in class hierarchies. Prefer C++ casts over C-style casts for clarity and safety.

#### static_cast
Purpose: Performs well-defined conversions between compatible types (e.g., int to float, pointers within an inheritance hierarchy, etc.).
Checks: Performs some compile-time checks to prevent unsafe conversions, but does not check at runtime.
	static_cast<void>(copy);
	fl = static_cast<float>(nb);

#### reinterpret_cast
Purpose: Reinterprets the bit pattern of a value as another type (e.g., pointer to integer, or between unrelated pointer types).
Checks: No safety checks; very risky. Use only when you know exactly what you are doing.
	reinterpret_cast<uintptr_t>(ptr); // converts from ptr to and int type
	reinterpret_cast<Data*>(raw); // makes the int back into a usable pointer

#### const_cast
Purpose: Adds or removes const or volatile qualifiers from a variable.
Checks: Only works with pointers or references.
	const int* ci = ...;
	int* i = const_cast<int*>(ci);
Take heed: modifying a value originally declared const is undefined behavior.

#### dynamic_cast
Purpose: Safely casts pointers or references within an inheritance hierarchy (requires at least one virtual function in the base class).
Checks: Performs runtime checks;
dynamic_cast behaves differently for pointers and references:
With a *pointer*, if the cast fails, it returns NULL. It does not throw an exception in this case.
With a *reference*, if the cast fails, it throws a std::bad_cast exception.


## converter

first draft:
- If the string is a single printable character (and not a digit), treat as char.
- If there is a leading + or - it might be int, float or double.
- If all characters are digits (possibly with a leading + or -), treat as int.
- If it contains exactly one . or an e/E (for scientific notation), and the rest are digits (with possible sign), treat as float/double.
- Otherwise, invalid input.

final checks:
Char: single, nondigit, printable character.
Int: - + at beginning, digits only.
Float: - + at beginning, digits, possibly one dot, possibly one e/E followed by +-, ending with f.
Double: - + at beginning, digits, possibly one dot, possibly one e/E followed by +-, no f at the end, if input too big for int.
```C++
static eScalarType checkType( std::string literal )
{
	size_t	i = 0;
	bool	hasDot = false;
	bool	hasF = false;
	bool	hasDigit = false;
	int		scientific = 0;

	if (literal == ("nan") || literal == ("-inf") || literal == ("+inf"))
			return (DOUBLE);
	if (literal == ("nanf") || literal == ("-inff") || literal == ("+inff"))
		return (FLOAT);
	if (literal.length() == 1 && !(isdigit(literal[0])))
		return (CHAR);
	if (literal[i] == '-' || literal[i] == '+')
		++i;
	for (; i < literal.length(); i++)
	{
		if (isdigit(literal[i]))
			hasDigit = true;
		else if (literal[i] == '.' && !hasDot && !hasF)
			hasDot = true;
		else if ((literal[i] == 'e' || literal[i] == 'E') && (literal[i + 1] == '-' || literal[i + 1] == '+'))
		{
			i++;
			scientific++;
		}
		else if (literal[i] == 'f' && !hasF && i == literal.length() - 1)
			hasF = true;
		else
		 	return (ERROR);
	}
	if (!hasDigit || scientific > 1)
		return (ERROR);
	if (hasF)
		return (FLOAT);
	if (hasDot || scientific == 1)
		return (DOUBLE);
	else
		return (INT);
}
```
### Char to any

It will always be safe to cast a char to an int, float or double.

### Int

#### int to float
very large or very small values will not be completely accurate, but will fit into a float.
above 16,777,216 and below -16,777,216 the int will not represent the int value accurately anymore.

### Float

#### float to int
--> check bounds of int
floats can be much bigger and smaller than an int. They will also be truncated, but the bigger and smaller values will not fit into an int.

#### float to double
safe, but will add bogus decimal places if the float is not a whole number.
```C++

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

### Int pointers

#### uintptr_t

- requires the [cstdint](https://cplusplus.com/reference/cstdint/) (stdint.h) header

just like intptr_t, this is a typedef for an unsigned integer type that is capable of holding a pointer.
It is defined as bing able to hold a value that can be converted to a pointer and back without loss of information.

[(u)intptr_t](https://cplusplus.com/forum/beginner/180101/) has the crucial difference to normal ints, that you will never loose information for pointer casting.
Normal ints can be too small to hold a pointer value, e.g. on a 64-bit system, an int might be 32 bits, while a pointer is 64 bits, so if you cast a pointer to an int, you might lose 32 bits of information.
It is useful for pointer arithmetic, but it is not a pointer type itself.

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

### io manupulation

[input/output manipulatiors](https://en.cppreference.com/w/cpp/io/manip.html)

an excerpt:

| Manupulator | Effect | Example Output |
| ------------- | -------------- | -------------- |
| Item1 | Item1 | Item1 |
| std::hex | Hexadecimal output | ff
| std::uppercase | Uppercase hex digits | FF
| std::showbase | Adds 0x prefix | 0xff
| std::setw(n) | Sets width (needs <iomanip>) | 00ff
| std::setfill('0') | Fills with zeros | 00ff
| std::dec | Switches back to decimal | 255


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


