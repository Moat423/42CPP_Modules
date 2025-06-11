#ifndef AFORM_HPP
# define AFORM_HPP
# include <ostream>
# include <string>

class Bureaucrat;

class AForm {
	public:
		AForm( void );
		AForm( std::string name, size_t gradeToSign, size_t gradeToExecute );
		virtual ~AForm();

		AForm(const AForm &copy);
		AForm& operator=( const AForm &assign );

		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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
		const size_t		_gradeToSign;
		const size_t		_gradeToExecute;
		bool				_signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif // !AFORM_HPP

