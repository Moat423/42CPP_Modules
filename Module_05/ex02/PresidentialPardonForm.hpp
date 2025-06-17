#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
#include <string>

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm& operator=( const PresidentialPardonForm &assign );

		std::string getTarget( void ) const;

		void		execute(Bureaucrat const &executor) const;
	private:
		const std::string	_name;
		const size_t		_gradeToSign;
		const size_t		_gradeToExecute;
		bool				_signed;
		const std::string	_target;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif // !PRESIDENTIALPARDONFORM_HPP
