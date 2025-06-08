#include "Bureaucrat.hpp"
#include "Debug.hpp"

// Default Constructor
Bureaucrat::Bureaucrat( void )
{
	debug("Bureaucrat Constructor called");
}

// Parameterized Constructor
Bureaucrat::Bureaucrat( std::string name, size_t grade ): _name(name), _grade(grade)
{
	debug("Bureaucrat constroctor called with name: " << name << " and grade " << grade);
	if (grade < 1)
		throw(GradeTooHighException);
	else if (grade > 150)
		throw(GradeTooLowException);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	debug("Bureaucrat Destructor called");
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy): _grade(copy.getGrade()), _name(copy.getName()) {}

// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=( const Bureaucrat &assign )
{
	if (this != &assign)
	{
		this->setGrade(assign.getGrade());
		this->setName(assign.getName());
	}
	return *this;
}

// Getter
const std::string Bureaucrat::getName( void ) const
{
	return this->_name;
}

// Setter
void Bureaucrat::setName( const std::string name )
{
	this->_name = name;
}

// Getter
const size_t Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

// Setter
void Bureaucrat::setGrade( const size_t grade )
{
	this->_grade = grade;
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << " , bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (os);
}
