#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &copy);
		//basic operator overloads
		Cure& operator=(const Cure &assign);
		//other member functions
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif // !CURE_HPP
