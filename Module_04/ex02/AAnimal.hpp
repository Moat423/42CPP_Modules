#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class AAnimal
{
	public:
		AAnimal( void );
		AAnimal( std::string type );
		virtual ~AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal& operator=( const AAnimal &assign);
		virtual void makeSound( void ) const;
		virtual void printIdeas( void ) const = 0;
		virtual std::string getType( void ) const;
	protected:
		std::string	type;
};

#endif //ANIMAL_HPP
