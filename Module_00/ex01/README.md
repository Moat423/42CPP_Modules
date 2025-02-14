Learning from this:

std::string is an interesting class, we were told to avoid heap allocation. But that is difficult, this class is always heap allocated automatically (it gets automatically allocated and destructed because thats how C++ works //be more accurate here!!)
and the only way to avoid allocation on the heap is by relying on C fixed size arrays or the SSO (Small String Optimization) of the string class. that means it allocates 15 bytes on the stack for the string, but if it is larger, then thats not possible. I could have restricted user input, but since a phone number is internationally maximally 15 digits and i need the null terminator, complzing with international norme for saving telephone numbers is more important here.

there is an interesting function: setw() which can control how much is read from cin.
But i run into problem ignoring the rest of the line then. it is just not as clean to use
		std::cin >> std::setw(7) >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
getline seems to just do a better job.

It is important to always check that the input buffer is cleaning after having the user type in something. So i learned, to call the cin.ignore method after doing a cin << i or other things.
