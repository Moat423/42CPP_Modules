#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
	public:
		Animal( void );
		virtual ~Animal();
		Animal(Animal &copy);
		Animal& operator=( const Animal &assign);
		void makeSound( void ) const;
		virtual std::string getType( void ) const;
	protected:
		std::string	type;
};

#endif //ANIMAL_HPP
