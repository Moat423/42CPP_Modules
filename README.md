
#Inheritance

### about initializer lists:

example:
```
HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {}
ClapTrap::ClapTrap(char *name): _name(name){
```
an initializer list is when instead of setting the values in the function body, they are set upon calling the function.
the interesting thing about this is, that it allows you to set const private members:

https://stackoverflow.com/questions/56503689/c-with-initializer-list-a-thing-when-to-use-normal-constructor

quote:
Initialization list is about calling ctor of member variables. If you assign, you are altering the value of instance by using assign function. Obviously, these two are different functions.

There are a few cases that you cannot assign value to member variable in the ctor.

    When the member variable is const.
    When the member variable is an instance of class without default ctor.
    When the member variable is a reference (same reason as above)
    Initializing base class

end quote
