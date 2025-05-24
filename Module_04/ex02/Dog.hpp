#ifndef DOG_HPP
# define DOG_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog: public A_Animal
{
	public:
		Dog( void );
		Dog( Dog const &copy );
		Dog &operator=( const Dog &assign );
		~Dog( void );

		std::string getType( void ) const;
		void makeSound() const;
		void printIdeas( void ) const;
		void setIdea(const size_t index, const std::string idea) const;
		std::string	getIdea( const size_t index) const;
	private:
		Brain	*_brain;
};

#endif // !DOG_HPP
