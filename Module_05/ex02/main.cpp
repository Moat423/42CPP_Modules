#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>
#include "Debug.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void	testingCreation(std::string text);
static void	testingCopying(std::string text);
static void testingAllForms(std::string text);
// static void	testingAssignment(std::string text);
// static void testingBureaucratSignForm(std::string text);
// static void	testingSigning(std::string text);
static void testingPresidentialPardonForm(std::string text);
static void testingShrubberyFormValues(std::string text);

int main( void )
{
	std::cout << BLUE << "====================Bureaucracy Testing====================" << RESET << std::endl;
	testingCreation("testing Form creation");
	testingCopying("testing copying");
	testingAllForms("TESTING ALL of the FORMS");
	// testingAssignment("assignment copying");
	// testingSigning("test the beSigned function of Form");
	// testingBureaucratSignForm("test the Bureaucreats signForm function");
	testingShrubberyFormValues("testing shrubberyForm Values");
	testingPresidentialPardonForm("testing PresidentialPardonForm");
}

static void	testingCreation(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	ShrubberyCreationForm A24;
	std::cout << A24 << std::endl;
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

// static void	testingAssignment(std::string text)
// {
// 	try {
// 	std::cout << std::endl << "====================" << text << "====================" << std::endl;
// 	Form timsForm("TimsForm", 150, 100);
// 	std::cout << timsForm << std::endl;
// 	Bureaucrat tim("Tim", 150);
// 	timsForm.beSigned(tim);
// 	Form paulsForm("PaulsForm", 2, 1);
// 	std::cout << paulsForm << std::endl;
// 	paulsForm = timsForm;
// 	std::cout << "copying non constant members from(meaning only signedness):" << std::endl;
// 	std::cout << timsForm << std::endl;
// 	std::cout << "output:" << std::endl;
// 	std::cout << paulsForm << std::endl;
// 	std::cout << "No exception occured." << std::endl;
// 	} catch (std::exception &e) {
// 		std::cout << std::endl << e.what() << std::endl;
// 	}
// }
//
// static void	testingSigning(std::string text)
// {
// 	std::cout << std::endl << "====================" << text << "====================" << std::endl;
// 	try {
// 	Bureaucrat stean("Stean", 150);
// 	std::cout << stean << std::endl;
// 	Bureaucrat king("King", 1);
// 	std::cout << king << std::endl;
// 	Form lowGradeForm("lowGradeForm", 150, 100);
// 	std::cout << lowGradeForm << std::endl;
// 	lowGradeForm.beSigned(stean);
// 	std::cout << lowGradeForm << std::endl;
// 	lowGradeForm.beSigned(king);
// 	std::cout << lowGradeForm << std::endl;
// 	Form highGradeForm("highGradeForm", 2, 1);
// 	std::cout << highGradeForm << std::endl;
// 	highGradeForm.beSigned(king);
// 	std::cout << highGradeForm << std::endl;
// 	std::cout << GREEN << "next one should throw an error" << RESET << std::endl;
// 	highGradeForm.beSigned(stean);
// 	std::cout << highGradeForm << std::endl;
// 	} catch (std::exception &e) {
// 		std::cout << std::endl << e.what() << std::endl;
// 	}
// 	try {
// 	} catch (std::exception &e) {
// 		std::cout << std::endl << e.what() << std::endl;
// 	}
// }
//
// static void testingBureaucratSignForm(std::string text)
// {
// 	std::cout << std::endl << "====================" << text << "====================" << std::endl;
// 	try {
// 	Bureaucrat stean("Stean", 150);
// 	std::cout << stean << std::endl;
// 	Bureaucrat king("King", 1);
// 	std::cout << king << std::endl;
// 	Form lowGradeForm("lowGradeForm", 150, 100);
// 	std::cout << lowGradeForm << std::endl;
// 	stean.signForm(lowGradeForm);
// 	std::cout << lowGradeForm << std::endl;
// 	king.signForm(lowGradeForm);
// 	std::cout << lowGradeForm << std::endl;
// 	Form highGradeForm("highGradeForm", 2, 1);
// 	std::cout << highGradeForm << std::endl;
// 	king.signForm(highGradeForm);
// 	std::cout << highGradeForm << std::endl;
// 	std::cout << GREEN << "next one should throw an error" << RESET << std::endl;
// 	stean.signForm(highGradeForm);
// 	std::cout << highGradeForm << std::endl;
// 	std::cout << GREEN <<
// 		"since normal execution has resumed and the error was caught in signForm, this line will be printed, if no abnormal error occured"
// 		<< RESET << std::endl;
// 	} catch (std::exception &e) {
// 		std::cout << std::endl << e.what() << std::endl;
// 	}
// 	try {
// 	} catch (std::exception &e) {
// 		std::cout << std::endl << e.what() << std::endl;
// 	}
// }

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

static void testingAllForms(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
		AForm *forms[6];
		forms[0] = new ShrubberyCreationForm();
		forms[1] = new ShrubberyCreationForm("firstHouse");
		forms[2] = new PresidentialPardonForm();
		forms[3] = new PresidentialPardonForm("Fiffi");
		forms[4] = new RobotomyRequestForm();
		forms[5] = new RobotomyRequestForm("Sullivan");
		Bureaucrat *workers[8];
		workers[0] = new Bureaucrat("Steve", 150);
		workers[0] = new Bureaucrat("Magda", 72);
		workers[0] = new Bureaucrat("PlowSign", 26);
		workers[0] = new Bureaucrat("PexactSign", 25);
		workers[0] = new Bureaucrat("PlowExec", 6);
		workers[0] = new Bureaucrat("PexactExec", 5);
		workers[0] = new Bureaucrat("King", 1);
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 8; j++) {
				forms[i]->beSigned(*workers[j]);
			}
			for (int j = 0; j < 8; j++) {
				workers[j]->executeForm(*forms[i]);
			}
		}
		for (int i = 0; i < 6; i++) {
			delete forms[i];
		}
		for (int i = 0; i < 8; i++) {
			delete workers[i];
		}
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}

}
