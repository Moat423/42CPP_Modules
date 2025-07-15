#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <vector>

int	subject_main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	// testing if i can init with vector
	std::vector<int> v(2, 3);
	MutantStack<int, std::vector<int> > ms(v);
	std::cout << ms.top() << std::endl;
	return 0;
}


int	test_list()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
	return (0);
}

int main()
{
	std::cout << "Understanding the stack adaptive container and its iterators" << std::endl;
	std::cout << "testing how normal behaviour would look, by testing lists" << std::endl;
	test_list();
	std::cout << "testing the actual MutantStack" << std::endl;
	subject_main();
	return 0;
}
