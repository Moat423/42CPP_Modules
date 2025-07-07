#include "Debug.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main ( void )
{
	std::cout << BLUE << "=== dynamic_cast ===" << RESET << std::endl;
	std::cout << "Generating a random Base instance..." << std::endl;
	Base *base = generate();
	std::cout << "Identifying the instance using a pointer:" << std::endl;
	identify(base);
	std::cout << "Identifying the instance using a reference:" << std::endl;
	identify(*base);
	return (0);
}

// randomly instantiates A, B, or C and returns the instance as a Base pointer.
Base * generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}

	int baseType = rand() % 3;
	switch (baseType)
	{
		case 0:
			debug("Generating A");
			return new A();
		case 1:
			debug("Generating B");
			return new B();
		case 2:
			debug("Generating C");
			return new C();
		default:
			debug("Unknown type generated");
			return NULL;
	}
}

// prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Unknown type" << std::endl;
	}
}

// prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
//inside this function is forbidden.
void identify(Base& p)
{
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
	} catch (const std::exception &e) {
		try {
			static_cast<void>(dynamic_cast<B&>(p));
			std::cout << "B" << std::endl;
		} catch (const std::exception &e) {
			try {
				static_cast<void>(dynamic_cast<C&>(p));
				std::cout << "C" << std::endl;
			} catch (const std::exception &e) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}
