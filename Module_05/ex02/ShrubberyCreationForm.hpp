#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm( void );
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm &assign );

		void		execute(Bureaucrat const &executor) const;
	private:
};


#endif // !SHRUBBERYCREATIONFORM_HPP

