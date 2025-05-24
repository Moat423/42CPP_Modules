#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class A_Animal
{
	public:
		A_Animal( void );
		A_Animal( std::string type );
		virtual ~A_Animal();
		A_Animal(const A_Animal &copy);
		A_Animal& operator=( const A_Animal &assign);
		virtual void makeSound( void ) const;
		virtual void printIdeas( void ) const = 0;
		virtual std::string getType( void ) const;
	protected:
		std::string	type;
};

#endif //ANIMAL_HPP
