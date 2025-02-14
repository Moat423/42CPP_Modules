#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
	private:
		Contact				_contacts[8];
		std::string			_getInput(std::string const) const;
		static int const	_WIDTH = 10;
		std::string	_formatString(std::string str) const;
		void	_printBook() const;
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact() const;
};

#endif // PHONEBOOK_HPP
