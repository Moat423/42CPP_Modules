#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	std::cout << "--------------------Please don't set the world on fire--------------------" << std::endl << std::endl;
	const Animal	*animalArray[4];
	const Cat		*mimi = new Cat();
	const Dog		*wauwi = new Dog();

	animalArray[0] = mimi;
	animalArray[1] = wauwi;
	// animals getting ideas:
	mimi->setIdea(0, "I hate water.");
	mimi->setIdea(1, "I am a most beautiful cat.");
	// Creating new animals to check if deep copied correctly
	const Cat *mimisTwin = new Cat(*mimi);
	mimisTwin->setIdea(1, "Your couch is mine, I peed on it.");
	animalArray[2] = mimisTwin;
	const Dog *wauwisTwin = new Dog(*wauwi);
	animalArray[3] = wauwisTwin;
	// animalArray[4] = new Cat();
	// animalArray[5] = new Dog();
	for (size_t i = 0; i < 4; (i += 2)) {
			const Cat* cat = dynamic_cast<const Cat*>(animalArray[i]);
			if (cat) {
				cat->makeSound();
				cat->printIdeas();
			}
			const Dog* dog = dynamic_cast<const Dog*>(animalArray[i + 1]);
			if (dog) {
				dog->makeSound();
				
			}
		}
	for (size_t i = 0; i < 4; ++i) {
		delete animalArray[i];
	}
	// delete animalArray[4];
	// delete animalArray[5];
	return 0;
}
