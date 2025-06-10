#ifndef FORM_HPP
# define FORM_HPP
# include <string>

class Form {
	public:
		Form( void );
		Form( std::string name, size_t gradeToSign, size_t gradeToExecute );
		virtual ~Form();

		Form(const Form &copy);
		Form& operator=( const Form &assign );

		// Getters and setters
		std::string		getName( void ) const;
		void			setName( std::string name );
		size_t			getGradeToSign( void ) const;
		size_t			getGradeToExecute( void ) const;

		void checkGrade( const int grade ) const;
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
		std::string		_name;
		bool			_signed;
		const size_t	_gradeToSign;
		const size_t	_gradeToExecute;
};


#endif // !FORM_HPP

