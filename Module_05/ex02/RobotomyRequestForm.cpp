#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm( void ):
	AForm("RobotomyRequestForm", 72, 45),
	_name("RobotomyRequestForm"),
	_gradeToSign(72),
	_gradeToExecute(45),
	_target("home")
{
	debug("RobotomyRequestForm default Constructor called");
}

RobotomyRequestForm::RobotomyRequestForm( std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	_name("RobotomyRequestForm"),
	_gradeToSign(72),
	_gradeToExecute(45),
	_target(target)
{
	debug("RobotomyRequestForm named Constructor called");
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	debug("RobotomyRequestForm Destructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	AForm(copy),
	_name(copy.getName()),
	_gradeToSign(copy.getGradeToSign()),
	_gradeToExecute(copy.getGradeToExecute()),
	_signed(copy.getSigned()),
	_target(copy.getTarget())
{}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &assign )
{
	static_cast<void>(assign);
	return (*this);
}

std::string RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw(AForm::NotSignedException());
	if (this->getGradeToExecute() < executor.getGrade())
		throw(AForm::GradeTooLowException());
	debug("📑🤖 RobotomyRequestForm execution in progress");
	if (BoolGenerator(std::time(NULL)).next())
		std::cout << BLUE << this->getTarget() << " has been robotomized sucessfully!" << std::endl
			<< "🤖 BEEP BOOP 🤖" << RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed..." << std::endl;

}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
	os << "📑🤖" << form.getName()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute()
		<< ", is signed: " << form.getSigned()
		<< ", has target: " << form.getTarget() << std::endl;
	return (os);
}
