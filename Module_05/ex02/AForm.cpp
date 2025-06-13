#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"
#include <string>
#include <iostream>

// Default Constructor
AForm::AForm( void ):
	_name("testAForm"),
	_gradeToSign(150),
	_gradeToExecute(150),
	_signed(false)
{
	debug(AForm Default Constructor called);
}

// Parameterized Constructor
AForm::AForm( std::string name, size_t gradeToSign, size_t gradeToExecute ):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	debug(AForm Parameterized Constructor called);
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

// Destructor
AForm::~AForm()
{
	debug(AForm Destructor called);
}

// Copy Constructor
AForm::AForm(const AForm &copy):
	_name(copy.getName()),
	_gradeToSign(copy.getGradeToSign()),
	_gradeToExecute(copy.getGradeToExecute()),
	_signed(copy.getSigned())
{
	checkGrade(copy.getGradeToSign());
	checkGrade(copy.getGradeToExecute());
}

AForm& AForm::operator=( const AForm &assign )
{
	static_cast<void>(assign);
	return *this;
}

// takes a bureaucrat and sets the form signed true,
// if the bureaucrats grade greater or equal to enough
// throws AForm::GradeTooLowException if grade not enough
void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->setSigned(true);
		std::cout << this->getName() << " has been signed by " << bureaucrat.getName() << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}

//--------------------setters and getters--------------------

std::string AForm::getName( void ) const
{
	return this->_name;
}

size_t AForm::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}

size_t AForm::getGradeToExecute( void ) const
{
	return this->_gradeToExecute;
}

bool AForm::getSigned( void ) const
{
	return this->_signed;
}

void AForm::setSigned( const bool signedness)
{
	this->_signed = signedness;
}

void AForm::checkGrade( const int grade ) const
{
	if (grade < 1) throw AForm::GradeTooHighException();
	if (grade > 150) throw AForm::GradeTooLowException();
}

//--------------------Exceptions--------------------

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("not signed");
}

// Stream operator overloads

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "📑" << form.getName()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute()
		<< ", is signed: " << form.getSigned() << std::endl;
	return (os);
}
