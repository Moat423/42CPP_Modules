#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( Cat const &copy );
		Cat &operator=( const Cat &assign );
		~Cat( void );

		std::string getType( void ) const;
		void makeSound() const;
};

#endif // !CAT_HPP
