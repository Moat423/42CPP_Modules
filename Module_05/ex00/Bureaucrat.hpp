#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <cstddef>
#include <exception>
#include <string>

class Bureaucrat {
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, size_t grade );
		virtual ~Bureaucrat();

		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=( const Bureaucrat &assign );

		//getters
		const size_t	getGrade() const;
		const std::string getName() const;

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
		std::string	_name;
		size_t		_grade;

		//setters
		void	setName( const std::string name );
		void	setGrade( const size_t grade );
};

#endif // !BUREAUCRAT_HPP
