#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	public:
		Intern( void );
		virtual ~Intern();

		Intern(const Intern& copy);
		Intern& operator=( const Intern& assign );

		AForm* makeForm( std::string formname, std::string target );

		class NonExistentFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


#endif // !INTERN_HPP

