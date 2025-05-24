#include "A_Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	std::cout << "--------------------Please don't set the world on fire--------------------" << std::endl << std::endl;
	const A_Animal	*animalArray[4];
	const Cat		*mimi = new Cat();
	const Dog		*wauwi = new Dog();

	animalArray[0] = mimi;
	animalArray[1] = wauwi;
	// animals getting ideas:
	mimi->setIdea(0, "I hate water.");
	mimi->setIdea(1, "I am a most beautiful cat.");
	wauwi->setIdea(0, "I am a good boy!");
	wauwi->setIdea(1, "Something smells goooooood");
	// Creating new animals to check if deep copied correctly
	const Cat *mimisTwin = new Cat(*mimi);
	mimisTwin->setIdea(1, "Your couch is mine, I peed on it.");
	animalArray[2] = mimisTwin;
	const Dog *wauwisTwin = new Dog(*wauwi);
	wauwisTwin->setIdea(1, "Squirrel!!!!!");
	animalArray[3] = wauwisTwin;
	for (size_t i = 0; i < 4; (i++)) {
				animalArray[i]->makeSound();
				animalArray[i]->printIdeas();
		}
	//Making wauwi have the same ideas as his twin
	std::cout << "setting the first dogs ideas to the same as the second dogs ideas" << std::endl;
	wauwi = wauwisTwin;
	std::cout << "printing first dogs ideas:" << std::endl;
	wauwi->printIdeas();
	std::cout << "printing second dogs ideas:" << std::endl;
	wauwisTwin->printIdeas();
	for (size_t i = 0; i < 4; ++i) {
		delete animalArray[i];
	}
	return 0;
}
