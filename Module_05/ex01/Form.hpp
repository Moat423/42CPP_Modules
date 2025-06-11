#ifndef FORM_HPP
# define FORM_HPP
# include <ostream>
# include <string>

class Bureaucrat;

class Form {
	public:
		Form( void );
		Form( std::string name, size_t gradeToSign, size_t gradeToExecute );
		virtual ~Form();

		Form(const Form &copy);
		Form& operator=( const Form &assign );

		void				beSigned(const Bureaucrat &bureaucrat);

		// Getters and setters
		std::string			getName( void ) const;
		size_t				getGradeToSign( void ) const;
		size_t				getGradeToExecute( void ) const;
		bool				getSigned( void ) const;
		void				setSigned( const bool signedness);

		void				checkGrade( const int grade ) const;
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
		bool				_signed;
		const size_t		_gradeToSign;
		const size_t		_gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif // !FORM_HPP

