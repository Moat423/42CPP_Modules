#include <iostream>
int main (void) {
	int *a = new int();
	std::cout << "*a = " << *a << std::endl;
	delete a;
	return 0;
}
