#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm( void ):
	AForm("RobotomyRequestForm", 72, 45),
	_name("RobotomyRequestForm"),
	_gradeToSign(72),
	_gradeToExecute(45),
	_target("Bureaucrat"),
	_boolGen(std::time(NULL) ^ reinterpret_cast<unsigned long>(this))
{
	debug("RobotomyRequestForm default Constructor called");
}

RobotomyRequestForm::RobotomyRequestForm( std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	_name("RobotomyRequestForm"),
	_gradeToSign(72),
	_gradeToExecute(45),
	_target(target),
	_boolGen(std::time(NULL) ^ reinterpret_cast<unsigned long>(this))
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
	_target(copy.getTarget()),
	_boolGen(copy.getBoolGen())
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

RobotomyRequestForm::BoolGenerator RobotomyRequestForm::getBoolGen( void ) const
{
	return (this->_boolGen);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw(AForm::NotSignedException());
	if (this->getGradeToExecute() < executor.getGrade())
		throw(AForm::GradeTooLowException());
	debug("📑🤖 RobotomyRequestForm execution in progress");
	if (_boolGen.next())
		std::cout << BLUE << this->getTarget() << " has been robotomized sucessfully!" << std::endl
			<< "🤖 BEEP BOOP 🤖" << RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed..." << RESET << std::endl;
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
