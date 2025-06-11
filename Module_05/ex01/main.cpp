#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <regex>
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
	testing_invalid_grades("testing creating forms with invalid grades");
	testing_copying("testing copying");
	testing_assignment("assignment copying");
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
	Form timsForm("TimsForm", 0, 100);
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetosign 0) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Form timsForm("TimsForm", 1, 151);
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoexecute 151) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Form timsForm("TimsForm", 1, 0);
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoexecute 0) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
}

// using different forms of copy construction
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
	Form timsForm = (Form("tempForm", 140, 160));
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoexecute 160) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Form timsForm(Form("tempForm", 160, 140));
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoSign 160) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Form timsForm = (Form("tempForm", 0, 140));
	std::cout << timsForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "form (gradetoSign 0) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Form timsForm(Form("tempForm", 140, 0));
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

static void	testing_signing(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat stean("Stean", 150);
	std::cout << stean << std::endl;
	Bureaucrat king("King", 1);
	std::cout << king << std::endl;
	Form lowGradeForm("lowGradeForm", 150, 100);
	std::cout << lowGradeForm << std::endl;
	lowGradeForm.beSigned(stean);
	std::cout << lowGradeForm << std::endl;
	lowGradeForm.beSigned(king);
	std::cout << lowGradeForm << std::endl;
	Form highGradeForm("highGradeForm", 2, 1);
	std::cout << highGradeForm << std::endl;
	highGradeForm.beSigned(king);
	std::cout << highGradeForm << std::endl;
	std::cout << GREEN << "next one should throw an error" << RESET << std::endl;
	highGradeForm.beSigned(stean);
	std::cout << highGradeForm << std::endl;
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}
	try {
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}
}
