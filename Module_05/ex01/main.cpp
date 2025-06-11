#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include "Debug.hpp"

static void	testing_creation(std::string text);
static void	testing_copying(std::string text);
static void	testing_assignment(std::string text);
static void	testing_invalid_grades(std::string text);
static void	testingDemotionOp(std::string text);
static void	testingDemotion(std::string text);
static void	testingPromotion(std::string text);
static void	testingPromotionOp(std::string text);

int main( void )
{
	std::cout << BLUE << "====================Bureaucracy Testing====================" << RESET << std::endl;
	testing_creation("testing Form creation");
	testing_copying("testing copying");
	testing_assignment("assignment copying");
	testing_invalid_grades("testing invalid grades");
	testingPromotion("testing Promotion");
	testingDemotion("testing Demotion");
	testingPromotionOp("testing Promotion Operations");
	testingDemotionOp("testing Demotion Operations");
}

static void	testing_creation(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Form joe;
	std::cout << joe << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
	Form paulsForm("PaulsForm", 2, 1);
	std::cout << paulsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
	Form timsForm("TimsForm", 150, 100);
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

static void	testing_copying(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Form timsForm("TimsForm", 150, 100);
	std::cout << timsForm << std::endl;
	std::cout << "copy constructing timsForms form to paulsForms form" << std::endl;
	Form paulsForm(timsForm);
	std::cout << paulsForm << std::endl;
	std::cout << "No exception occured." << std::endl;
	}
	catch ( std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
	Form timsForm(Form{"tempForm", 140, 160});
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoexecute 160) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Form timsForm(Form{"tempForm", 160, 140});
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoSign 160) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Form timsForm(Form{"tempForm", 0, 140});
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoSign 0) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Form timsForm(Form{"tempForm", 140, 0});
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoExecute 0) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
}

static void	testing_assignment(std::string text)
{
	try {
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	Form timsForm("TimsForm", 150, 100);
	std::cout << timsForm << std::endl;
	Bureaucrat tim("Tim", 150);
	timsForm.beSigned(tim);
	Form paulsForm("PaulsForm", 2, 1);
	std::cout << paulsForm << std::endl;
	paulsForm = timsForm;
	std::cout << "copying non constant members from(meaning only signedness):" << std::endl;
	std::cout << timsForm << std::endl;
	std::cout << "output:" << std::endl;
	std::cout << paulsForm << std::endl;
	std::cout << "No exception occured." << std::endl;
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}
}

static void	testing_invalid_grades(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Form timsForm("TimsForm", -1, 100);
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetosign 18446744073709551615) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Form timsForm("TimsForm", 1, 151);
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoexecute 151) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
}

static void	testing_signing(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Form lowGradeForm("lowGradeForm", 150, 100);
	std::cout << lowGradeForm << std::endl;
	Bureaucrat stean("Stean", 150);
	std::cout << stean << std::endl;
	lowGradeForm.beSigned(stean);
	std::cout << lowGradeForm << std::endl;
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}
	try {
	Bureaucrat stean("King", 1);
	std::cout << stean << std::endl;
	Form highGradeForm("highGradeForm", 2, 1);
	std::cout << highGradeForm << std::endl;
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}
}

static void	testingPromotion(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat stean("Stean", 3);
	std::cout << "original stean: " << stean << std::endl;
	for (int i = 0; i <= 3; i++) {
		stean.incrementGrade();
		std::cout << stean;
	}
	std::cout << "No exception occured." << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "increment failed: " << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "decrement failed: " << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cout << "other error: " << e.what() << std::endl;
	}
}

static void	testingDemotion(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat stean("Stean", 148);
	std::cout << "original stean: " << stean << std::endl;
	for (int i = 0; i <= 3; i++) {
		stean.decrementGrade();
		std::cout << stean;
	}

	std::cout << "this won't get printed if an error occured" << std::endl;

	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "increment failed: " << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "decrement failed: " << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cout << "other error: " << e.what() << std::endl;
	}
}

static void	testingPromotionOp(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat stean("Stean", 3);
	Bureaucrat danie("danie", 3);
	std::cout << "original stean: " << stean << std::endl;
	std::cout << "original danie: " << danie << std::endl;
	for (int i = 0; i <= 3; i++) {
		stean++;
		std::cout << stean;
		++danie;
		std::cout << danie;
	}

	std::cout << "this won't get printed if an error occured" << std::endl;

	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "increment failed: " << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "decrement failed: " << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cout << "other error: " << e.what() << std::endl;
	}
}

static void	testingDemotionOp(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat stean("Stean", 148);
	Bureaucrat danie("Danie", 148);
	std::cout << "original stean: " << stean << std::endl;
	std::cout << "original danie: " << danie << std::endl;
	for (int i = 0; i <= 3; i++) {
		stean--;
		std::cout << stean;
		--danie;
		std::cout << danie;
	}

	std::cout << "this won't get printed if an error occured" << std::endl;

	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "increment failed: " << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "decrement failed: " << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cout << "other error: " << e.what() << std::endl;
	}
}

