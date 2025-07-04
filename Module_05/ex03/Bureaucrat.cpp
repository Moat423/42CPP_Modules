#include "Bureaucrat.hpp"
#include "Debug.hpp"
#include <iostream>

// Default Constructor
Bureaucrat::Bureaucrat( void ): _name("Biggus Diccus"), _grade(1)
{
	debug("👔Bureaucrat Constructor called");
}

// Parameterized Constructor
Bureaucrat::Bureaucrat( std::string name, size_t grade ): _name(name), _grade(grade)
{
	debug("👔Bureaucrat constructor called with name: " << name << " and grade " << grade);
	checkGrade(grade);
}

// Destructor
Bureaucrat::~Bureaucrat() throw()
{
	debug("👔Bureaucrat Destructor called");
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy):  _name(copy.getName()), _grade(copy.getGrade())
{}

// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=( const Bureaucrat &assign )
{
	if (this != &assign)
		this->setGrade(assign.getGrade());
	return *this;
}

// --------------------Member functions--------------------

void Bureaucrat::checkGrade( const size_t grade ) const
{
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::incrementGrade( void )
{
	int	grade;

	grade = this->getGrade();
	checkGrade(--grade);
	setGrade(grade);
}

void Bureaucrat::decrementGrade( void )
{
	int	grade;

	grade = this->getGrade();
	checkGrade(++grade);
	setGrade(grade);
}

void Bureaucrat::signForm( AForm &form) const
{
	try {
	form.beSigned(*this);
	std::cout << "👔✍ " << this->getName()
		<< " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e){
	std::cout << this->getName()
		<< " couldn’t sign " << form.getName()
		<< " because their " << e.what()
		<< "." << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const & form ) const
{
	try {
	form.execute(*this);
	std::cout << "👔" << this->getName()
		<< " executed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
	std::cout << "👔" << this->getName()
		<< " couldn’t execute " << form.getName()
		<< " because their " << e.what()
		<< "." << std::endl;
	} catch (AForm::NotSignedException &e) {
	std::cout << "👔" << this->getName()
		<< " couldn’t execute " << form.getName()
		<< " because their " << e.what()
		<< "." << std::endl;
	}
}

//---------------------------------------pre- and postcrement---------------------------------------

Bureaucrat &Bureaucrat::operator++( void )
{
	incrementGrade();
	return (*this);
}

Bureaucrat Bureaucrat::operator++( int )
{
	Bureaucrat ans;
	incrementGrade();
	return (ans);
}

Bureaucrat &Bureaucrat::operator--( void )
{
	decrementGrade();
	return (*this);
}

Bureaucrat Bureaucrat::operator--( int )
{
	Bureaucrat ans;
	decrementGrade();
	return (ans);
}

//----------------name----------

// Getter
std::string Bureaucrat::getName( void ) const
{
	return this->_name;
}

//----------grade----------

// Getter
size_t Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

// Setter
void Bureaucrat::setGrade( const size_t grade )
{
	this->_grade = grade;
}

//--------------------Stream operations--------------------

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (os);
}

//--------------------Exceptions--------------------

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
