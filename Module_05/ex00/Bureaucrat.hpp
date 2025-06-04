#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>

class Bureaucrat
{
	// constructors and desctuctors
	Bureaucrat( void );

	// exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			/*Exception(const std::string& msg) : _msg(msg){}*/
			/**/
			/*virtual const char* what() const noexcept override*/
			/*{*/
			/*	return _msg.c_str();*/
			/*}*/
	};
};

#endif // !BUREAUCRAT_HPP
