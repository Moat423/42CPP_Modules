#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
#include <string>

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm& operator=( const RobotomyRequestForm &assign );

		std::string getTarget( void ) const;

		void		execute(Bureaucrat const &executor) const;
	private:
		const std::string	_name;
		const size_t		_gradeToSign;
		const size_t		_gradeToExecute;
		bool				_signed;
		const std::string	_target;

		class BoolGenerator {
			mutable unsigned int state;
		public:
			explicit BoolGenerator(unsigned int seed) : state(seed ? seed : 1) {}
			bool next() {
				// XORshift32 algorithm (George Marsaglia)
				state ^= state << 13;
				state ^= state >> 17;
				state ^= state << 5;
				return state & 1;  // Extract least significant bit
			}
		};

		mutable BoolGenerator _boolGen;
		RobotomyRequestForm::BoolGenerator getBoolGen( void ) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);

#endif // !ROBOTOMYREQUESTFORM_HPP
