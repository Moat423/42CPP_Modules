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
	testing_creation("testing Bureaucrat creation");
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
	Bureaucrat joe;
	std::cout << joe << std::endl;
	} catch (std::exception &e) {
		std::cout << "Bureaucrat (default) creation failed" << std::endl;
	}
	try {
	Bureaucrat paul("Paul", 2);
	std::cout << paul << std::endl;
	} catch (std::exception &e) {
		std::cout << "Bureaucrat (grade 2) creation failed" << std::endl;
	}
	try {
	Bureaucrat tim("Tim", 150);
	std::cout << tim << std::endl;
	} catch (std::exception &e) {
		std::cout << "Bureaucrat (grade 150) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
}

static void	testing_copying(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat tim("Tim", 150);
	std::cout << tim << std::endl;
	Bureaucrat tom(tim);
	std::cout << "copying tim to tom" << std::endl;
	std::cout << tom << std::endl;
	std::cout << "No exception occured." << std::endl;
	}
	catch ( std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

static void	testing_assignment(std::string text)
{
	try {
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	Bureaucrat tim("Tim", 150);
	Bureaucrat toby("Toby", 30);
	tim = toby;
	std::cout << "expected output:" << std::endl;
	std::cout << toby << std::endl;
	std::cout << "output:" << std::endl;
	std::cout << tim << std::endl;
	std::cout << "No exception occured." << std::endl;
	} catch (std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}
}

static void	testing_invalid_grades(std::string text)
{
	std::cout << std::endl << "====================" << text << "====================" << std::endl;
	try {
	Bureaucrat stean("Stean", 151);
	std::cout << stean << std::endl;
	} catch (std::exception &e) {
		std::cout << "Bureaucrat (grade 151) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Bureaucrat stean("Stean", 0);
	std::cout << stean << std::endl;
	} catch (std::exception &e) {
		std::cout << "Bureaucrat (grade 0) creation failed. Reason:" << std::endl << e.what() << std::endl;
	}
	try {
	Bureaucrat stean("Stean", -1);
	std::cout << stean << std::endl;
	} catch (std::exception &e) {
		std::cout << "Bureaucrat (grade 18446744073709551615) creation failed. Reason:" << std::endl << e.what() << std::endl;
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

