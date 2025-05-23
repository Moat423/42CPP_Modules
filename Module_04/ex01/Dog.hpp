#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog( void );
		Dog( Dog const &copy );
		Dog &operator=( const Dog &assign );
		~Dog( void );

		std::string getType( void ) const;
		void makeSound() const;
};

#endif // !DOG_HPP
