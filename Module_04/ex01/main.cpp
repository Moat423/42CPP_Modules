#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	std::cout << "--------------------Please don't set the world on fire--------------------" << std::endl << std::endl;
	const Animal	*animalArray[4];
	const Cat		*mimi = new Cat();
	Dog		*wauwi = new Dog();

	std::cout << std::endl;
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
	Dog *wauwisTwin = new Dog(*wauwi);
	wauwisTwin->setIdea(1, "Squirrel!!!!!");
	animalArray[3] = wauwisTwin;
	std::cout << std::endl;
	for (size_t i = 0; i < 4; (i += 2)) {
			const Cat* cat = dynamic_cast<const Cat*>(animalArray[i]);
			if (cat) {
				cat->makeSound();
				cat->printIdeas();
			}
			const Dog* dog = dynamic_cast<const Dog*>(animalArray[i + 1]);
			if (dog) {
				dog->makeSound();
				dog->printIdeas();
				
			}
		}
	//Making wauwi have the same ideas as his twin
	//making references
	Dog &wauwiRef = *wauwi;
	Dog &wauwisTwinRef = *wauwisTwin;
	std::cout << std::endl;
	std::cout << "setting the first dogs ideas to the same as the second dogs ideas" << std::endl;
	wauwiRef = wauwisTwinRef;
	std::cout << "printing wauwis ideas:" << std::endl;
	wauwi->printIdeas();
	std::cout << "printing wauwisTwins ideas:" << std::endl;
	wauwisTwin->printIdeas();
	std::cout << std::endl;
	wauwi->setIdea(1, "Dig dig dig!");
	wauwi->setIdea(2, "When will Human come back?");
	std::cout << "printing wauwis ideas:" << std::endl;
	wauwi->printIdeas();
	std::cout << "printing wauwisTwins ideas:" << std::endl;
	wauwisTwin->printIdeas();
	std::cout << std::endl;
	for (size_t i = 0; i < 4; ++i) {
		delete animalArray[i];
	}
	return 0;
}
