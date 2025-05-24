#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( Cat const &copy );
		Cat &operator=( const Cat &assign );
		~Cat( void );

		std::string getType( void ) const;
		void makeSound() const;
		void printIdeas( void ) const;
		void setIdea(const size_t index, const std::string idea) const;
		std::string	getIdea( const size_t index) const;
	private:
		Brain	*_brain;
};

#endif // !CAT_HPP
