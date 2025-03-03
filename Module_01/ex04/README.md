# Open, close, stringstream

there are some ways to open files in C++.
You can open it on initializiation:
```
ifstream in("filename.ext", ios_base::in);
```

Or by calling a method on the object:
```
ifstream myfile;
myfile.open("<path to file>");
myfile.read(somedata.data(), nsize);
myfile.close();
```

source:
https://stackoverflow.com/questions/7880/how-do-you-open-a-file-in-c

I decided to do it in initialization.

Since the istream can not be directly saved into a string, i save it inside a stringstream and convert that,
the alternative would be to use getline or read and read chunks and reallocate as it gets bigger.
using getline would mean, having to append newlines inbetween every call.

stringstreams are neat. remember them for the future.


// TODO: explain this
these kind of expressions:
```
	if (std::string(argv[2]).empty())
```
kind of seem like anonymous assingments. it just converts it and then i can directly use it.
// needs research if this is fast, and if i should be doing this, if i then do the same converion again when passing argv[2] to a function that takes std::string
