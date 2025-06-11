#include "Form.hpp"
#include "Debug.hpp"
#include <string>

// Default Constructor
Form::Form( void ):
	_name("Zaphod Beeblebrox"),
	_gradeToSign(1),
	_gradeToExecute(1)
{
	debug(Form Default Constructor called);
}

// Parameterized Constructor
Form::Form( std::string name, size_t gradeToSign, size_t gradeToExecute ):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
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
	_gradeToExecute(copy.getGradeToExecute())
{
	checkGrade(copy.getGradeToSign());
	checkGrade(copy.getGradeToExecute());
}

// TODO: cant assign grades
// Copy Assignment Operator
Form& Form::operator=( const Form &assign )
{
	if (this != &assign)
	{
		this->setName(assign.getName());
		// this->_gradeToSign = (assign.getGradeToSign());
	}
	return *this;
}

//--------------------setters and getters--------------------

// Getter
std::string Form::getName( void ) const
{
	return this->_name;
}

// Setter
void Form::setName( std::string name )
{
	this->_name = name;
}

// Getter
size_t Form::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}

// Getter
size_t Form::getGradeToExecute( void ) const
{
	return this->_gradeToExecute;
}


void Form::checkGrade( const int grade ) const
{
	if (grade < 1) throw Form::GradeTooHighException();
	if (grade > 150) throw Form::GradeTooLowException();
}

//--------------------Exceptions--------------------

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
