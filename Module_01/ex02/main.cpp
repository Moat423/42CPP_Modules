#include <string>
#include <iostream>

int	main(void)
{
	const std::string string = "HI THIS IS BRAIN";
	const std::string *stringPTR = &string;
	const std::string &stringREF = string;

	std::cout << "The memory address of the string variable:" << std::endl;
	std::cout << &string << std::endl;
	std::cout << "The memory address held inside stringPTR, pointing to string:" << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << "The memory address held inside stringREF:" << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "The value of the string variable:" << std::endl;
	std::cout << string << std::endl;
	std::cout << "The value when dereferencing stringPTR:" << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << "The value of stringREF:" << std::endl;
	std::cout << stringREF << std::endl;
}

