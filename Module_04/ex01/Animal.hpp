#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
	public:
		Animal( void );
		Animal( std::string type );
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal& operator=( const Animal &assign);
		virtual void makeSound( void ) const;
		virtual std::string getType( void ) const;
	protected:
		std::string	type;
};

#endif //ANIMAL_HPP
