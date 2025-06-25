#Casts

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



