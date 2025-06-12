#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
#include <string>

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm &assign );

		std::string getTarget( void ) const;

		void		execute(Bureaucrat const &executor) const;
	private:
		const std::string	_name;
		const size_t		_gradeToSign;
		const size_t		_gradeToExecute;
		bool				_signed;
		const std::string	_target;
};


#endif // !SHRUBBERYCREATIONFORM_HPP

