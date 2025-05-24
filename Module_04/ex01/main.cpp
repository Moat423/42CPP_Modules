#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

const Animal *turnIntoAnimal(const Animal *xyz) { return (xyz); }

int main()
{
	std::cout << "--------------------Please don't set the worls on fire--------------------" << std::endl << std::endl;
	const Animal	*animalArray[4];
	const Cat		mimi;
	const Dog		wauwi;
	const Dog		*wauwiPointer = &wauwi;
	const Cat		mimisTwin(mimi);
	const Animal	wauwisTwin(*wauwiPointer);

	animalArray[0] = turnIntoAnimal(&mimi);
	animalArray[1] = wauwiPointer;
	animalArray[2] = &mimisTwin;
	animalArray[3] = &wauwisTwin;
	animalArray[4] = new Cat();
	animalArray[5] = new Dog();
	/*for (size_t i = 0; i < 4; (i += 2)) {*/
	/*	animalArray[i] = new*/
	/*}*/
	
	return 0;
}
