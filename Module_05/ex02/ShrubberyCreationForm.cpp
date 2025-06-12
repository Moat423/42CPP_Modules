#include "ShrubberyCreationForm.hpp"
#include "Debug.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ):
	AForm("ShrubberyCreationForm", 145, 137)
{
	debug("ShrubberyCreationForm Constructor called");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	debug("ShrubberyCreationForm Destructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
AForm(copy) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &assign )
{
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

}
