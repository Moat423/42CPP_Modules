#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

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
	const Animal* mietzi = new Cat();
	std::cout << std::endl;
	std::cout << "Type of dog:" << std::endl;
	std::cout << schnuffi->getType() << " " << std::endl;
	std::cout << "Type of cat:" << std::endl;
	std::cout << mietzi->getType() << " " << std::endl;
	schnuffi->makeSound();
	mietzi->makeSound(); //will output the cat sound!
	meta->makeSound();
	const Cat	orangeTabby = Cat();
	func(&orangeTabby);
	std::cout << std::endl << "Time to say goodbye........" << std::endl;
	delete meta;
	delete schnuffi;
	delete mietzi;



	std::cout << std::endl << "closing the ANIMAL CREATOR" << std::endl;
	std::cout << "WELCOME to the WRONG ANIMAL CREATOR. You  are loged in as the creator" << std::endl << std::endl;
	std::cout << "creating a generic Animal:" << std::endl;
	const WrongAnimal* muta = new WrongAnimal();
	std::cout << std::endl;
	std::cout << "creating a dog:" << std::endl;
	const Animal* scruffi = new Dog();
	std::cout << std::endl;
	std::cout << "creating a cat:" << std::endl;
	const WrongAnimal* paw = new WrongCat();
	std::cout << std::endl;
	std::cout << "Type of dog:" << std::endl;
	std::cout << scruffi->getType() << " " << std::endl;
	std::cout << "Type of cat:" << std::endl;
	std::cout << paw->getType() << " " << std::endl;
	scruffi->makeSound();
	paw->makeSound(); //will not output the cat sound
	muta->makeSound();
	delete muta;
	delete scruffi;
	delete paw;
	return 0;
}
