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
	debug("Bureaucrat constructed with name: " << name << " and grade " << grade);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	debug("Bureaucrat Destructor called");
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

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

