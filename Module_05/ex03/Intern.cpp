#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Debug.hpp"
#include <iostream>
#include <string>

Intern::Intern( void )
{
	debug("Intern hired");
}

Intern::~Intern()
{
	debug("Internship ended");
}

Intern::Intern(const Intern &copy)
{
	debug("Intern cloned");
}

Intern& Intern::operator=( const Intern &assign )
{
	static_cast<void>(assign);
	return *this;
}

static AForm *makePresidentialPardonForm( std::string target )
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomyRequestForm( std::string target )
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubberyCreationForm( std::string target )
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm( std::string formname, std::string target )
{
	AForm *form;
	std::string formnames[3] = {
		"RobotomyRequestForm",
		"ShrubberyCreationForm",
		"PresidentialPardonForm"
	};
	typedef AForm* (*formMaker)( const std::string target );
	formMaker formMakers[3] = {
		makeRobotomyRequestForm,
		makeShrubberyCreationForm,
		makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formname == formnames[i])
		{
			std::cout << "Intern creates " << formname << std::endl;
			return (formMakers[i](target));
		}
	}
	std::cout << RED << "Intern could not create the form: " << formname << RESET << std::endl;
	return (NULL);
}
