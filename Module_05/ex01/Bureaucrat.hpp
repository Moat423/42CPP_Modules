#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <cstddef>
#include <exception>
#include <ostream>
#include <string>

class Bureaucrat {
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, size_t grade );
		virtual ~Bureaucrat() throw();

		Bureaucrat(const Bureaucrat &copy);

		//operator overloads
		Bureaucrat& operator=( const Bureaucrat &assign );

		Bureaucrat	&operator++( void ); // precrement Grade
		Bureaucrat	operator++( int ); //postcrement
		Bureaucrat	&operator--( void ); // precrement Grade
		Bureaucrat	operator--( int ); //postcrement

		//getters
		size_t 		getGrade() const;
		std::string	getName() const;

		//member functions
		void		incrementGrade( void );
		void		decrementGrade( void );

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		size_t				_grade;

		//setters
		void		setGrade( const size_t grade );

		void		checkGrade( const size_t grade ) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif // !BUREAUCRAT_HPP
