#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>
#include "Debug.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

static void	testingCreation(std::string text);
static void	testingCopying(std::string text);
static void testingAllForms(std::string text);
static void testingPresidentialPardonForm(std::string text);
static void testingShrubberyFormValues(std::string text);
static void testingRobotomyRequestForm(std::string text);

int main( void )
{
	std::cout << BLUE << "====================Bureaucracy Testing====================" << RESET << std::endl;
	testingCreation("testing Form creation");
	testingCopying("testing copying");
	testingAllForms("TESTING ALL of the FORMS");
	testingShrubberyFormValues("testing shrubberyForm Values");
	testingPresidentialPardonForm("testing PresidentialPardonForm");
	testingRobotomyRequestForm("testing RobotomyRequestForm");
}

static void	testingCreation(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	Intern damien;
	try {
		AForm *form1 = damien.makeForm("ShrubberyCreationForm", "pool");
	std::cout << *form1 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

// using different forms of copy construction
static void	testingCopying(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	ShrubberyCreationForm A24("litterbox");
	std::cout << "A24:\n" << A24 << std::endl;
	std::cout << "new shrubbery form saved in AForm pointer:" << std::endl;
	AForm *timsForm = new ShrubberyCreationForm(A24);
	std::cout << *timsForm << std::endl;
	std::cout << "copy constructing" << std::endl;
	ShrubberyCreationForm A25(A24);
	std::cout << "A25:\n" << A25 << std::endl;
	ShrubberyCreationForm A26;
	std::cout << "setting two shrubfroms equal (they will have different targets, cause const)" << std::endl;
	std::cout << "A26 = A25" << std::endl;
	A26 = A25;
	std::cout << "A26:\n" << A26 << std::endl;
	delete timsForm;
	std::cout << "No exception occured." << std::endl;
	}
	catch ( std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

static void testingShrubberyFormValues(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat tomLow("Tom", 150);
	std::cout << tomLow << std::endl;
	Bureaucrat stean("Stean", 145);
	std::cout << stean << std::endl;
	Bureaucrat king("King", 1);
	std::cout << king << std::endl;
	AForm *shrubberyCreationForm = new ShrubberyCreationForm("Backyard");
	ShrubberyCreationForm treeForm("Mollystreet");
	std::cout << shrubberyCreationForm << std::endl;
	std::cout << "----------signing the form with the Bureaucrat function----------" << std::endl;
	std::cout << GREEN << "expected to fail:" << RESET << std::endl;
	tomLow.signForm(*shrubberyCreationForm);
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	stean.signForm(*shrubberyCreationForm);
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	king.signForm(*shrubberyCreationForm);
	std::cout << *shrubberyCreationForm << std::endl;
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	stean.signForm(treeForm);
	std::cout << treeForm << std::endl;
	std::cout << "----------executing the form with the Bureaucrat function----------" << std::endl;
	king.executeForm(ShrubberyCreationForm("unsigned"));
	king.executeForm(*shrubberyCreationForm);
	stean.executeForm(*shrubberyCreationForm);
	delete shrubberyCreationForm;
	std::cout << GREEN <<
		"since normal execution has resumed and the error was caught in signForm, this line will be printed, if no abnormal error occured"
		<< RESET << std::endl;
	std::cout << "----------executing the form with the form function----------" << std::endl;
	treeForm.execute(king);
	std::cout << GREEN << "next one should throw an error" << RESET << std::endl;
	treeForm.execute(stean);
	std::cout << treeForm << std::endl;
	std::cout << GREEN <<
		"this will not be printed, because of the error before"
		<< RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}
}

static void testingPresidentialPardonForm(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat lowSign("lowSign", 26);
	Bureaucrat exactSign("exactSign", 25);
	Bureaucrat lowExec("lowExec", 6);
	Bureaucrat exactExec("exactExec", 5);
	Bureaucrat king("King", 1);
	std::cout << king << std::endl;
	PresidentialPardonForm form("Cat Felix");
	std::cout << form << std::endl;

	std::cout << "----------signing the form with the Bureaucrat function----------" << std::endl;
	std::cout << GREEN << "expected to fail:" << RESET << std::endl;
	lowSign.signForm(form);
	std::cout << form << std::endl;
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	exactSign.signForm(form);
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	lowExec.signForm(form);
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	exactExec.signForm(form);
	std::cout << form << std::endl;

	std::cout << "----------executing the form with the Bureaucrat function----------" << std::endl;
	king.executeForm(PresidentialPardonForm("unsigned"));
	std::cout << GREEN << "expected to fail:" << RESET << std::endl;
	lowSign.executeForm(form);
	exactSign.executeForm(form);
	lowExec.executeForm(form);
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	exactExec.executeForm(form);
	std::cout << GREEN <<
		"since normal execution has resumed and the error was caught in signForm, this line will be printed, if no abnormal error occured"
		<< RESET << std::endl;
	std::cout << "----------executing the form with the form function----------" << std::endl;
	form.execute(exactExec);
	std::cout << GREEN << "next one should throw an error" << RESET << std::endl;
	form.execute(lowExec);
	std::cout << GREEN <<
		"this will not be printed, because of the error before"
		<< RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}
}

static void testingRobotomyRequestForm(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat lowSign("lowSign", 73);
	Bureaucrat exactSign("exactSign", 72);
	Bureaucrat lowExec("lowExec", 46);
	Bureaucrat exactExec("exactExec", 45);
	Bureaucrat king("King", 1);
	std::cout << king << std::endl;
	RobotomyRequestForm form("Cat Felix");
	std::cout << form << std::endl;

	std::cout << "----------signing the form with the Bureaucrat function----------" << std::endl;
	std::cout << GREEN << "expected to fail:" << RESET << std::endl;
	lowSign.signForm(form);
	std::cout << form << std::endl;
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	exactSign.signForm(form);
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	lowExec.signForm(form);
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	exactExec.signForm(form);
	std::cout << form << std::endl;

	std::cout << "----------executing the form with the Bureaucrat function----------" << std::endl;
	king.executeForm(RobotomyRequestForm("unsigned"));
	std::cout << GREEN << "expected to fail:" << RESET << std::endl;
	lowSign.executeForm(form);
	exactSign.executeForm(form);
	lowExec.executeForm(form);
	std::cout << GREEN << "expected to work:" << RESET << std::endl;
	exactExec.executeForm(form);
	std::cout << GREEN <<
		"since normal execution has resumed and the error was caught in signForm, this line will be printed, if no abnormal error occured"
		<< RESET << std::endl;
	std::cout << "----------executing the form with the form function----------" << std::endl;
	form.execute(exactExec);
	std::cout << GREEN << "next one should throw an error" << RESET << std::endl;
	form.execute(lowExec);
	std::cout << GREEN <<
		"this will not be printed, because of the error before"
		<< RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}
}
static void testingAllForms(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
		AForm *forms[6];
		forms[0] = new ShrubberyCreationForm();
		forms[1] = new ShrubberyCreationForm("firstHouse");
		forms[2] = new RobotomyRequestForm();
		forms[3] = new RobotomyRequestForm("Fiffi");
		forms[4] = new RobotomyRequestForm();
		forms[5] = new RobotomyRequestForm("Sullivan");
		Bureaucrat *workers[7];
		workers[0] = new Bureaucrat("Steve", 150);
		workers[1] = new Bureaucrat("Magda", 72);
		workers[2] = new Bureaucrat("PlowSign", 26);
		workers[3] = new Bureaucrat("PexactSign", 25);
		workers[4] = new Bureaucrat("PlowExec", 6);
		workers[5] = new Bureaucrat("PexactExec", 5);
		workers[6] = new Bureaucrat("King", 1);
		std::cout << std::endl;
		for (int i = 0; i < 6; i++) {
			std::cout << RED << "SIGNING" << RESET << std::endl;
			for (int j = 0; j < 7; j++) {
				workers[j]->signForm(*forms[i]);
			}
			std::cout << RED << "EXECUTING" << RESET << std::endl;
			for (int j = 0; j < 7; j++) {
				workers[j]->executeForm(*forms[i]);
			}
		std::cout << std::endl;
		}
		for (int i = 0; i < 6; i++) {
			delete forms[i];
		}
		for (int i = 0; i < 7; i++) {
			delete workers[i];
		}
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}

}
