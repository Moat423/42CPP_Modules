#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <ios>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm( void ):
	AForm("ShrubberyCreationForm", 145, 137),
	_name("ShrubberyCreationForm"),
	_gradeToSign(145),
	_gradeToExecute(137),
	_target("home")
{
	debug("ShrubberyCreationForm default Constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	_name("ShrubberyCreationForm"),
	_gradeToSign(145),
	_gradeToExecute(137),
	_target(target)
{
	debug("ShrubberyCreationForm named Constructor called");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	debug("ShrubberyCreationForm Destructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	AForm(copy),
	_name(copy.getName()),
	_gradeToSign(copy.getGradeToSign()),
	_gradeToExecute(copy.getGradeToExecute()),
	_signed(copy.getSigned()),
	_target(copy.getTarget())
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &assign )
{
	static_cast<void>(assign);
	return (*this);
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw(AForm::NotSignedException());
	if (this->getGradeToExecute() < executor.getGrade())
		throw(AForm::GradeTooLowException());
	debug("📑🌳 ShrubberyCreationForm executed");
	std::ofstream file;
	file.exceptions(std::ios_base::failbit | std::ios_base::badbit);
	file.open( (this->getTarget() + "_shrubbery").c_str());

	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠋⠓⠤⠾⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⢠⠴⠋⠙⣦⠔⢎⡀⠀⠀⠀⠘⠖⠋⠚⠦⡄⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⢸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⠆⠀⠀⠀⠀⠀⠀⠀                                          ⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⢀⡀⡀⠀⠀⠀⠀" << std::endl;
	file << "⠀⢀⡤⠤⣀⣀⡹⠴⢤⠀⠀⠀⠀⠀⠀⠀⠀⢀⣐⡮⠹⠤⣀⢤⠀⠀⠀⠀⠀                                          ⠀⠀⠀⠀⠀⠀⡠⠇⠀⠈⢙⠉⠐⠅⠀⠀⡦⢄⠀⠀" << std::endl;
	file << "⢠⡞⠉⠀⠀⠀⠉⠓⠊⠉⠀⠀⢀⠀⢀⡔⠉⠉⠉⠉⠒⠁⠀⠀⠈⡑⠀⠀⠀⠀                                          ⠀⠀⠀⠀⢰⠁⠀⠑⠐⠀⠀⠀⠀⠀⠀⠀⠀⠾⢄⠀" << std::endl;
	file << "⢹⡆⠀⠀⠀⠀⠀⠀⠤⣦⡀⢛⡟⢴⣯⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠊⠀⠀⠀⠀⠀⠀⠀⠄⢄⠀⠀⠀⠀⢀⡜⠁" << std::endl;
	file << "⠸⡄⢀⡀⠀⣄⠀⠀⠀⢀⡹⠼⣣⠠⢉⢹⠣⠦⡖⢀⠶⠀⠀⢠⣔⣖⡅⠦⢄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠁⠀⠀⠈⣷⠻⠛⣦⠴⠶⠤⣤⠞⠉⠀⠀⠀⠙⢳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀⠀⠀⠀⠀⡸⠀" << std::endl;
	file << "⠀⠉⠉⠻⢾⣛⢊⠏⠀⡤⠀⡀⣬⠫⠂⡆⢀⢦⠇⡊⠽⡪⠁⠀⠀⠉⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠾⢧⠀⠀⠀⠀⠀⠀⢸⣁⠀⠀⠀⠈⠳⠀⠀⠀⠀⠀⣨⡷⠶⢤⡀⠀⠀⠀⠀⠸⠀⠀⠀⠀⠀⠀⠀⠀⢀⠴⢠⡌⣀⠐⠀⠈⠘⠁⡄" << std::endl;
	file << "⠀⠀⣠⠶⠚⠈⠉⠀⢌⠆⠉⠀⠘⠖⠙⢇⢠⣤⠗⠒⠒⠃⠉⠁⠀⠀⠀⠀⠀⡸⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠚⠛⠓⠾⣄⠀⠀⢀⡴⠚⠛⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀⠀⠄⠀⡀⠀⠀⠀⢠⣾⣃⠀⠁⠀⢙⣶⣀⠀⠀⠘⡧" << std::endl;
	file << "⠀⠀⠸⣤⡄⠀⠀⠀⡀⠀⠀⠀⠀⣀⡠⠊⠂⡇⢀⣀⠀⠀⠀⠀⠀⢰⣖⡒⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⡁⠀⠀⠀⠀⠀⠚⠉⠉⠛⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠾⠧⣄⠀⠀⠀⠀⠀⠀⠀⠀⠔⠀⠘⠛⠀⠀⠀⢸⡾⠏⠀⠯⠀⠏⠀" << std::endl;
	file << "⠀⠀⠀⠀⠑⠧⠤⠶⠷⠀⠀⢈⣫⠁⠘⠀⠔⠉⠁⢟⠀⠀⠀⠀⡤⠤⠴⠁⠀⠀⠀⠀⠀⠀⠀⠀⣠⡴⠛⠉⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣧⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠛⠓⠚⠛⠀⠀⢆⠀⠰⠀⠀⠈⠉⠓⠖⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠤⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠨⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠈⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠚⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡔⠂⠀⡀⠀⣀⠑⠤⢀⡀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀⠘⠄⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠁⠀⠀⠈⠀⠀⠀⠀" << std::endl;
	file << "                              ⢀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠢⠖⠚⣧⠀⠀⠀⠀⠀⠀⠀⠰⣤⣤⣤⡞⠁⠀⠀                    " << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⢀⡀⡀⠀⠀⠀⠀          ⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠰⣦⣀⡀⢀⣠⠏⠀⠀⠀⠐⠶⠤⠴⠚⠁⠠⠿⠧⢤⡀⠀                    " << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⡠⠇⠀⠈⢙⠉⠐⠅⠀⠀⡦⢄⠀⠀          ⠙⣆⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⠚⠻⡄⠉⣽⣄⣀⣠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠆                    " << std::endl;
	file << "⠀⠀⠀⠀⢰⠁⠀⠑⠐⠀⠀⠀⠀⠀⠀⠀⠀⠾⢄⠀          ⠀⢘⡷⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡗⢶⡏⠀⠀⠙⠶⠋⠈⠁⡞⢿⣀⠀⣀⠀⠀⠀⠀⠀⠀⠴⠴⣟⡁                    " << std::endl;
	file << "⠀⠀⠀⠊⠀⠀⠀⠀⠀⠀⠀⠄⢄⠀⠀⠀⠀⢀⡜⠁          ⠀⢺⡀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⣤⣴⢿⣧⡀⢳⡀⠀⠀⠀⠀⠀⢰⠇⠀⣿⣿⣥⣠⣄⡀⠀⢀⠀⠀⠀⣽⡇                    " << std::endl;
	file << "⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀⠀⠀⠀⠀⡸⠀          ⠀⠀⠙⠦⠤⢾⠀⠀⠀⠀⣀⠀⠀⠀⠀⣻⣦⡿⠙⠛⠃⠀⠀⠀⠀⠀⣼⠀⣼⣯⡿⠛⠉⠿⠤⡤⠟⢣⡤⠿⠋⠁                    " << std::endl;
	file << "⠸⠀⠀⠀⠀⠀⠀⠀⠀⢀⠴⢠⡌⣀⠐⠀⠈⠘⠁⡄          ⠀⠀⠀⠀⠀⠘⢦⣀⣀⣀⡼⠓⠒⠒⠚⠁⠈⠳⡄⠀⠀⠀⠀⠀⠀⢀⣿⣾⣿⠻⣄⣀⢀⡼⠦⣄⣀⣰⠇⠀⠀⠀                    " << std::endl;
	file << "⠀⠄⠀⡀⠀⠀⠀⢠⣾⣃⠀⠁⠀⢙⣶⣀⠀⠀⠘⡧          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⢸⣿⣰⠃⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀                    " << std::endl;
	file << "⠀⠀⠀⠀⠀⠔⠀⠘⠛⠀⠀⠀⢸⡾⠏⠀⠯⠀⠏⠀          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠈⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                    " << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                    " << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠨⠀⠀⠀⠀⠀⠀⠀          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢳⠀⠀⠀⠀⠀⠀⢹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                    " << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⢠⡔⠂⠀⡀⠀⣀⠑⠤⢀⡀⠀⠀⠀          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠈⠀⠀⠀⠀⠀⠀⠈⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                    " << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠁⠀⠀⠈⠀⠀⠀⠀          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠶⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠘⢦⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                    " << std::endl;
	file << "                              ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠛⠓⠒⠒⠒⠒⠒⠶⣤⣀⠀⠀⢶⣤⣀⣀⣀⣉⣙⣲⣦⠀⠀⠀⠀⠀⠀⠀⠀                    " << std::endl;
	file << "                              ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠒⠾⡇⠀⠈⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀                    " << std::endl;
	file << "                              ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⣢⠂⠀⠀⠀⠀⠀⠀⠀⠀                           " << std::endl;
	file.flush();
	file.close();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
	os << "📑🌳" << form.getName()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute()
		<< ", is signed: " << form.getSigned()
		<< ", has target: " << form.getTarget() << std::endl;
	return (os);
}

