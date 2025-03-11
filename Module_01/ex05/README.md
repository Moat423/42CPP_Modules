# Function Pointers

srcs:
https://www.geeksforgeeks.org/function-pointer-to-member-function-in-cpp/

general forumlation:
```cpp
return_type (ClassName::*pointer_name)(argument_types) = &ClassName::member_function;
```
Remember that one can always call a function from within another member function by using the this pointer.
That means, at no point should one create an instance of the class inside a member function of this class, if i ever see that, i should remember this.

it is also good form to typdef function pointers as I have read:
https://stackoverflow.com/questions/5093090/whats-the-syntax-for-declaring-an-array-of-function-pointers-without-using-a-se

so I typedefed that to make an array out of it.

calling a member function from an array of member functions:
```C++
(this->*MembFunctions[i]) ();
```

First the member function is correctly dereferenced, and then called.
C++ order of precedence is left to right and () before dereference *. So if there were no parenthesis, it would get evaluated wrongly, and the function pointer would not be there properly before is got called.
incorrent order:
```C++
this->*MemFunctions[i] ();
```
the above would not work, because it first calls MemFunctions[i] and then tries to dereference it, which is not possible.
>>>>>>> 7fea7301093516ae2b74de6dc1cbf33b36b1a454
