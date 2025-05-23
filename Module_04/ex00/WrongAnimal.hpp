#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal& operator=( const WrongAnimal &assign);
		void makeSound( void ) const;
		std::string getType( void ) const;
	protected:
		std::string	type;
};

#endif //WRONGANIMAL_HPP
