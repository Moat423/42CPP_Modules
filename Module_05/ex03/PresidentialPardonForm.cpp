#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm( void ):
	AForm("PresidentialPardonForm", 25, 5),
	_name("PresidentialPardonForm"),
	_gradeToSign(25),
	_gradeToExecute(5),
	_target("Kitty")
{
	debug("PresidentialPardonForm default Constructor called");
}

PresidentialPardonForm::PresidentialPardonForm( std::string target):
	AForm("PresidentialPardonForm", 25, 5),
	_name("PresidentialPardonForm"),
	_gradeToSign(25),
	_gradeToExecute(5),
	_target(target)
{
	debug("PresidentialPardonForm named Constructor called");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	debug("PresidentialPardonForm Destructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
	AForm(copy),
	_name(copy.getName()),
	_gradeToSign(copy.getGradeToSign()),
	_gradeToExecute(copy.getGradeToExecute()),
	_signed(copy.getSigned()),
	_target(copy.getTarget())
{}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &assign )
{
	static_cast<void>(assign);
	return (*this);
}

std::string PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw(AForm::NotSignedException());
	if (this->getGradeToExecute() < executor.getGrade())
		throw(AForm::GradeTooLowException());
	debug("📑👑 PresidentialPardonForm executed");
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
	os << "📑👑" << form.getName()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute()
		<< ", is signed: " << form.getSigned()
		<< ", has target: " << form.getTarget() << std::endl;
	return (os);
}

