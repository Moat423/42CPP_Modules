what do learn from this:

References are really usefull, cause I don't need to rewrite some code,
when i already passed things by value, but need them passed by reference instead.
after all, the function declaration can just use a reference type, and passing in a value to that function will automatically pass it by reference.
Thats cool right?

So references are not something new.
They are things to make passing between functions a bit pretteir semantically.
That means, now, instead of having to pass pointers and dereference them,
I know that when i pass by value, i create a full copy in this local scope.
When I pass by reference, i don't create a full copy in the local scope, but instead, just a reference to the original object.

So whats the fuzz? well in C++ it's convention to use references over pointers.
Its kinda more readable for people who are not used to pointers.

## setters

lets take this:
inside main:
```

		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");
		jim.setWeapon(club);
```

now here we are just saying the type we got was a reference and therefore we have a pointer here.
and when we fetch the address of that one, we actually get the address of the original club object, that was created in main.
huh, thats neat. (we could have also passed it by address, but we are trying to learn here guys :D)
```
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
```

now if instead this was passed by value, we would get a dangling pointer, cause the original object would be destroyed after the function call. Thats really not what we want.
```
void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
}
```

why did we even get the address of a reference? well because we wanted to be able to store NULL in the weapon pointer, and we can't do that with a reference, as a reference ALWAYS needs to be initialized (so i would have to give it a value on construction).

## getters

also, we can use references in the getters.
never forget, that the apersand is part of the type and not the variable name, so even though the function declaration looks like this:

	const std::string	&getType();

the function implementation looks like this:
(the ampersand belongs to the std:string and the getType is a member of Weapon.)

```
const std::string	&Weapon::getType()
{
	return (this->_type);
}
```
in my opinion it would be simpler to tell the correct type if the apersand was closer to the type, like so, but i was following a certain norme above.

```
const std::string &	Weapon::getType()
  |		|	|	  |		|		|
next object is immutable in brackts:
		|	|	  |		|		|
     (part of the std class		|
			|	  |		|		|
		C++ string type)		|
				  |		|		|
				is a reference	|
						|		|
				(part of the Weapon class
								|
							method)
```

its a bit hard to express the syntax for std::string or Weapon::getType but think of it as a Surname::Firstname kind of thing.


## assignment versus initialization
srcs:
https://stackoverflow.com/questions/1272680/what-does-a-colon-following-a-c-constructor-name-do
the constructer body only ever contains assignments. So this is invalid for a weapon of reference type (needs to be initialised with value)

```
HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->_weapon = weapon;
	this->_name = name;
}
```

so where is the initialization? well, it's in the constructor initializer list. This is where we initialize the object with the values we pass in.

```
HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {}
```
```
