#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const & type);
		~AMateria();
		AMateria(const AMateria &copy);
		//basic operator overloads
		AMateria& operator=(const AMateria &assign);
		//getters and setters
		std::string const & getType() const;
		//other member functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // !AMATERIA_HPP
