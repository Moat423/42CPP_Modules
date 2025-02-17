to check this, use the git word diff
git diff --no-index --color-words=. 19920104_091532.log test.log

this has a lot of typedefs.
tyoedefs might be good to use in the future, cause it let's me circumvent having to write out large class names or type names or the constant std:: in front of the standard classes. Still, I am not sure, how much I will use this, since readablity is a concern and i don't want people reading the code to think i have custom classes when i am using standard ones, or not recognize classes. Maybe that concern is not that valid, but i will keep it in mind.

A word on static:
the static declaration inside a class constrains the lifetime of the value over all instances the class is being used (correct me if I am  wrong here // make the explanation better)
uses of static:
//todo

As I was given Account.hpp and tests.cpp and the .log file which i had to reproduce with an Account.cpp file I had to write,
I did not change any of the other files.

However, while trying to understand the tests.cpp file, I found it curious that they initialized their vectors by first creating an array and then copzing the values over. In my humble and untrained opinion, I would direclty initialiye the vector with literals,

the typedef is just an alias for a vector of ints. therefore instead of doing the following and assigning from the array to the vector:

cpp code:
	typedef std::vector<int>								  ints_t;

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

I would rather do this:

	ints_t 				deposits = { 5, 765, 564, 2, 87, 23, 9, 20 };
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

maybe they just wanted us to understand how vectors can be initialized by giving it a starting pointer and an ending pointer. WHich I really did not know before.

why are those functions are static in the class:

class Account {
public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

what this implies is, that they are shared accross every single "Account" class object, that the program creates, but they still have their scope in which they exist.
so it is memory efficient in that way.

But it also means, you have to initialize them (give them values) in the .cpp file.


Functors (function Objects)
https://www.programiz.com/cpp-programming/functors

basically an overload of the () operator to call an abject as if it was a function.
the good thing about it, is that they can retain their state and that they can be more easily optimized by compilers (oftentime can be inlined. also less errorprone, cause compilers can check them easier)
