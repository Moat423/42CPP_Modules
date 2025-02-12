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
	public:
		Contact();
		~Contact();
		void		set(std::string firstName, std::string lastName, std::string nickname, std::string phonenumber, std::string darkestSecret);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhonenumber();
		std::string	getDarkestSecret();
		void		display(int index);
};

#endif // CONTACT_HPP
