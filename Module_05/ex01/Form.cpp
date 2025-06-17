#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"
#include <string>
#include <iostream>

// Default Constructor
Form::Form( void ):
	_name("testForm"),
	_gradeToSign(150),
	_gradeToExecute(150),
	_signed(false)
{
	debug(Form Default Constructor called);
}

// Parameterized Constructor
Form::Form( std::string name, size_t gradeToSign, size_t gradeToExecute ):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	debug(Form Parameterized Constructor called);
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

// Destructor
Form::~Form()
{
	debug(Form Destructor called);
}

// Copy Constructor
Form::Form(const Form &copy):
	_name(copy.getName()),
	_gradeToSign(copy.getGradeToSign()),
	_gradeToExecute(copy.getGradeToExecute()),
	_signed(copy.getSigned())
{
	checkGrade(copy.getGradeToSign());
	checkGrade(copy.getGradeToExecute());
}

Form& Form::operator=( const Form &assign )
{
	static_cast<void>(assign);
	return *this;
}

// takes a bureaucrat and sets the form signed true,
// if the bureaucrats grade greater or equal to enough
// throws Form::GradeTooLowException if grade not enough
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->setSigned(true);
		std::cout << this->getName() << " has been signed by " << bureaucrat.getName() << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

//--------------------setters and getters--------------------

std::string Form::getName( void ) const
{
	return this->_name;
}

size_t Form::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}

size_t Form::getGradeToExecute( void ) const
{
	return this->_gradeToExecute;
}

bool Form::getSigned( void ) const
{
	return this->_signed;
}

void Form::setSigned( const bool signedness)
{
	this->_signed = signedness;
}

void Form::checkGrade( const int grade ) const
{
	if (grade < 1) throw Form::GradeTooHighException();
	if (grade > 150) throw Form::GradeTooLowException();
}

//--------------------Exceptions--------------------

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

// Stream operator overloads

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "📑" << form.getName()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute()
		<< ", is signed: " << form.getSigned() << std::endl;
	return (os);
}
