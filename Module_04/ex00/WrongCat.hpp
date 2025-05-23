#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( WrongCat const &copy );
		WrongCat &operator=( const WrongCat &assign );
		~WrongCat( void );

		std::string getType( void ) const;
		void makeSound() const;
};

#endif // !WRONGCAT_HPP
