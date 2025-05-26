#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice &copy);
		//basic operator overloads
		Ice& operator=(const Ice &assign);
		//other member functions
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif // !ICE_HPP
