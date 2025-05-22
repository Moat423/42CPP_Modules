#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <ostream>

void func(const Animal *xyz) { xyz->makeSound(); }

int main()
{
	std::cout << "WELCOME to the ANIMAL CREATOR. You  are loged in as the creator" << std::endl << std::endl;
	std::cout << "creating a generic Animal:" << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl;
	std::cout << "creating a dog:" << std::endl;
	const Animal* schnuffi = new Dog();
	std::cout << std::endl;
	std::cout << "creating a cat:" << std::endl;
	const Animal* mitzi = new Cat();
	std::cout << std::endl;
	std::cout << "Type of dog:" << std::endl;
	std::cout << schnuffi->getType() << " " << std::endl;
	std::cout << "Type of cat:" << std::endl;
	std::cout << mitzi->getType() << " " << std::endl;
	schnuffi->makeSound();
	mitzi->makeSound(); //will output the cat sound!
	meta->makeSound();
	
	const Animal *animalCollection[4];
	animalCollection[0] = new Cat;
	animalCollection[1] = new Dog();
	animalCollection[2] = new Animal(*mitzi);
	animalCollection[3] = new Animal(*schnuffi);

	for (size_t i = 0; i < sizeof(animalCollection); i++)
		func(animalCollection[i]);
	std::cout << std::endl << "Time to say goodbye........" << std::endl;
	delete meta;
	delete schnuffi;
	delete mitzi;
	for (size_t i = 0; i < 4; i++)
		delete animalCollection[i];
	return 0;
}
