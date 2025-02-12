#ifndef  CONTACT_HPP
# define CONTACT_HPP

#include <string>
class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkestSecret;
		int			_index;
	
	public:
		Contact();
		~Contact();
		void	display(int index);
};

#endif // CONTACT_HPP
