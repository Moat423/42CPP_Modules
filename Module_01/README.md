# CPP Module 01
### all about contructing, destructing, memory allocation, reference, pointers to members and the usage of the switch in CPP

## srcs:
https://www.geeksforgeeks.org/new-vs-malloc-and-free-vs-delete-in-c/

### new (and delete) vs malloc (and free)
new is a C++ feature and uses the constructor and destructor of a class,
while the c functions malloc and free don't.
Therefore it makes sense to use new and delete in C++ code.

Other than that it works just like any other dynamic allocation, as in that the programmer
has to take care of the freeing of the memory and it's scope.


ex00
teaches us to use stack allocation (using the automatic destructors upon leaving
function scope) when an object needs to only exists in the current scope,
and heap allocation, if we need an object to exist beyond the function.
therefore we had two functions:
randomChump and newZombie
to prove that in the first one, with stack allocation they exist only in that function
and with the other, they get passed on to the calling function.
