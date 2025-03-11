Learning from this:

std::string is an interesting class, we were told to avoid heap allocation. But that is difficult, this class is always heap allocated automatically (it gets automatically allocated and destructed because thats how C++ works //be more accurate here!!)
and the only way to avoid allocation on the heap is by relying on C fixed size arrays or the SSO (Small String Optimization) of the string class. that means it allocates 15 bytes on the stack for the string, but if it is larger, then thats not possible. I could have restricted user input, but decided against it.

there is an interesting function: setw() which can control how much is read from cin.
But i run into problem ignoring the rest of the line then. it is just not as clean to use
		std::cin >> std::setw(7) >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
getline seems to just do a better job.

It is important to always check that the input buffer is cleaning after having the user type in something. So i learned, to call the cin.ignore method after doing a cin << i or other things.

Also, its a really nice feature of C++ to declare functions as const. that means, the compiler knows, they will not change any members of the class, and can optimise better.
I will try to use that in the future.

## getting input from the user

int i;

cin << i

this means that cin will read from the input buffer, and store it in i. But if the user types in a string, then the input buffer will be in a fail state, and the next time cin is called, it will not work. So what needs to be done, is to clear potential error flag that was put up, and ignore the rest of the line.
there are two ways to see if the input buffer is in a fail state:
std::cin.fail() or std::cin.bad()
and one can also just check the return of cin. If it is false, then the input was successful.
if (!(std::cin >> i)) {
	//code in case of failure
}

clearing the flag:
cin.clear();

ignoring the rest of the line:
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

in detail this is explained here: http://www.cplusplus.com/reference/istream/istream/ignore/
that means "If this is exactly numeric_limits<streamsize>::max(), there is no limit"
so that it will never stop, until it encounters the delimiter, which in this case is '\n'.
(I found some stuff about even the counting of characters from the stream being disable upon using this ginormous number:
https://stackoverflow.com/questions/53065945/value-of-numeric-limitsstreamsizemax-in-c )



things to read:
https://vorbrodt.blog/2019/03/30/sso-of-stdstring/
https://pvs-studio.com/en/blog/terms/6658/
https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp10_IO.html
http://duramecho.com/ComputerInformation/WhyHowCppConst.html
